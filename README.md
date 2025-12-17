# ESP32-Based-Automated-Window-Curtain-Control-System
### ESP32-Based Automated Window Curtain Control System

SmartCurtain-X is an embedded systems project that implements an **automatic window curtain control system** using an **ESP32 microcontroller**, **DC motors**, **H-bridge motor driver**, and **opto/IR sensors**.  
The system allows controlled upward and downward movement of a window curtain with proper end-position detection and motor protection.

---

## 📌 Project Overview

This project demonstrates how a window curtain can be automatically controlled using sensors and a microcontroller.  
The curtain moves **downwards or upwards** based on commands, and automatically stops when it reaches the **upper or lower limit**, ensuring safe and reliable operation.

The complete logic is implemented in software and tested on ESP32 before final hardware deployment.

---

## ⚙️ System Features

- ESP32-based control logic  
- Bidirectional DC motor control using H-bridge  
- Automatic curtain stopping at top and bottom  
- Opto / IR sensor-based position detection  
- Safe motor operation (no overrun)  
- Easy testing using push buttons or jumper wires  
- Expandable for IoT / mobile control

---

## 🧱 Block Diagram (Conceptual)
+-------------------+
| ESP32 |
| |
| - Control Logic |
| - Sensor Reading |
| |
+---------+---------+
|
v
+-------------------+
| Sensor Inputs |
| (Upper & Lower) |
+---------+---------+
|
v
+-------------------+
| H-Bridge Driver |
| (Motor Control) |
+---------+---------+
|
v
+-------------------+
| DC Motors |
| (Curtain System) |
+-------------------+

---

## 🔌 Hardware Components Used

| Component | Description |
|---------|------------|
| ESP32 | Main controller |
| DC Motors (2x) | Curtain movement |
| H-Bridge (L298N / L293D) | Motor direction control |
| Opto / IR Sensors (2x) | Curtain position sensing |
| Power Supply | Motor + ESP32 power |
| Jumper Wires / Breadboard | Prototyping |
| Push Buttons (optional) | Sensor simulation during testing |

---

## 🔍 Sensor Working (Opto / IR Sensors)

Two sensors are used:

### 1️⃣ Upper Sensor  
- Detects when the curtain passes or reaches the upper position  
- Output logic:
  - `1` → No curtain detected  
  - `0` → Curtain detected  

### 2️⃣ Lower Sensor  
- Detects when the curtain reaches the bottom  
- Output logic:
  - `1` → No curtain detected  
  - `0` → Curtain detected  

These sensors help the ESP32 decide **when to stop the motors automatically**.

---

## 🔄 System Logic (Truth Table)

| Curtain State | Upper Sensor (S1) | Lower Sensor (S2) | Motor State |
|--------------|------------------|------------------|------------|
| Idle (Top) | 1 | 1 | OFF |
| Moving Down | 0 | 1 | ON (Clockwise) |
| Fully Down | 0 | 0 | OFF |
| Moving Up | 0 | 1 | ON (Anti-clockwise) |
| Fully Up | 1 | 1 | OFF |

---

## 🧠 Control Logic Summary

### Curtain Moving Down:
- Motor rotates clockwise  
- Curtain passes upper sensor  
- Motor continues running  
- Motor stops when **both sensors = 0**

### Curtain Moving Up:
- Motor rotates anti-clockwise  
- Curtain moves upward  
- Motor stops when **both sensors = 1**

---

## 🧪 Testing Without Hardware (ESP32 Only)

Before connecting motors and sensors, the logic can be tested using:

- **Jumper wires** (to simulate sensors)
- **LEDs** (to represent motor direction)
- **Serial Monitor** for debugging

### Jumper Wire Simulation:
- Jumper not connected → Logic `1`
- Jumper connected to GND → Logic `0`

This allows full testing without damaging hardware.

---

## 🧰 Pin Configuration (Example)

| Function | ESP32 GPIO |
|--------|-----------|
| Upper Sensor | GPIO 32 |
| Lower Sensor | GPIO 33 |
| Motor IN1 | GPIO 25 |
| Motor IN2 | GPIO 26 |
| Motor Enable | GPIO 27 |

---

## 🚀 How to Run the Project

1. Clone the repository  
2. Open the code in Arduino IDE  
3. Select **ESP32 board**  
4. Upload the code  
5. Test using jumper wires or push buttons  
6. Connect H-bridge and motors  
7. Mount sensors and curtain mechanism  

---

## 🔒 Safety Notes

- Always use a **separate motor power supply**
- Common ground is mandatory
- Do not power motors directly from ESP32
- Add timeout logic to prevent motor damage

---

## 📈 Future Improvements

- Wi-Fi / Mobile App Control  
- Voice control integration  
- Light-based automatic opening  
- MQTT / Home Automation integration  
- Limit switch backup safety  

---

## 👨‍🎓 Project Type

- Embedded Systems  
- Automation  
- Academic / University Project  
- ESP32 Microcontroller Based  

---







