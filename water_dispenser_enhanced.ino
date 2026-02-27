// =====================================================================
//  Automated Water Dispenser — Enhanced
// =====================================================================

#include <TM1637Display.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>

// ---------------- PIN DEFINITIONS ----------------
#define CLK             2
#define DIO             3
#define BUTTON1_PIN     4
#define BUTTON2_PIN     5
#define ENCODER_S1      6
#define ENCODER_S2      7
#define ENCODER_KEY     8
#define SERVO_PIN       9
#define MOTOR_IN1       10
#define MOTOR_IN2       11
#define LED_PIN         12

// ---------------- CONSTANTS ----------------
#define NUM_LEDS            5
#define NUM_LIMIT_SWITCHES  5

#define VOLUME_MIN          10      // mL
#define VOLUME_MAX          99      // mL
#define VOLUME_STEP         1       // mL per encoder click

// Calibrate this to your pump: mL dispensed per second at full speed
#define ML_PER_SECOND       8.0f

#define SERVO_DELAY_MS      600     // ms to wait after servo moves
#define DEBOUNCE_MS         5       // encoder debounce window
#define LONG_PRESS_MS       1000    // ms to hold Button2 for mode toggle
#define BTN_DEBOUNCE_MS     50      // button debounce

// ---------------- COLOURS ----------------
#define COLOR_OFF       strip.Color(0,   0,   0)
#define COLOR_READY     strip.Color(0,   255, 0)    // glass present, not served
#define COLOR_SERVING   strip.Color(0,   0,   255)  // dispensing
#define COLOR_FULL      strip.Color(255, 0,   0)    // served / full
#define COLOR_WARNING   strip.Color(255, 80,  0)    // glass removed mid-serve

// ---------------- OBJECTS ----------------
Servo              servo;
TM1637Display      display(CLK, DIO);
Adafruit_NeoPixel  strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// ---------------- HARDWARE TABLES ----------------
const int limitSwitches[NUM_LIMIT_SWITCHES] = { A0, A1, A2, A3, A4 };
const int angles[NUM_LIMIT_SWITCHES]        = { 30, 60, 93, 130, 180 };

// ---------------- STATE ----------------
int  selectedVolume = 10;
bool glassFull[NUM_LIMIT_SWITCHES]   = { false };
bool glassPresent[NUM_LIMIT_SWITCHES]= { false };
bool systemOn   = false;
bool modeA      = true;       // true = Manual (A), false = Auto (B)

// Encoder
int  lastS1State      = HIGH;
unsigned long lastEncTime = 0;

// Button 1 (system toggle)
bool     btn1Last   = HIGH;
unsigned long btn1Time = 0;

// Button 2 (serve / mode toggle)
bool     btn2Last          = HIGH;
unsigned long btn2PressStart   = 0;
bool     longPressHandled  = false;

// Auto-mode: flag a serve is needed without calling from loop directly
bool pendingServe = false;

// =====================================================================

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON1_PIN,  INPUT_PULLUP);
  pinMode(BUTTON2_PIN,  INPUT_PULLUP);
  pinMode(ENCODER_S1,   INPUT_PULLUP);
  pinMode(ENCODER_S2,   INPUT_PULLUP);
  pinMode(ENCODER_KEY,  INPUT_PULLUP);

  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  stopPump();

  servo.attach(SERVO_PIN);
  servo.write(0);

  for (int i = 0; i < NUM_LIMIT_SWITCHES; i++) {
    pinMode(limitSwitches[i], INPUT_PULLUP);
  }

  strip.begin();
  strip.show();

  display.setBrightness(0x0f);

  bootAnimation();
}

// =====================================================================
//  MAIN LOOP
// =====================================================================

void loop() {
  handleSystemToggle();

  if (!systemOn) return;

  handleEncoder();
  handleButton2();
  checkGlasses();

  if (!modeA && pendingServe) {
    pendingServe = false;
    serveWater();
  }

  updateDisplay();
}

// =====================================================================
//  BOOT ANIMATION
// =====================================================================

void bootAnimation() {
  // Quick rainbow sweep so user knows it's alive
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(0, 100, 200));
    strip.show();
    delay(80);
  }
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, COLOR_OFF);
  }
  strip.show();

  // Flash dashes on display
  uint8_t dashes[4] = { 0x40, 0x40, 0x40, 0x40 };
  display.setSegments(dashes);
  delay(400);
  display.clear();
}

// =====================================================================
//  SYSTEM TOGGLE (Button 1)
// =====================================================================

