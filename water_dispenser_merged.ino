// =====================================================================
//  Automated Water Dispenser — MERGED FINAL
//  Board  : Arduino Nano
//  Display: SSD1306 OLED 0.96" 128x64 via I2C (SDA=A4, SCL=A5)
//
//  Best of both versions:
//    [+] Interrupt-driven encoder (faster, no missed ticks)
//    [+] NeoPixel feedback per slot (green/blue/red/orange)
//    [+] Glass-removed safety abort mid-serve
//    [+] Drink counter + total mL stats screen
//    [+] Idle timeout auto power-off (5 min)
//    [+] Rich OLED UI with dedicated screens
//    [+] OLED refresh throttled (no flicker)
//    [+] Encoder KEY button toggles stats screen
//    [+] volatile keyword on ISR shared variables (bug fix)
//
//  Controls:
//    Button 1  short press  — system on/off
//    Button 2  short press  — manual serve (Mode A)
//    Button 2  long press   — toggle Mode A (manual) / Mode B (auto)
//    Encoder   turn         — adjust target volume (10–99 mL)
//    Encoder   key press    — toggle stats screen
//
//  Wiring:
//    OLED  SDA → A4  |  SCL → A5   (I2C — do NOT reassign)
//    BTN1        → D4
//    BTN2        → D5
//    ENC_A (CLK) → D2  ← interrupt pin
//    ENC_B (DT)  → D3  ← interrupt pin
//    ENC_KEY     → D8
//    SERVO       → D9
//    L298N IN1   → D10
//    L298N IN2   → D11
//    NEOPIXEL    → D12
//    LIMIT SW 1–5 → A0–A4  (other leg → GND)
//
//  Libraries (install via Library Manager):
//    - Adafruit SSD1306
//    - Adafruit GFX
//    - Adafruit NeoPixel
//    - Servo (built-in)
// =====================================================================

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>
#include <Adafruit_NeoPixel.h>

// ── OLED ──────────────────────────────────────────────────────────────
#define SCREEN_W     128
#define SCREEN_H      64
#define OLED_RESET    -1
#define OLED_ADDR    0x3C   // try 0x3D if screen stays blank
Adafruit_SSD1306 oled(SCREEN_W, SCREEN_H, &Wire, OLED_RESET);

// ── PIN DEFINITIONS ───────────────────────────────────────────────────
#define BUTTON1_PIN   4
#define BUTTON2_PIN   5
#define ENC_A         2     // interrupt pin — CLK on KY-040
#define ENC_B         3     // interrupt pin — DT  on KY-040
#define ENC_KEY       8     // SW on KY-040
#define SERVO_PIN     9
#define MOTOR_IN1    10
#define MOTOR_IN2    11
#define LED_PIN      12

// ── CONSTANTS ─────────────────────────────────────────────────────────
#define NUM_LEDS            5
#define NUM_SWITCHES        5

#define VOLUME_MIN         10     // mL
#define VOLUME_MAX         99     // mL

// Calibrate: measure how many mL your pump delivers in 1 second
#define ML_PER_SECOND       8.0f

#define SERVO_DELAY_MS    600
#define BTN_DEBOUNCE_MS    50
#define LONG_PRESS_MS    1000
#define OLED_REFRESH_MS   100

// Set to 0 to disable idle timeout
#define IDLE_TIMEOUT_MS  300000UL  // 5 minutes

// ── NEOPIXEL COLOURS ──────────────────────────────────────────────────
#define COLOR_OFF      strip.Color(0,   0,   0)
#define COLOR_READY    strip.Color(0,   220, 0)    // green  — glass present
#define COLOR_SERVING  strip.Color(0,   80,  255)  // blue   — dispensing
#define COLOR_FULL     strip.Color(220, 0,   0)    // red    — done
#define COLOR_WARNING  strip.Color(255, 80,  0)    // orange — glass removed

// ── OBJECTS ───────────────────────────────────────────────────────────
Servo             servo;
Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// ── HARDWARE TABLES ───────────────────────────────────────────────────
const int limitSwitches[NUM_SWITCHES] = { A0, A1, A2, A3, A4 };
const int angles[NUM_SWITCHES]        = { 30, 60, 93, 130, 180 };

