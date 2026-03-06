<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Water Dispenser — Nano + OLED Wiring</title>
<style>
  @import url('https://fonts.googleapis.com/css2?family=JetBrains+Mono:wght@400;600&family=Orbitron:wght@600;900&display=swap');
  *{margin:0;padding:0;box-sizing:border-box;}
  body{background:#16213e;font-family:'JetBrains Mono',monospace;color:#e2e8f0;min-height:100vh;user-select:none;}
  header{background:linear-gradient(135deg,#0f0f23,#1a1a3e);border-bottom:2px solid #2d3561;padding:12px 20px;display:flex;align-items:center;justify-content:space-between;}
  header h1{font-family:'Orbitron',sans-serif;font-size:1rem;color:#60a5fa;letter-spacing:3px;text-shadow:0 0 20px rgba(96,165,250,.5);}
  .hint{font-size:.6rem;color:#475569;letter-spacing:1px;}
  .badge{background:rgba(96,165,250,.1);border:1px solid rgba(96,165,250,.3);border-radius:20px;padding:4px 12px;font-size:.6rem;color:#93c5fd;letter-spacing:2px;}
  .wrap{display:grid;grid-template-columns:1fr 230px;height:calc(100vh - 52px);}
  .board{overflow:auto;background-image:linear-gradient(rgba(255,255,255,.018) 1px,transparent 1px),linear-gradient(90deg,rgba(255,255,255,.018) 1px,transparent 1px);background-size:24px 24px;background-color:#0f1729;padding:16px;position:relative;}
  .wire{cursor:pointer;}
  .wire path,.wire line,.wire polyline{pointer-events:stroke;stroke-linecap:round;stroke-linejoin:round;}
  .wire.active path,.wire.active line,.wire.active polyline{stroke-width:4.5!important;filter:drop-shadow(0 0 5px currentColor) drop-shadow(0 0 10px currentColor);}
  .wire.faded{opacity:.1;}
  .pin-node{cursor:pointer;}
  .pin-node.active{animation:pulse 1s infinite;}
  @keyframes pulse{0%,100%{opacity:1}50%{opacity:.4}}
  #tip{position:fixed;pointer-events:none;background:#0d1117;border:1px solid #30363d;border-radius:8px;padding:8px 12px;font-size:.68rem;color:#e2e8f0;line-height:1.7;box-shadow:0 8px 32px rgba(0,0,0,.7);max-width:220px;z-index:999;display:none;}
  #tip .tf{color:#94a3b8;font-size:.6rem;}
  #tip .tl{font-weight:600;color:#fff;}
  #tip .tp{color:#60a5fa;font-size:.6rem;}
  .sidebar{background:#0a0d14;border-left:1px solid #1e2535;overflow-y:auto;padding:14px;display:flex;flex-direction:column;gap:5px;}
  .s-title{font-family:'Orbitron',sans-serif;font-size:.58rem;letter-spacing:2px;color:#60a5fa;border-bottom:1px solid #1e2535;padding-bottom:5px;margin-bottom:4px;}
  .conn-row{display:grid;grid-template-columns:10px 1fr auto;align-items:center;gap:6px;padding:4px 5px;border-radius:4px;cursor:pointer;font-size:.6rem;border:1px solid transparent;transition:background .1s,border-color .1s;}
  .conn-row:hover{background:rgba(255,255,255,.04);}
  .conn-row.active{background:rgba(96,165,250,.08);border-color:rgba(96,165,250,.25);}
  .conn-dot{width:9px;height:9px;border-radius:50%;}
  .conn-from{color:#94a3b8;}
  .conn-to{color:#475569;font-size:.56rem;}
  .s-gap{height:6px;border-top:1px solid #1e2535;margin-top:2px;}
  .note{border-radius:6px;padding:9px;font-size:.58rem;line-height:1.8;margin-top:4px;}
  .note.warn{background:rgba(239,68,68,.07);border:1px solid rgba(239,68,68,.2);color:#fca5a5;}
  .note.info{background:rgba(96,165,250,.05);border:1px solid rgba(96,165,250,.15);color:#93c5fd;}
  .note b{display:block;margin-bottom:2px;}
  .note.warn b{color:#ef4444;}
  .note.info b{color:#60a5fa;}
  svg{display:block;}
</style>
</head>
<body>
<header>
  <h1>INTERACTIVE WIRING — NANO + OLED</h1>
  <span class="hint">CLICK ANY WIRE OR PIN TO HIGHLIGHT</span>
  <div class="badge">ARDUINO NANO + SSD1306</div>
</header>
<div id="tip"></div>
<div class="wrap">
<div class="board">
<svg id="svg" viewBox="0 0 1020 820" xmlns="http://www.w3.org/2000/svg" style="min-width:880px;width:100%;height:auto">
<defs>
  <filter id="glow"><feGaussianBlur stdDeviation="1.5" result="b"/><feMerge><feMergeNode in="b"/><feMergeNode in="SourceGraphic"/></feMerge></filter>
  <filter id="shadow"><feDropShadow dx="1" dy="3" stdDeviation="5" flood-color="#000" flood-opacity=".6"/></filter>
  <filter id="pcb-sh"><feDropShadow dx="2" dy="4" stdDeviation="7" flood-color="#000" flood-opacity=".7"/></filter>
  <marker id="am-red"    markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#ef4444"/></marker>
  <marker id="am-gnd"    markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#78716c"/></marker>
  <marker id="am-purple" markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#a78bfa"/></marker>
  <marker id="am-violet" markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#c084fc"/></marker>
  <marker id="am-orange" markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#f97316"/></marker>
  <marker id="am-amber"  markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#fb923c"/></marker>
  <marker id="am-green"  markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#4ade80"/></marker>
  <marker id="am-lime"   markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#22c55e"/></marker>
  <marker id="am-mint"   markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#86efac"/></marker>
  <marker id="am-yellow" markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#facc15"/></marker>
  <marker id="am-sky"    markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#38bdf8"/></marker>
  <marker id="am-blue"   markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#7dd3fc"/></marker>
  <marker id="am-pink"   markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#f472b6"/></marker>
  <marker id="am-teal"   markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#34d399"/></marker>
  <marker id="am-cyan"   markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#22d3ee"/></marker>
  <marker id="am-indigo" markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto"><path d="M0,.5 L5,3 L0,5.5Z" fill="#818cf8"/></marker>
</defs>

<!-- ══ ARDUINO NANO ══ -->
<g filter="url(#pcb-sh)">
  <!-- Nano is narrower/longer than Uno -->
  <rect x="370" y="210" width="160" height="340" rx="6" fill="#1a4a8a"/>
  <rect x="375" y="215" width="150" height="330" rx="4" fill="#1e5799"/>
  <text x="450" y="234" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="8" fill="#93c5fd" letter-spacing="2" font-weight="700">ARDUINO</text>
  <text x="450" y="246" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="8" fill="#93c5fd" letter-spacing="2" font-weight="700">NANO</text>
  <!-- ATmega chip -->
  <rect x="405" y="310" width="90" height="60" rx="3" fill="#111"/>
  <text x="450" y="343" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="7" fill="#374151">ATmega328P</text>
  <g fill="#6b7280"><rect x="403" y="316" width="4" height="4" rx=".5"/><rect x="403" y="326" width="4" height="4" rx=".5"/><rect x="403" y="336" width="4" height="4" rx=".5"/><rect x="403" y="346" width="4" height="4" rx=".5"/><rect x="491" y="316" width="4" height="4" rx=".5"/><rect x="491" y="326" width="4" height="4" rx=".5"/><rect x="491" y="336" width="4" height="4" rx=".5"/><rect x="491" y="346" width="4" height="4" rx=".5"/></g>
  <!-- Mini USB -->
  <rect x="435" y="524" width="30" height="20" rx="3" fill="#2d3748" stroke="#4a5568" stroke-width="1"/>
  <text x="450" y="537" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="5.5" fill="#718096">USB</text>
  <!-- Voltage reg -->
  <rect x="390" y="280" width="22" height="14" rx="2" fill="#2d3748" stroke="#4a5568" stroke-width=".5"/>
  <text x="401" y="290" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="5" fill="#9ca3af">REG</text>

  <!-- RIGHT pin header — D2..D12 -->
  <rect x="526" y="258" width="8" height="244" rx="2" fill="#2d3748" stroke="#4a5568" stroke-width=".5"/>
  <circle id="p-D2"  cx="530" cy="268" r="4.5" fill="#2d3748" stroke="#a78bfa" stroke-width="2" class="pin-node" data-net="sda"/>
  <text x="522" y="272" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#cbd5e1">D2</text>
  <circle id="p-D3"  cx="530" cy="285" r="4.5" fill="#2d3748" stroke="#c084fc" stroke-width="2" class="pin-node" data-net="scl"/>
  <text x="522" y="289" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#cbd5e1">D3</text>
  <circle id="p-D4"  cx="530" cy="302" r="4.5" fill="#2d3748" stroke="#f97316" stroke-width="2" class="pin-node" data-net="btn1"/>
  <text x="522" y="306" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#cbd5e1">D4</text>
  <circle id="p-D5"  cx="530" cy="319" r="4.5" fill="#2d3748" stroke="#fb923c" stroke-width="2" class="pin-node" data-net="btn2"/>
  <text x="522" y="323" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#cbd5e1">D5</text>
  <circle id="p-D6"  cx="530" cy="336" r="4.5" fill="#2d3748" stroke="#4ade80" stroke-width="2" class="pin-node" data-net="s1"/>
  <text x="522" y="340" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#cbd5e1">D6</text>
  <circle id="p-D7"  cx="530" cy="353" r="4.5" fill="#2d3748" stroke="#22c55e" stroke-width="2" class="pin-node" data-net="s2"/>
  <text x="522" y="357" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#cbd5e1">D7</text>
  <circle id="p-D8"  cx="530" cy="370" r="4.5" fill="#2d3748" stroke="#86efac" stroke-width="2" class="pin-node" data-net="key"/>
  <text x="522" y="374" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#cbd5e1">D8</text>
  <circle id="p-D9"  cx="530" cy="387" r="4.5" fill="#2d3748" stroke="#facc15" stroke-width="2" class="pin-node" data-net="servo"/>
  <text x="522" y="391" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#cbd5e1">D9</text>
  <circle id="p-D10" cx="530" cy="404" r="4.5" fill="#2d3748" stroke="#38bdf8" stroke-width="2" class="pin-node" data-net="in1"/>
  <text x="522" y="408" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#cbd5e1">D10</text>
  <circle id="p-D11" cx="530" cy="421" r="4.5" fill="#2d3748" stroke="#7dd3fc" stroke-width="2" class="pin-node" data-net="in2"/>
  <text x="522" y="425" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#cbd5e1">D11</text>
  <circle id="p-D12" cx="530" cy="438" r="4.5" fill="#2d3748" stroke="#f472b6" stroke-width="2" class="pin-node" data-net="neo"/>
  <text x="522" y="442" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#cbd5e1">D12</text>

  <!-- LEFT pin header — 5V, GND, A0–A5 -->
  <rect x="366" y="258" width="8" height="244" rx="2" fill="#2d3748" stroke="#4a5568" stroke-width=".5"/>
  <circle id="p-5V"   cx="370" cy="268" r="4.5" fill="#2d3748" stroke="#ef4444" stroke-width="2" class="pin-node" data-net="5v"/>
  <text x="378" y="272" font-family="JetBrains Mono,monospace" font-size="7" fill="#ef4444">5V</text>
  <circle id="p-GND1" cx="370" cy="285" r="4.5" fill="#2d3748" stroke="#78716c" stroke-width="2" class="pin-node" data-net="gnd"/>
  <text x="378" y="289" font-family="JetBrains Mono,monospace" font-size="7" fill="#78716c">GND</text>
  <circle id="p-GND2" cx="370" cy="302" r="4.5" fill="#2d3748" stroke="#78716c" stroke-width="2" class="pin-node" data-net="gnd"/>
  <text x="378" y="306" font-family="JetBrains Mono,monospace" font-size="7" fill="#78716c">GND</text>
  <!-- A4=SDA, A5=SCL for I2C -->
  <circle id="p-A0" cx="370" cy="360" r="4.5" fill="#2d3748" stroke="#34d399" stroke-width="2" class="pin-node" data-net="sw1"/>
  <text x="378" y="364" font-family="JetBrains Mono,monospace" font-size="7" fill="#34d399">A0</text>
  <circle id="p-A1" cx="370" cy="377" r="4.5" fill="#2d3748" stroke="#2dd4bf" stroke-width="2" class="pin-node" data-net="sw2"/>
  <text x="378" y="381" font-family="JetBrains Mono,monospace" font-size="7" fill="#2dd4bf">A1</text>
  <circle id="p-A2" cx="370" cy="394" r="4.5" fill="#2d3748" stroke="#22d3ee" stroke-width="2" class="pin-node" data-net="sw3"/>
  <text x="378" y="398" font-family="JetBrains Mono,monospace" font-size="7" fill="#22d3ee">A2</text>
  <circle id="p-A3" cx="370" cy="411" r="4.5" fill="#2d3748" stroke="#38bdf8" stroke-width="2" class="pin-node" data-net="sw4"/>
  <text x="378" y="415" font-family="JetBrains Mono,monospace" font-size="7" fill="#38bdf8">A3</text>
  <circle id="p-A4" cx="370" cy="428" r="4.5" fill="#2d3748" stroke="#a78bfa" stroke-width="2" class="pin-node" data-net="sda"/>
  <text x="378" y="432" font-family="JetBrains Mono,monospace" font-size="7" fill="#a78bfa">A4</text>
  <text x="378" y="442" font-family="JetBrains Mono,monospace" font-size="5.5" fill="#7c3aed">SDA</text>
  <circle id="p-A5" cx="370" cy="449" r="4.5" fill="#2d3748" stroke="#c084fc" stroke-width="2" class="pin-node" data-net="scl"/>
  <text x="378" y="453" font-family="JetBrains Mono,monospace" font-size="7" fill="#c084fc">A5</text>
  <text x="378" y="463" font-family="JetBrains Mono,monospace" font-size="5.5" fill="#7c3aed">SCL</text>
  <circle id="p-A44" cx="370" cy="470" r="4.5" fill="#2d3748" stroke="#818cf8" stroke-width="2" class="pin-node" data-net="sw5"/>
  <text x="378" y="474" font-family="JetBrains Mono,monospace" font-size="7" fill="#818cf8">A6</text>

  <!-- I2C label on Nano -->
  <rect x="376" y="478" width="58" height="14" rx="2" fill="#1e1040" stroke="#7c3aed" stroke-width="1"/>
  <text x="405" y="489" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#a78bfa">I2C: A4+A5</text>
</g>

<!-- ══ SSD1306 OLED ══ -->
<g filter="url(#pcb-sh)">
  <rect x="50" y="28" width="180" height="100" rx="6" fill="#0a001a"/>
  <rect x="56" y="34" width="168" height="60" rx="3" fill="#050010" stroke="#4c1d95" stroke-width="1"/>
  <!-- OLED screen face -->
  <rect x="62" y="38" width="155" height="52" rx="2" fill="#030008"/>
  <!-- fake OLED content -->
  <rect x="64" y="40" width="38" height="10" rx="1" fill="#7c3aed" opacity=".9"/>
  <text x="83" y="49" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="5.5" fill="#000">MANUAL</text>
  <text x="130" y="60" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="20" fill="#a78bfa" opacity=".9" letter-spacing="2">50</text>
  <text x="196" y="66" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="8" fill="#7c3aed">mL</text>
  <rect x="62" y="82" width="155" height="5" rx="1" fill="#1a0040"/>
  <rect x="62" y="82" width="78" height="5" rx="1" fill="#7c3aed" opacity=".8"/>
  <text x="140" y="105" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="7" fill="#a78bfa" letter-spacing="2">SSD1306 OLED</text>
  <text x="140" y="116" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#4b5563">0.96" 128×64 I2C</text>
  <!-- 4 pins: GND VCC SCL SDA -->
  <circle id="p-OG"   cx="80"  cy="130" r="4" fill="#1e293b" stroke="#78716c" stroke-width="1.5" class="pin-node" data-net="gnd"/>
  <circle id="p-OV"   cx="100" cy="130" r="4" fill="#991b1b" stroke="#ef4444" stroke-width="1.5" class="pin-node" data-net="5v"/>
  <circle id="p-OSCL" cx="120" cy="130" r="4" fill="#1e0040" stroke="#c084fc" stroke-width="1.5" class="pin-node" data-net="scl"/>
  <circle id="p-OSDA" cx="140" cy="130" r="4" fill="#1e0040" stroke="#a78bfa" stroke-width="1.5" class="pin-node" data-net="sda"/>
  <text x="80"  y="143" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6.5" fill="#78716c">GND</text>
  <text x="100" y="143" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6.5" fill="#ef4444">VCC</text>
  <text x="120" y="143" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6.5" fill="#c084fc">SCL</text>
  <text x="140" y="143" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6.5" fill="#a78bfa">SDA</text>
  <!-- I2C note -->
  <rect x="56" y="148" width="168" height="12" rx="2" fill="#1e1040" stroke="#7c3aed" stroke-width=".5"/>
  <text x="140" y="158" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#7c3aed">I2C addr: 0x3C  (try 0x3D if blank)</text>
</g>

<!-- ══ NEOPIXEL ══ -->
<g filter="url(#shadow)">
  <rect x="50" y="185" width="220" height="52" rx="5" fill="#0a0a1a" stroke="#db2777" stroke-width="1.5"/>
  <rect x="58"  y="195" width="28" height="28" rx="3" fill="#831843"/><circle cx="72"  cy="209" r="8" fill="#f472b6" opacity=".9" filter="url(#glow)"/>
  <rect x="96"  y="195" width="28" height="28" rx="3" fill="#1e3a5f"/><circle cx="110" cy="209" r="8" fill="#38bdf8" opacity=".9" filter="url(#glow)"/>
  <rect x="134" y="195" width="28" height="28" rx="3" fill="#14532d"/><circle cx="148" cy="209" r="8" fill="#4ade80" opacity=".9" filter="url(#glow)"/>
  <rect x="172" y="195" width="28" height="28" rx="3" fill="#78350f"/><circle cx="186" cy="209" r="8" fill="#fb923c" opacity=".9" filter="url(#glow)"/>
  <rect x="210" y="195" width="28" height="28" rx="3" fill="#4c1d95"/><circle cx="224" cy="209" r="8" fill="#a78bfa" opacity=".9" filter="url(#glow)"/>
  <text x="140" y="245" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="7" fill="#f472b6" letter-spacing="2">NEOPIXEL ×5</text>
  <circle id="p-DIN" cx="80"  cy="250" r="4" fill="#db2777" stroke="#f472b6" stroke-width="1.5" class="pin-node" data-net="neo"/>
  <circle id="p-NV"  cx="106" cy="250" r="4" fill="#991b1b" stroke="#ef4444" stroke-width="1.5" class="pin-node" data-net="5v"/>
  <circle id="p-NG"  cx="132" cy="250" r="4" fill="#1e293b" stroke="#78716c" stroke-width="1.5" class="pin-node" data-net="gnd"/>
  <text x="80"  y="262" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6.5" fill="#f472b6">DIN</text>
  <text x="106" y="262" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6.5" fill="#ef4444">5V</text>
  <text x="132" y="262" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6.5" fill="#78716c">GND</text>
</g>

<!-- ══ BUTTONS ══ -->
<g filter="url(#shadow)">
  <rect x="50" y="285" width="76" height="78" rx="6" fill="#1c0a00" stroke="#ea580c" stroke-width="1.5"/>
  <text x="88" y="302" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="7" fill="#f97316" letter-spacing="1">BTN 1</text>
  <text x="88" y="312" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#4b5563">ON/OFF</text>
  <circle cx="88" cy="333" r="14" fill="#7c2d12" stroke="#f97316" stroke-width="2.5"/>
  <circle cx="88" cy="333" r="7" fill="#c2410c"/>
  <circle id="p-B1G" cx="72" cy="355" r="3.5" fill="#1e293b" stroke="#78716c" stroke-width="1.5" class="pin-node" data-net="gnd"/>
  <circle id="p-B1S" cx="104" cy="355" r="3.5" fill="#7c2d12" stroke="#f97316" stroke-width="1.5" class="pin-node" data-net="btn1"/>
  <text x="72"  y="367" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#78716c">GND</text>
  <text x="104" y="367" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#f97316">D4</text>
</g>
<g filter="url(#shadow)">
  <rect x="148" y="285" width="76" height="78" rx="6" fill="#1c0500" stroke="#c2410c" stroke-width="1.5"/>
  <text x="186" y="302" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="7" fill="#fb923c" letter-spacing="1">BTN 2</text>
  <text x="186" y="312" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#4b5563">SERVE</text>
  <circle cx="186" cy="333" r="14" fill="#7c2d12" stroke="#fb923c" stroke-width="2.5"/>
  <circle cx="186" cy="333" r="7" fill="#c2410c"/>
  <circle id="p-B2G" cx="170" cy="355" r="3.5" fill="#1e293b" stroke="#78716c" stroke-width="1.5" class="pin-node" data-net="gnd"/>
  <circle id="p-B2S" cx="202" cy="355" r="3.5" fill="#7c2d12" stroke="#fb923c" stroke-width="1.5" class="pin-node" data-net="btn2"/>
  <text x="170" y="367" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#78716c">GND</text>
  <text x="202" y="367" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#fb923c">D5</text>
</g>

<!-- ══ ENCODER ══ -->
<g filter="url(#shadow)">
  <rect x="50" y="390" width="130" height="106" rx="6" fill="#001a08" stroke="#16a34a" stroke-width="1.5"/>
  <text x="115" y="408" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="8" fill="#4ade80" letter-spacing="1">ENCODER</text>
  <circle cx="115" cy="446" r="24" fill="#052e16" stroke="#16a34a" stroke-width="2.5"/>
  <circle cx="115" cy="446" r="13" fill="#14532d" stroke="#4ade80" stroke-width="1.5"/>
  <circle cx="115" cy="446" r="4" fill="#052e16"/>
  <line x1="115" y1="434" x2="115" y2="441" stroke="#4ade80" stroke-width="2" stroke-linecap="round"/>
  <circle id="p-ES1" cx="63"  cy="482" r="3.5" fill="#14532d" stroke="#4ade80"  stroke-width="1.5" class="pin-node" data-net="s1"/>
  <circle id="p-ES2" cx="80"  cy="482" r="3.5" fill="#14532d" stroke="#22c55e"  stroke-width="1.5" class="pin-node" data-net="s2"/>
  <circle id="p-EK"  cx="97"  cy="482" r="3.5" fill="#14532d" stroke="#86efac"  stroke-width="1.5" class="pin-node" data-net="key"/>
  <circle id="p-EV"  cx="114" cy="482" r="3.5" fill="#991b1b" stroke="#ef4444"  stroke-width="1.5" class="pin-node" data-net="5v"/>
  <circle id="p-EG"  cx="131" cy="482" r="3.5" fill="#1e293b" stroke="#78716c"  stroke-width="1.5" class="pin-node" data-net="gnd"/>
  <text x="63"  y="494" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#4ade80">S1</text>
  <text x="80"  y="494" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#22c55e">S2</text>
  <text x="97"  y="494" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#86efac">KEY</text>
  <text x="114" y="494" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#ef4444">5V</text>
  <text x="131" y="494" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#78716c">GND</text>
</g>

<!-- ══ LIMIT SWITCHES ══ -->
<g filter="url(#shadow)">
  <rect x="50" y="520" width="240" height="196" rx="6" fill="#001020" stroke="#0284c7" stroke-width="1.5"/>
  <text x="170" y="538" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="8" fill="#38bdf8" letter-spacing="1">LIMIT SWITCHES</text>
  <text x="170" y="550" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6.5" fill="#4b5563">5× — one per glass slot</text>
  <rect x="60" y="557" width="52" height="22" rx="3" fill="#0c1e30" stroke="#0369a1" stroke-width="1"/>
  <rect x="76" y="562" width="12" height="12" rx="1" fill="#1e40af"/><rect x="80" y="559" width="4" height="6" rx="1" fill="#60a5fa"/>
  <text x="66" y="587" font-family="JetBrains Mono,monospace" font-size="6" fill="#34d399">SW1→A0</text>
  <circle id="p-SW1S" cx="64"  cy="568" r="3" fill="#34d399" class="pin-node" data-net="sw1"/>
  <circle id="p-SW1G" cx="108" cy="568" r="3" fill="#1e293b" stroke="#78716c" stroke-width="1" class="pin-node" data-net="gnd"/>
  <rect x="130" y="557" width="52" height="22" rx="3" fill="#0c1e30" stroke="#0369a1" stroke-width="1"/>
  <rect x="146" y="562" width="12" height="12" rx="1" fill="#1e40af"/><rect x="150" y="559" width="4" height="6" rx="1" fill="#60a5fa"/>
  <text x="136" y="587" font-family="JetBrains Mono,monospace" font-size="6" fill="#2dd4bf">SW2→A1</text>
  <circle id="p-SW2S" cx="134" cy="568" r="3" fill="#2dd4bf" class="pin-node" data-net="sw2"/>
  <circle id="p-SW2G" cx="178" cy="568" r="3" fill="#1e293b" stroke="#78716c" stroke-width="1" class="pin-node" data-net="gnd"/>
  <rect x="60" y="600" width="52" height="22" rx="3" fill="#0c1e30" stroke="#0369a1" stroke-width="1"/>
  <rect x="76" y="605" width="12" height="12" rx="1" fill="#1e40af"/><rect x="80" y="602" width="4" height="6" rx="1" fill="#60a5fa"/>
  <text x="66" y="630" font-family="JetBrains Mono,monospace" font-size="6" fill="#22d3ee">SW3→A2</text>
  <circle id="p-SW3S" cx="64"  cy="611" r="3" fill="#22d3ee" class="pin-node" data-net="sw3"/>
  <circle id="p-SW3G" cx="108" cy="611" r="3" fill="#1e293b" stroke="#78716c" stroke-width="1" class="pin-node" data-net="gnd"/>
  <rect x="130" y="600" width="52" height="22" rx="3" fill="#0c1e30" stroke="#0369a1" stroke-width="1"/>
  <rect x="146" y="605" width="12" height="12" rx="1" fill="#1e40af"/><rect x="150" y="602" width="4" height="6" rx="1" fill="#60a5fa"/>
  <text x="136" y="630" font-family="JetBrains Mono,monospace" font-size="6" fill="#38bdf8">SW4→A3</text>
  <circle id="p-SW4S" cx="134" cy="611" r="3" fill="#38bdf8" class="pin-node" data-net="sw4"/>
  <circle id="p-SW4G" cx="178" cy="611" r="3" fill="#1e293b" stroke="#78716c" stroke-width="1" class="pin-node" data-net="gnd"/>
  <rect x="95" y="643" width="52" height="22" rx="3" fill="#0c1e30" stroke="#0369a1" stroke-width="1"/>
  <rect x="111" y="648" width="12" height="12" rx="1" fill="#1e40af"/><rect x="115" y="645" width="4" height="6" rx="1" fill="#60a5fa"/>
  <text x="101" y="673" font-family="JetBrains Mono,monospace" font-size="6" fill="#818cf8">SW5→A6</text>
  <circle id="p-SW5S" cx="99"  cy="654" r="3" fill="#818cf8" class="pin-node" data-net="sw5"/>
  <circle id="p-SW5G" cx="143" cy="654" r="3" fill="#1e293b" stroke="#78716c" stroke-width="1" class="pin-node" data-net="gnd"/>
</g>

<!-- ══ MINI L298N ══ -->
<g filter="url(#pcb-sh)">
  <rect x="660" y="330" width="130" height="115" rx="6" fill="#cc0000"/>
  <rect x="665" y="335" width="120" height="105" rx="4" fill="#b91c1c"/>
  <rect x="690" y="350" width="60" height="52" rx="2" fill="#111"/>
  <text x="720" y="372" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="7" fill="#6b7280">L298N</text>
  <text x="720" y="384" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#4b5563">MINI</text>
  <text x="725" y="343" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="7" fill="#fca5a5" letter-spacing="1">MINI L298N</text>
  <rect x="665" y="408" width="16" height="13" rx="1" fill="#78716c" stroke="#a8a29e" stroke-width=".5"/>
  <rect x="665" y="424" width="16" height="13" rx="1" fill="#78716c" stroke="#a8a29e" stroke-width=".5"/>
  <rect x="665" y="440" width="16" height="13" rx="1" fill="#78716c" stroke="#a8a29e" stroke-width=".5"/>
  <circle id="p-IN1" cx="673" cy="414" r="3.5" fill="#374151" stroke="#38bdf8" stroke-width="1.5" class="pin-node" data-net="in1"/>
  <circle id="p-IN2" cx="673" cy="430" r="3.5" fill="#374151" stroke="#7dd3fc" stroke-width="1.5" class="pin-node" data-net="in2"/>
  <circle id="p-VIN" cx="673" cy="446" r="3.5" fill="#374151" stroke="#fbbf24" stroke-width="1.5" class="pin-node" data-net="psu2"/>
  <text x="663" y="419" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#38bdf8">IN1</text>
  <text x="663" y="435" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#7dd3fc">IN2</text>
  <text x="663" y="451" text-anchor="end" font-family="JetBrains Mono,monospace" font-size="7" fill="#fbbf24">VIN</text>
  <rect x="779" y="408" width="16" height="13" rx="1" fill="#78716c" stroke="#a8a29e" stroke-width=".5"/>
  <rect x="779" y="424" width="16" height="13" rx="1" fill="#78716c" stroke="#a8a29e" stroke-width=".5"/>
  <circle id="p-OUT+" cx="787" cy="414" r="3.5" fill="#374151" stroke="#fb923c" stroke-width="1.5" class="pin-node" data-net="pump-pos"/>
  <circle id="p-OUT-" cx="787" cy="430" r="3.5" fill="#374151" stroke="#78716c" stroke-width="1.5" class="pin-node" data-net="pump-neg"/>
  <text x="797" y="419" font-family="JetBrains Mono,monospace" font-size="7" fill="#fb923c">OUT+</text>
  <text x="797" y="435" font-family="JetBrains Mono,monospace" font-size="7" fill="#78716c">OUT-</text>
</g>

<!-- ══ SERVO ══ -->
<g filter="url(#shadow)">
  <rect x="700" y="100" width="110" height="72" rx="5" fill="#2d3748"/>
  <rect x="706" y="106" width="98" height="60" rx="3" fill="#1a202c"/>
  <rect x="755" y="90" width="16" height="16" rx="2" fill="#e2e8f0"/>
  <circle cx="763" cy="98" r="4" fill="#a0aec0"/>
  <text x="750" y="140" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="8" fill="#a0aec0" letter-spacing="1">SERVO</text>
  <circle id="p-SIG" cx="714" cy="172" r="4" fill="#854d0e" stroke="#facc15" stroke-width="1.5" class="pin-node" data-net="servo"/>
  <circle id="p-SV"  cx="730" cy="172" r="4" fill="#991b1b" stroke="#ef4444" stroke-width="1.5" class="pin-node" data-net="5v"/>
  <circle id="p-SG"  cx="746" cy="172" r="4" fill="#1e293b" stroke="#78716c" stroke-width="1.5" class="pin-node" data-net="gnd"/>
  <text x="714" y="184" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#facc15">SIG</text>
  <text x="730" y="184" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#ef4444">5V</text>
  <text x="746" y="184" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#78716c">GND</text>
</g>

<!-- ══ DC PUMP ══ -->
<g filter="url(#shadow)">
  <rect x="700" y="580" width="130" height="100" rx="6" fill="#1a0800" stroke="#b45309" stroke-width="1.5"/>
  <text x="765" y="598" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="8" fill="#fbbf24" letter-spacing="1">DC PUMP</text>
  <ellipse cx="750" cy="645" rx="30" ry="26" fill="#0f0800" stroke="#92400e" stroke-width="2"/>
  <ellipse cx="750" cy="645" rx="14" ry="14" fill="#1c1200" stroke="#b45309" stroke-width="1.5"/>
  <ellipse cx="750" cy="645" rx="4"  ry="4"  fill="#92400e"/>
  <circle id="p-PP" cx="800" cy="613" r="4" fill="#7c2d12" stroke="#ef4444" stroke-width="1.5" class="pin-node" data-net="pump-pos"/>
  <circle id="p-PN" cx="816" cy="613" r="4" fill="#1e293b" stroke="#78716c" stroke-width="1.5" class="pin-node" data-net="pump-neg"/>
  <text x="800" y="604" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#fb923c">+</text>
  <text x="816" y="604" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#78716c">-</text>
</g>

<!-- ══ POWER SUPPLIES ══ -->
<g filter="url(#shadow)">
  <rect x="370" y="28" width="210" height="80" rx="7" fill="#1c0800" stroke="#ea580c" stroke-width="1.5"/>
  <text x="475" y="46" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="8" fill="#fb923c" letter-spacing="2">POWER</text>
  <rect x="382" y="52" width="90" height="46" rx="4" fill="#0f0300" stroke="#c2410c" stroke-width="1"/>
  <text x="427" y="66" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="7" fill="#f97316">PSU 1 — 5V</text>
  <text x="427" y="77" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#7c2d12">Logic+Servo</text>
  <circle id="p-P1+" cx="400" cy="90" r="4.5" fill="#991b1b" stroke="#ef4444" stroke-width="1.5" class="pin-node" data-net="5v"/>
  <circle id="p-P1-" cx="420" cy="90" r="4.5" fill="#1e293b" stroke="#78716c" stroke-width="1.5" class="pin-node" data-net="gnd"/>
  <text x="400" y="102" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#ef4444">+5V</text>
  <text x="420" y="102" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#78716c">GND</text>
  <rect x="484" y="52" width="90" height="46" rx="4" fill="#0f0c00" stroke="#ca8a04" stroke-width="1"/>
  <text x="529" y="66" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="7" fill="#fbbf24">PSU 2</text>
  <text x="529" y="77" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#92400e">Motor/Pump</text>
  <circle id="p-P2+" cx="507" cy="90" r="4.5" fill="#1a1500" stroke="#fbbf24" stroke-width="1.5" class="pin-node" data-net="psu2"/>
  <circle id="p-P2-" cx="527" cy="90" r="4.5" fill="#1e293b" stroke="#78716c" stroke-width="1.5" class="pin-node" data-net="gnd"/>
  <text x="507" y="102" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#fbbf24">+V</text>
  <text x="527" y="102" text-anchor="middle" font-family="JetBrains Mono,monospace" font-size="6" fill="#78716c">GND</text>
</g>

<!-- ══ GND RAIL ══ -->
<rect x="220" y="775" width="620" height="14" rx="4" fill="#1e293b" stroke="#475569" stroke-width="1.5"/>
<text x="530" y="786" text-anchor="middle" font-family="Orbitron,sans-serif" font-size="7" fill="#64748b" letter-spacing="3">COMMON GROUND</text>

<!-- ══════════════ WIRES ══════════════ -->

<!-- 5V power -->
<g class="wire" data-net="5v" data-label="5V Power" data-from="PSU1 +5V" data-to="Nano 5V · Servo · NeoPixel · Encoder · OLED VCC">
  <path d="M400,90 L400,138 L340,138 L340,268 L366,268" fill="none" stroke="#ef4444" stroke-width="2.2" marker-end="url(#am-red)"/>
  <path d="M100,130 L100,138 L400,138" fill="none" stroke="#ef4444" stroke-width="1.6" marker-end="url(#am-red)"/>
  <path d="M106,250 L106,143 L400,143" fill="none" stroke="#ef4444" stroke-width="1.6" marker-end="url(#am-red)"/>
  <path d="M730,172 L730,188 L348,188 L348,268 L366,268" fill="none" stroke="#ef4444" stroke-width="1.6" marker-end="url(#am-red)"/>
  <path d="M114,482 L114,268 L366,268" fill="none" stroke="#ef4444" stroke-width="1.6" marker-end="url(#am-red)"/>
</g>

<!-- GND -->
<g class="wire" data-net="gnd" data-label="Common Ground" data-from="All GNDs" data-to="Common Ground Rail">
  <path d="M420,90 L420,775" fill="none" stroke="#78716c" stroke-width="1.6" stroke-dasharray="6,3" marker-end="url(#am-gnd)"/>
  <path d="M527,90 L527,775" fill="none" stroke="#78716c" stroke-width="1.6" stroke-dasharray="6,3" marker-end="url(#am-gnd)"/>
  <path d="M370,285 L308,285 L308,775 L220,775" fill="none" stroke="#78716c" stroke-width="1.8" stroke-dasharray="6,3" marker-end="url(#am-gnd)"/>
  <path d="M80,130 L80,775" fill="none" stroke="#78716c" stroke-width="1.4" stroke-dasharray="5,3" marker-end="url(#am-gnd)"/>
  <path d="M132,250 L132,775" fill="none" stroke="#78716c" stroke-width="1.4" stroke-dasharray="5,3" marker-end="url(#am-gnd)"/>
  <path d="M72,355 L72,775" fill="none" stroke="#78716c" stroke-width="1.4" stroke-dasharray="5,3" marker-end="url(#am-gnd)"/>
  <path d="M170,355 L170,779 L220,779" fill="none" stroke="#78716c" stroke-width="1.4" stroke-dasharray="5,3" marker-end="url(#am-gnd)"/>
  <path d="M131,494 L131,775" fill="none" stroke="#78716c" stroke-width="1.4" stroke-dasharray="5,3" marker-end="url(#am-gnd)"/>
  <path d="M746,172 L746,766 L840,766 L840,775" fill="none" stroke="#78716c" stroke-width="1.4" stroke-dasharray="5,3" marker-end="url(#am-gnd)"/>
  <path d="M673,446 L640,446 L640,775" fill="none" stroke="#78716c" stroke-width="1.6" stroke-dasharray="6,3" marker-end="url(#am-gnd)"/>
  <path d="M108,568 L222,568 L222,775" fill="none" stroke="#78716c" stroke-width="1.4" stroke-dasharray="4,3" marker-end="url(#am-gnd)"/>
  <path d="M178,568 L226,568 L226,775" fill="none" stroke="#78716c" stroke-width="1.2" stroke-dasharray="4,3"/>
  <path d="M108,611 L230,611 L230,775" fill="none" stroke="#78716c" stroke-width="1.2" stroke-dasharray="4,3"/>
  <path d="M178,611 L234,611 L234,775" fill="none" stroke="#78716c" stroke-width="1.2" stroke-dasharray="4,3"/>
  <path d="M143,654 L238,654 L238,775" fill="none" stroke="#78716c" stroke-width="1.2" stroke-dasharray="4,3"/>
</g>

<!-- PSU2 → L298N VIN -->
<g class="wire" data-net="psu2" data-label="Motor Power" data-from="PSU2 +V" data-to="Mini L298N VIN">
  <path d="M507,90 L507,146 L638,146 L638,446 L665,446" fill="none" stroke="#fbbf24" stroke-width="2.5" marker-end="url(#am-yellow)"/>
</g>

<!-- OLED SDA → Nano A4 -->
<g class="wire" data-net="sda" data-label="I2C Data (SDA)" data-from="OLED SDA" data-to="Nano A4">
  <path d="M140,130 L140,160 L350,160 L350,428 L366,428" fill="none" stroke="#a78bfa" stroke-width="2.2" marker-end="url(#am-purple)"/>
</g>

<!-- OLED SCL → Nano A5 -->
<g class="wire" data-net="scl" data-label="I2C Clock (SCL)" data-from="OLED SCL" data-to="Nano A5">
  <path d="M120,130 L120,155 L344,155 L344,449 L366,449" fill="none" stroke="#c084fc" stroke-width="2.2" marker-end="url(#am-violet)"/>
</g>

<!-- NeoPixel DIN → D12 -->
<g class="wire" data-net="neo" data-label="NeoPixel Data" data-from="NeoPixel DIN" data-to="Nano D12">
  <path d="M80,250 L80,270 L628,270 L628,438 L530,438" fill="none" stroke="#f472b6" stroke-width="2" marker-end="url(#am-pink)"/>
</g>

<!-- BTN1 → D4 -->
<g class="wire" data-net="btn1" data-label="Button 1 (ON/OFF)" data-from="Button 1 signal" data-to="Nano D4">
  <path d="M104,355 L104,378 L634,378 L634,302 L530,302" fill="none" stroke="#f97316" stroke-width="2" marker-end="url(#am-orange)"/>
</g>

<!-- BTN2 → D5 -->
<g class="wire" data-net="btn2" data-label="Button 2 (Serve/Mode)" data-from="Button 2 signal" data-to="Nano D5">
  <path d="M202,355 L202,384 L638,384 L638,319 L530,319" fill="none" stroke="#fb923c" stroke-width="2" marker-end="url(#am-amber)"/>
</g>

<!-- Encoder S1 → D6 -->
<g class="wire" data-net="s1" data-label="Encoder S1" data-from="Encoder S1" data-to="Nano D6">
  <path d="M63,482 L63,508 L642,508 L642,336 L530,336" fill="none" stroke="#4ade80" stroke-width="2" marker-end="url(#am-green)"/>
</g>

<!-- Encoder S2 → D7 -->
<g class="wire" data-net="s2" data-label="Encoder S2" data-from="Encoder S2" data-to="Nano D7">
  <path d="M80,482 L80,514 L646,514 L646,353 L530,353" fill="none" stroke="#22c55e" stroke-width="2" marker-end="url(#am-lime)"/>
</g>

<!-- Encoder KEY → D8 -->
<g class="wire" data-net="key" data-label="Encoder KEY" data-from="Encoder KEY button" data-to="Nano D8">
  <path d="M97,482 L97,520 L650,520 L650,370 L530,370" fill="none" stroke="#86efac" stroke-width="2" marker-end="url(#am-mint)"/>
</g>

<!-- Servo SIG → D9 -->
<g class="wire" data-net="servo" data-label="Servo Signal" data-from="Servo SIG (yellow wire)" data-to="Nano D9">
  <path d="M714,172 L714,194 L658,194 L658,387 L530,387" fill="none" stroke="#facc15" stroke-width="2.5" marker-end="url(#am-yellow)"/>
</g>

<!-- D10 → L298N IN1 -->
<g class="wire" data-net="in1" data-label="Motor IN1" data-from="Nano D10" data-to="Mini L298N IN1">
  <path d="M530,404 L638,404 L638,414 L665,414" fill="none" stroke="#38bdf8" stroke-width="2.5" marker-end="url(#am-sky)"/>
</g>

<!-- D11 → L298N IN2 -->
<g class="wire" data-net="in2" data-label="Motor IN2" data-from="Nano D11" data-to="Mini L298N IN2">
  <path d="M530,421 L634,421 L634,430 L665,430" fill="none" stroke="#7dd3fc" stroke-width="2.5" marker-end="url(#am-blue)"/>
</g>

<!-- L298N OUT+ → Pump+ -->
<g class="wire" data-net="pump-pos" data-label="Pump Power +" data-from="L298N OUT+" data-to="DC Pump +">
  <path d="M787,414 L838,414 L838,613 L804,613" fill="none" stroke="#fb923c" stroke-width="2.5" marker-end="url(#am-amber)"/>
</g>

<!-- L298N OUT- → Pump- -->
<g class="wire" data-net="pump-neg" data-label="Pump Power −" data-from="L298N OUT−" data-to="DC Pump −">
  <path d="M787,430 L842,430 L842,620 L820,620" fill="none" stroke="#78716c" stroke-width="1.8" marker-end="url(#am-gnd)"/>
</g>

<!-- Limit SW1 → A0 -->
<g class="wire" data-net="sw1" data-label="Limit Switch 1" data-from="Limit SW1 signal" data-to="Nano A0">
  <path d="M64,568 L38,568 L38,360 L366,360" fill="none" stroke="#34d399" stroke-width="2" marker-end="url(#am-teal)"/>
</g>

<!-- Limit SW2 → A1 -->
<g class="wire" data-net="sw2" data-label="Limit Switch 2" data-from="Limit SW2 signal" data-to="Nano A1">
  <path d="M134,568 L34,568 L34,377 L366,377" fill="none" stroke="#2dd4bf" stroke-width="2" marker-end="url(#am-teal)"/>
</g>

<!-- Limit SW3 → A2 -->
<g class="wire" data-net="sw3" data-label="Limit Switch 3" data-from="Limit SW3 signal" data-to="Nano A2">
  <path d="M64,611 L30,611 L30,394 L366,394" fill="none" stroke="#22d3ee" stroke-width="2" marker-end="url(#am-cyan)"/>
</g>

<!-- Limit SW4 → A3 -->
<g class="wire" data-net="sw4" data-label="Limit Switch 4" data-from="Limit SW4 signal" data-to="Nano A3">
  <path d="M134,611 L26,611 L26,411 L366,411" fill="none" stroke="#38bdf8" stroke-width="2" marker-end="url(#am-sky)"/>
</g>

<!-- Limit SW5 → A6 -->
<g class="wire" data-net="sw5" data-label="Limit Switch 5" data-from="Limit SW5 signal" data-to="Nano A6">
  <path d="M99,654 L22,654 L22,470 L366,470" fill="none" stroke="#818cf8" stroke-width="2" marker-end="url(#am-indigo)"/>
</g>

</svg>
</div>

<!-- SIDEBAR -->
<div class="sidebar" id="sidebar">
  <div class="s-title">CLICK TO HIGHLIGHT</div>
  <div class="conn-row" data-net="5v">      <div class="conn-dot" style="background:#ef4444"></div><span class="conn-from">5V Power</span>       <span class="conn-to">PSU1→All</span></div>
  <div class="conn-row" data-net="gnd">     <div class="conn-dot" style="background:#78716c"></div><span class="conn-from">GND Rail</span>       <span class="conn-to">All→Rail</span></div>
  <div class="conn-row" data-net="psu2">    <div class="conn-dot" style="background:#fbbf24"></div><span class="conn-from">Motor Power</span>    <span class="conn-to">PSU2→L298N</span></div>
  <div class="s-gap"></div>
  <div class="conn-row" data-net="sda">     <div class="conn-dot" style="background:#a78bfa"></div><span class="conn-from">OLED SDA</span>       <span class="conn-to">→ A4</span></div>
  <div class="conn-row" data-net="scl">     <div class="conn-dot" style="background:#c084fc"></div><span class="conn-from">OLED SCL</span>       <span class="conn-to">→ A5</span></div>
  <div class="conn-row" data-net="btn1">    <div class="conn-dot" style="background:#f97316"></div><span class="conn-from">Button 1</span>       <span class="conn-to">→ D4</span></div>
  <div class="conn-row" data-net="btn2">    <div class="conn-dot" style="background:#fb923c"></div><span class="conn-from">Button 2</span>       <span class="conn-to">→ D5</span></div>
  <div class="conn-row" data-net="s1">      <div class="conn-dot" style="background:#4ade80"></div><span class="conn-from">Encoder S1</span>     <span class="conn-to">→ D6</span></div>
  <div class="conn-row" data-net="s2">      <div class="conn-dot" style="background:#22c55e"></div><span class="conn-from">Encoder S2</span>     <span class="conn-to">→ D7</span></div>
  <div class="conn-row" data-net="key">     <div class="conn-dot" style="background:#86efac"></div><span class="conn-from">Encoder KEY</span>    <span class="conn-to">→ D8</span></div>
  <div class="conn-row" data-net="servo">   <div class="conn-dot" style="background:#facc15"></div><span class="conn-from">Servo Signal</span>   <span class="conn-to">→ D9</span></div>
  <div class="conn-row" data-net="in1">     <div class="conn-dot" style="background:#38bdf8"></div><span class="conn-from">L298N IN1</span>      <span class="conn-to">← D10</span></div>
  <div class="conn-row" data-net="in2">     <div class="conn-dot" style="background:#7dd3fc"></div><span class="conn-from">L298N IN2</span>      <span class="conn-to">← D11</span></div>
  <div class="conn-row" data-net="neo">     <div class="conn-dot" style="background:#f472b6"></div><span class="conn-from">NeoPixel DIN</span>   <span class="conn-to">→ D12</span></div>
  <div class="s-gap"></div>
  <div class="conn-row" data-net="sw1">     <div class="conn-dot" style="background:#34d399"></div><span class="conn-from">Limit SW 1</span>     <span class="conn-to">→ A0</span></div>
  <div class="conn-row" data-net="sw2">     <div class="conn-dot" style="background:#2dd4bf"></div><span class="conn-from">Limit SW 2</span>     <span class="conn-to">→ A1</span></div>
  <div class="conn-row" data-net="sw3">     <div class="conn-dot" style="background:#22d3ee"></div><span class="conn-from">Limit SW 3</span>     <span class="conn-to">→ A2</span></div>
  <div class="conn-row" data-net="sw4">     <div class="conn-dot" style="background:#38bdf8"></div><span class="conn-from">Limit SW 4</span>     <span class="conn-to">→ A3</span></div>
  <div class="conn-row" data-net="sw5">     <div class="conn-dot" style="background:#818cf8"></div><span class="conn-from">Limit SW 5</span>     <span class="conn-to">→ A6</span></div>
  <div class="s-gap"></div>
  <div class="conn-row" data-net="pump-pos"><div class="conn-dot" style="background:#fb923c"></div><span class="conn-from">Pump +</span>          <span class="conn-to">OUT+</span></div>
  <div class="conn-row" data-net="pump-neg"><div class="conn-dot" style="background:#78716c"></div><span class="conn-from">Pump −</span>          <span class="conn-to">OUT−</span></div>

  <div class="note warn"><b>⚠ OLED I2C ADDRESS</b>Most SSD1306 use 0x3C. If your screen stays blank after upload, change OLED_ADDRESS to 0x3D in the code.</div>
  <div class="note info"><b>💡 NANO I2C PINS</b>SDA = A4, SCL = A5. These are fixed hardware I2C pins on the Nano — do not use for anything else.</div>
  <div class="note info"><b>💡 LIBRARIES NEEDED</b>Install via Library Manager:<br>· Adafruit SSD1306<br>· Adafruit GFX<br>· Adafruit NeoPixel</div>
  <div class="note warn"><b>⚠ TWO SUPPLIES</b>PSU1 (5V) → Nano, servo, NeoPixels, OLED.<br>PSU2 (5–12V) → L298N + pump only.<br>All GNDs must share common ground.</div>
</div>
</div>

<script>
const tip=document.getElementById('tip');
let activeNet=null;
const wires=[...document.querySelectorAll('.wire[data-net]')];
const pins=[...document.querySelectorAll('.pin-node[data-net]')];
const rows=[...document.querySelectorAll('.conn-row[data-net]')];
function getNet(el){return el.dataset.net;}
function activate(net){
  if(activeNet===net){deactivate();return;}
  activeNet=net;
  wires.forEach(w=>{w.classList.toggle('active',getNet(w)===net);w.classList.toggle('faded',getNet(w)!==net);});
  pins.forEach(p=>p.classList.toggle('active',getNet(p)===net));
  rows.forEach(r=>r.classList.toggle('active',getNet(r)===net));
}
function deactivate(){
  activeNet=null;
  wires.forEach(w=>{w.classList.remove('active','faded');});
  pins.forEach(p=>p.classList.remove('active'));
  rows.forEach(r=>r.classList.remove('active'));
  tip.style.display='none';
}
function showTip(w,x,y){
  tip.innerHTML=`<div class="tf">${w.dataset.from}</div><div class="tl">${w.dataset.label}</div><div class="tp">${w.dataset.to}</div>`;
  tip.style.left=(x+14)+'px';tip.style.top=(y-10)+'px';tip.style.display='block';
}
wires.forEach(w=>{
  w.addEventListener('click',e=>{e.stopPropagation();activate(getNet(w));showTip(w,e.clientX,e.clientY);});
  w.addEventListener('mousemove',e=>{if(activeNet===getNet(w)){tip.style.left=(e.clientX+14)+'px';tip.style.top=(e.clientY-10)+'px';}});
});
pins.forEach(p=>{
  p.addEventListener('click',e=>{
    e.stopPropagation();const net=getNet(p);
    const w=wires.find(w=>getNet(w)===net);
    activate(net);
    if(w)showTip(w,e.clientX,e.clientY);
  });
});
rows.forEach(r=>{
  r.addEventListener('click',e=>{
    e.stopPropagation();const net=getNet(r);
    const w=wires.find(w=>getNet(w)===net);
    activate(net);
    if(w){const rect=r.getBoundingClientRect();showTip(w,rect.left-240,rect.top);}
  });
});
document.getElementById('svg').addEventListener('click',deactivate);
</script>
</body>
</html>