void handleSystemToggle() {
  bool current = digitalRead(BUTTON1_PIN);

  // Debounce
  if (current != btn1Last) {
    btn1Time = millis();
  }

  if ((millis() - btn1Time) > BTN_DEBOUNCE_MS) {
    static bool confirmed = HIGH;
    if (current != confirmed) {
      confirmed = current;
      if (confirmed == LOW) {          // falling edge = press
        systemOn = !systemOn;

        if (!systemOn) {
          stopPump();
          servo.write(0);
          display.clear();
          for (int i = 0; i < NUM_LEDS; i++) {
            glassFull[i]    = false;
            glassPresent[i] = false;
          }
          strip.clear();
          strip.show();
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
//  ROTARY ENCODER
// =====================================================================

void handleEncoder() {
  int s1 = digitalRead(ENCODER_S1);

  if (s1 != lastS1State && s1 == LOW) {
    // Simple debounce: ignore if too soon after last event
    if (millis() - lastEncTime > DEBOUNCE_MS) {
      lastEncTime = millis();
      if (digitalRead(ENCODER_S2) == LOW)
        selectedVolume += VOLUME_STEP;
      else
        selectedVolume -= VOLUME_STEP;

      selectedVolume = constrain(selectedVolume, VOLUME_MIN, VOLUME_MAX);
      Serial.print(F("Volume: "));
      Serial.println(selectedVolume);
    }
  }

  lastS1State = s1;
}

// =====================================================================
//  BUTTON 2 — Short press: manual serve | Long press: toggle mode
// =====================================================================

void handleButton2() {
  bool current = digitalRead(BUTTON2_PIN);

  // Press start
  if (btn2Last == HIGH && current == LOW) {
    btn2PressStart   = millis();
    longPressHandled = false;
  }

  // Held down — check for long press
  if (current == LOW && !longPressHandled) {
    if (millis() - btn2PressStart >= LONG_PRESS_MS) {
      modeA = !modeA;
      longPressHandled = true;
      Serial.print(F("Mode: "));
      Serial.println(modeA ? F("Manual (A)") : F("Auto (B)"));
      // Brief display flash to confirm mode change
      display.clear();
      delay(200);
    }
  }

  // Release — short press triggers manual serve in Mode A
  if (btn2Last == LOW && current == HIGH) {
    if (!longPressHandled && modeA) {
      serveWater();
    }
  }

  btn2Last = current;
}

// =====================================================================
//  UPDATE DISPLAY   [A/B]  [volume]
// =====================================================================

void updateDisplay() {
  uint8_t data[4];
  data[0] = modeA ? 0x77 : 0x7C;   // 'A' or 'b'
  data[1] = 0x00;
  data[2] = display.encodeDigit(selectedVolume / 10);
  data[3] = display.encodeDigit(selectedVolume % 10);
  display.setSegments(data);
}

// =====================================================================
//  CHECK GLASSES — update LED state, trigger auto mode
// =====================================================================

void checkGlasses() {
  for (int i = 0; i < NUM_LIMIT_SWITCHES; i++) {
    bool detected = (digitalRead(limitSwitches[i]) == LOW);

    if (!detected) {
      // Glass removed
      if (glassPresent[i]) {
        glassFull[i]    = false;
        glassPresent[i] = false;
        strip.setPixelColor(i, COLOR_OFF);
        Serial.print(F("Glass removed: slot "));
        Serial.println(i);
      }
    } else {
      // Glass present
      if (!glassPresent[i]) {
        // Newly placed glass
        glassPresent[i] = true;
        if (!glassFull[i]) {
          strip.setPixelColor(i, COLOR_READY);
          if (!modeA) {
            pendingServe = true;   // signal auto serve
          }
          Serial.print(F("Glass detected: slot "));
          Serial.println(i);
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
  for (int i = 0; i < NUM_LIMIT_SWITCHES; i++) {
    if (glassPresent[i] && !glassFull[i]) {
      rotateAndServe(i);
      glassFull[i] = true;
    }
  }
}

// =====================================================================
//  ROTATE SERVO AND DISPENSE
// =====================================================================

void rotateAndServe(int index) {
  Serial.print(F("Serving slot "));
  Serial.print(index);
  Serial.print(F("  volume: "));
  Serial.println(selectedVolume);

  // --- Move spout to glass ---
  servo.write(angles[index]);
  delay(SERVO_DELAY_MS);

  // --- LED: serving (blue) ---
  strip.setPixelColor(index, COLOR_SERVING);
  strip.show();

  // --- Start pump ---
  startPump();

  // --- Dispense for calibrated duration ---
  unsigned long serveDuration = (unsigned long)((selectedVolume / ML_PER_SECOND) * 1000.0f);
  unsigned long startTime     = millis();
  unsigned long elapsed       = 0;
  bool aborted = false;

  while (elapsed < serveDuration) {
    elapsed = millis() - startTime;

    // Safety: abort if glass is removed mid-serve
    if (digitalRead(limitSwitches[index]) == HIGH) {
      aborted = true;
      Serial.println(F("WARN: Glass removed during serve!"));
      break;
    }

    // Live display: show mL dispensed so far
    int dispensed = constrain(
      (int)((elapsed / 1000.0f) * ML_PER_SECOND),
      0,
      selectedVolume
    );

    uint8_t data[4];
    data[0] = modeA ? 0x77 : 0x7C;
    data[1] = 0x00;
    data[2] = display.encodeDigit(dispensed / 10);
    data[3] = display.encodeDigit(dispensed % 10);
    display.setSegments(data);

    delay(50);   // refresh rate ~20 fps
  }

  // --- Stop pump ---
  stopPump();

  // --- Return servo to home ---
  servo.write(0);
  delay(SERVO_DELAY_MS);

  // --- LED final state ---
  if (aborted) {
    strip.setPixelColor(index, COLOR_WARNING);   // orange = glass removed
    glassFull[index] = false;                    // allow retry
  } else {
    strip.setPixelColor(index, COLOR_FULL);      // red = full
  }
  strip.show();

  Serial.println(aborted ? F("Serve aborted.") : F("Serve complete."));
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