// ── ENCODER STATE (volatile — shared with ISR) ────────────────────────
volatile int  encDelta    = 0;   // +1 or -1 per detent
volatile bool encALast    = HIGH;

// ── SYSTEM STATE ──────────────────────────────────────────────────────
int  selectedVolume = 10;
bool systemOn       = false;
bool modeA          = true;
bool pendingServe   = false;

bool glassFull[NUM_SWITCHES]    = {};
bool glassPresent[NUM_SWITCHES] = {};

// ── DRINK STATS ───────────────────────────────────────────────────────
int           drinkCount    = 0;
unsigned long totalMlServed = 0;
bool          showingStats  = false;

// ── IDLE TIMEOUT ──────────────────────────────────────────────────────
unsigned long lastActivityTime = 0;

// ── BUTTON 1 ──────────────────────────────────────────────────────────
bool          btn1Last = HIGH;
unsigned long btn1Time = 0;

// ── BUTTON 2 ──────────────────────────────────────────────────────────
bool          btn2Last         = HIGH;
unsigned long btn2PressStart   = 0;
bool          longPressHandled = false;

// ── ENCODER KEY ───────────────────────────────────────────────────────
bool encKeyLast = HIGH;

// ── OLED REFRESH THROTTLE ─────────────────────────────────────────────
unsigned long lastOledUpdate = 0;


// =====================================================================
//  ENCODER ISR
//  Called on every CHANGE of ENC_A (pin D2).
//  Reads ENC_B to determine direction.
//  encDelta is consumed in the main loop — safe because Nano is 8-bit
//  and int reads are not atomic, but we only increment/decrement by 1
//  and constrain in the main loop, so worst case is a skipped tick.
// =====================================================================
void encoderISR() {
  bool a = digitalRead(ENC_A);
  bool b = digitalRead(ENC_B);

  if (a != encALast) {
    // CW when A leads B, CCW when B leads A
    encDelta += (b != a) ? +1 : -1;
    encALast = a;
  }
}


// =====================================================================
//  SETUP
// =====================================================================
void setup() {
  Serial.begin(9600);

  // Digital inputs
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(ENC_A,       INPUT_PULLUP);
  pinMode(ENC_B,       INPUT_PULLUP);
  pinMode(ENC_KEY,     INPUT_PULLUP);

  // Motor outputs
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  stopPump();

  // Servo
  servo.attach(SERVO_PIN);
  servo.write(0);

  // Limit switches
  for (int i = 0; i < NUM_SWITCHES; i++) {
    pinMode(limitSwitches[i], INPUT_PULLUP);
  }

  // NeoPixel
  strip.begin();
  strip.clear();
  strip.show();

  // Encoder interrupt — fire on both edges for full resolution
  attachInterrupt(digitalPinToInterrupt(ENC_A), encoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_B), encoderISR, CHANGE);

  // OLED
  if (!oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("OLED not found! Check wiring or try 0x3D"));
    while (true);
  }

  bootAnimation();
  lastActivityTime = millis();
}


// =====================================================================
//  MAIN LOOP
// =====================================================================
void loop() {
  handleSystemToggle();

  if (!systemOn) return;

  handleEncoder();
  handleEncoderKey();
  handleButton2();
  checkGlasses();
  checkIdleTimeout();

  if (!modeA && pendingServe) {
    pendingServe = false;
    serveWater();
  }

  // Throttle OLED updates to avoid flicker
  if (millis() - lastOledUpdate >= OLED_REFRESH_MS) {
    lastOledUpdate = millis();
    showingStats ? oledShowStats() : oledShowMain();
  }
}


// =====================================================================
//  BOOT ANIMATION
// =====================================================================
void bootAnimation() {
  // NeoPixel blue sweep
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(0, 80, 200));
    strip.show();
    delay(80);
  }
  strip.clear();
  strip.show();

  // OLED splash screen
  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);
  oled.drawRect(0, 0, 128, 64, SSD1306_WHITE);
  oled.setTextSize(1);
  oled.setCursor(18, 10);
  oled.print(F("WATER DISPENSER"));
  oled.drawLine(0, 22, 127, 22, SSD1306_WHITE);
  oled.setCursor(28, 30);
  oled.print(F("Arduino Nano"));
  oled.setCursor(22, 44);
  oled.print(F("Press BTN1 to ON"));
  oled.display();
  delay(1500);
  oled.clearDisplay();
  oled.display();
}


// =====================================================================
//  ACTIVITY TRACKER — call on any user interaction
// =====================================================================
void recordActivity() {
  lastActivityTime = millis();
}


// =====================================================================
//  IDLE TIMEOUT
// =====================================================================
void checkIdleTimeout() {
#if IDLE_TIMEOUT_MS > 0
  if (millis() - lastActivityTime >= IDLE_TIMEOUT_MS) {
    Serial.println(F("Idle timeout — shutting down."));
    systemOn = false;
    stopPump();
    servo.write(0);
    strip.clear();
    strip.show();
    for (int i = 0; i < NUM_SWITCHES; i++) {
      glassFull[i] = glassPresent[i] = false;
    }
    showingStats = false;

    oled.clearDisplay();
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(1);
    oled.setCursor(22, 22);
    oled.print(F("System idle OFF"));
    oled.setCursor(16, 38);
    oled.print(F("Press BTN1 to ON"));
    oled.display();
  }
#endif
}


// =====================================================================
//  SYSTEM TOGGLE — Button 1 short press
// =====================================================================
void handleSystemToggle() {
  bool current = digitalRead(BUTTON1_PIN);
  if (current != btn1Last) btn1Time = millis();

  if (millis() - btn1Time > BTN_DEBOUNCE_MS) {
    static bool confirmed = HIGH;
    if (current != confirmed) {
      confirmed = current;
      if (confirmed == LOW) {
        systemOn = !systemOn;
        recordActivity();

        if (!systemOn) {
          stopPump();
          servo.write(0);
          strip.clear();
          strip.show();
          for (int i = 0; i < NUM_SWITCHES; i++) {
            glassFull[i] = glassPresent[i] = false;
          }
          showingStats = false;
          oledShowOff();
          Serial.println(F("System OFF"));
        } else {
          Serial.println(F("System ON"));
        }
      }
    }
  }
  btn1Last = current;
}


// =====================================================================
//  ENCODER — consume ISR delta, update volume
// =====================================================================
void handleEncoder() {
  // Atomically grab and clear the delta
  noInterrupts();
  int delta = encDelta;
  encDelta  = 0;
  interrupts();

  if (delta != 0) {
    selectedVolume = constrain(
      selectedVolume + (delta > 0 ? 1 : -1),
      VOLUME_MIN, VOLUME_MAX
    );
    showingStats = false;   // snap back to main on turn
    recordActivity();
    Serial.print(F("Volume: "));
    Serial.println(selectedVolume);
  }
}


// =====================================================================
//  ENCODER KEY — toggle stats / main screen
// =====================================================================
void handleEncoderKey() {
  bool current = digitalRead(ENC_KEY);
  if (encKeyLast == LOW && current == HIGH) {
    showingStats = !showingStats;
    recordActivity();
    Serial.println(showingStats ? F("Stats screen") : F("Main screen"));
  }
  encKeyLast = current;
}


// =====================================================================
//  BUTTON 2 — short press: serve | long press: toggle mode
// =====================================================================
void handleButton2() {
  bool current = digitalRead(BUTTON2_PIN);

  if (btn2Last == HIGH && current == LOW) {
    btn2PressStart   = millis();
    longPressHandled = false;
    recordActivity();
  }

  if (current == LOW && !longPressHandled) {
    if (millis() - btn2PressStart >= LONG_PRESS_MS) {
      modeA            = !modeA;
      longPressHandled = true;
      showingStats     = false;
      Serial.println(modeA ? F("Mode: Manual") : F("Mode: Auto"));
      oledFlashMode();
    }
  }

  if (btn2Last == LOW && current == HIGH) {
    if (!longPressHandled && modeA) {
      serveWater();
    }
  }

  btn2Last = current;
}


// =====================================================================
//  CHECK GLASSES — poll limit switches, update NeoPixels
// =====================================================================
void checkGlasses() {
  for (int i = 0; i < NUM_SWITCHES; i++) {
    bool detected = (digitalRead(limitSwitches[i]) == LOW);

    if (!detected) {
      if (glassPresent[i]) {
        glassPresent[i] = false;
        glassFull[i]    = false;
        strip.setPixelColor(i, COLOR_OFF);
        Serial.print(F("Glass removed: slot ")); Serial.println(i + 1);
      }
    } else {
      if (!glassPresent[i]) {
        glassPresent[i] = true;
        recordActivity();
        if (!glassFull[i]) {
          strip.setPixelColor(i, COLOR_READY);
          if (!modeA) pendingServe = true;
          Serial.print(F("Glass detected: slot ")); Serial.println(i + 1);
        }
      }
    }
  }
  strip.show();
}


// =====================================================================
//  SERVE WATER — iterate all slots
// =====================================================================
void serveWater() {
  for (int i = 0; i < NUM_SWITCHES; i++) {
    if (glassPresent[i] && !glassFull[i]) {
      rotateAndServe(i);
      glassFull[i] = true;
    }
  }
}


// =====================================================================
//  ROTATE AND DISPENSE — core serving routine
// =====================================================================
void rotateAndServe(int index) {
  Serial.print(F("Serving slot ")); Serial.print(index + 1);
  Serial.print(F(" — target: ")); Serial.print(selectedVolume);
  Serial.println(F(" mL"));

  // 1. Move spout to correct position
  servo.write(angles[index]);
  delay(SERVO_DELAY_MS);

  // 2. Blue LED — dispensing
  strip.setPixelColor(index, COLOR_SERVING);
  strip.show();

  // 3. Start pump
  startPump();

  unsigned long duration  = (unsigned long)((selectedVolume / ML_PER_SECOND) * 1000.0f);
  unsigned long startTime = millis();
  bool aborted = false;

  // 4. Dispensing loop — live OLED update + safety check
  while (millis() - startTime < duration) {
    // Safety: abort if glass removed mid-serve
    if (digitalRead(limitSwitches[index]) == HIGH) {
      aborted = true;
      Serial.println(F("WARN: Glass removed mid-serve!"));
      break;
    }

    unsigned long elapsed = millis() - startTime;
    int dispensed = constrain(
      (int)((elapsed / 1000.0f) * ML_PER_SECOND),
      0, selectedVolume
    );
    oledShowServing(index, dispensed, selectedVolume);
    delay(50);
  }

  // 5. Stop pump
  stopPump();

  // 6. Update drink stats on successful serve
  if (!aborted) {
    drinkCount++;
    totalMlServed += selectedVolume;
    oledShowServing(index, selectedVolume, selectedVolume); // show 100%
    delay(400);
    Serial.print(F("Drinks: ")); Serial.print(drinkCount);
    Serial.print(F("  Total: ")); Serial.print(totalMlServed); Serial.println(F(" mL"));
  }

  // 7. Return servo to home
  servo.write(0);
  delay(SERVO_DELAY_MS);

  // 8. LED feedback — red (done) or orange (aborted)
  strip.setPixelColor(index, aborted ? COLOR_WARNING : COLOR_FULL);
  strip.show();

  if (aborted) {
    glassFull[index] = false;
    oledShowWarning(index);
  }

  recordActivity();
  Serial.println(aborted ? F("Serve aborted.") : F("Serve complete."));
}


// =====================================================================
//  OLED SCREENS
// =====================================================================

// ── Main screen ────────────────────────────────────────────────────────
void oledShowMain() {
  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);

  // Mode badge (filled rect, inverted text)
  oled.fillRoundRect(0, 0, 42, 14, 3, SSD1306_WHITE);
  oled.setTextColor(SSD1306_BLACK);
  oled.setTextSize(1);
  oled.setCursor(3, 3);
  oled.print(modeA ? F("MANUAL") : F(" AUTO "));
  oled.setTextColor(SSD1306_WHITE);

  // Glass slot circles (top right, 5 slots)
  for (int i = 0; i < NUM_SWITCHES; i++) {
    int x = 58 + i * 14;
    if (glassPresent[i]) {
      glassFull[i]
        ? oled.fillCircle(x, 7, 4, SSD1306_WHITE)
        : oled.drawCircle(x, 7, 4, SSD1306_WHITE);
    } else {
      // Empty dot
      oled.drawCircle(x, 7, 4, SSD1306_WHITE);
      oled.drawPixel(x, 7, SSD1306_BLACK);
    }
  }

  // Divider
  oled.drawLine(0, 16, 127, 16, SSD1306_WHITE);

  // Big volume number
  oled.setTextSize(4);
  oled.setCursor(selectedVolume >= 100 ? 14 : 26, 22);
  oled.print(selectedVolume);
  oled.setTextSize(1);
  oled.setCursor(96, 30);
  oled.print(F("mL"));

  // Bottom hint bar
  oled.drawLine(0, 54, 127, 54, SSD1306_WHITE);
  oled.setCursor(2, 57);
  oled.print(F("ENC:vol  KEY:stats"));

  oled.display();
}

// ── Stats screen ──────────────────────────────────────────────────────
void oledShowStats() {
  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);

  // Inverted title bar
  oled.fillRect(0, 0, 128, 14, SSD1306_WHITE);
  oled.setTextColor(SSD1306_BLACK);
  oled.setTextSize(1);
  oled.setCursor(28, 3);
  oled.print(F("SESSION STATS"));
  oled.setTextColor(SSD1306_WHITE);

  // Drink count
  oled.setTextSize(1);
  oled.setCursor(2, 20);
  oled.print(F("Drinks:"));
  oled.setTextSize(2);
  oled.setCursor(2, 30);
  oled.print(drinkCount);

  // Total mL (compact: show "1.2L" above 999)
  oled.setTextSize(1);
  oled.setCursor(68, 20);
  oled.print(F("Total mL:"));
  oled.setTextSize(2);
  oled.setCursor(68, 30);
  if (totalMlServed >= 1000) {
    oled.print(totalMlServed / 1000.0f, 1);
    oled.setTextSize(1);
    oled.print(F("L"));
  } else {
    oled.print(totalMlServed);
  }

  // Bottom hint
  oled.drawLine(0, 54, 127, 54, SSD1306_WHITE);
  oled.setTextSize(1);
  oled.setCursor(22, 57);
  oled.print(F("KEY: back to main"));

  oled.display();
}

// ── Serving screen (live progress) ────────────────────────────────────
void oledShowServing(int slot, int dispensed, int target) {
  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);

  oled.setTextSize(1);
  oled.setCursor(18, 2);
  oled.print(F("SERVING SLOT "));
  oled.print(slot + 1);
  oled.drawLine(0, 12, 127, 12, SSD1306_WHITE);

  // Large dispensed number
  oled.setTextSize(4);
  oled.setCursor(dispensed >= 100 ? 10 : 22, 18);
  oled.print(dispensed);

  // Target label
  oled.setTextSize(1);
  oled.setCursor(96, 24);
  oled.print(F("/"));
  oled.setCursor(96, 34);
  oled.print(target);
  oled.setCursor(96, 44);
  oled.print(F("mL"));

  // Progress bar
  oled.drawRect(0, 54, 128, 10, SSD1306_WHITE);
  int barW = map(dispensed, 0, target, 0, 124);
  oled.fillRect(2, 56, max(barW, 0), 6, SSD1306_WHITE);

  oled.display();
}

// ── System off screen ─────────────────────────────────────────────────
void oledShowOff() {
  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);
  oled.drawRect(0, 0, 128, 64, SSD1306_WHITE);
  oled.setTextSize(2);
  oled.setCursor(30, 16);
  oled.print(F("SYSTEM"));
  oled.setCursor(46, 36);
  oled.print(F("OFF"));
  oled.display();
}

// ── Mode toggle flash ─────────────────────────────────────────────────
void oledFlashMode() {
  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(2);
  oled.setCursor(10, 14);
  oled.print(F("MODE:"));
  oled.setCursor(10, 36);
  oled.print(modeA ? F("MANUAL") : F("AUTO  "));
  oled.display();
  delay(600);
}

// ── Warning screen (glass removed mid-serve) ──────────────────────────
void oledShowWarning(int slot) {
  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.setCursor(28, 8);
  oled.print(F("!! WARNING !!"));
  oled.drawLine(0, 18, 127, 18, SSD1306_WHITE);
  oled.setCursor(10, 26);
  oled.print(F("Glass removed!"));
  oled.setCursor(10, 38);
  oled.print(F("Slot: "));
  oled.print(slot + 1);
  oled.setCursor(10, 50);
  oled.print(F("Serve aborted."));
  oled.display();
  delay(1500);
}


// =====================================================================
//  PUMP HELPERS
// =====================================================================
void startPump() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
}

void stopPump() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
}
