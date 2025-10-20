# 👁️ Animated OLED Eye using Arduino

This project displays a **realistic single blinking eye** on an **SH1106 128x64 OLED display** using Arduino.  
The animation includes smooth **blinking** and **natural iris movement**, making it perfect for **robot faces**, **interactive art**, or **IoT projects**.

---

## 🧠 Features
- Smooth blink animation (open → close → open)
- Random iris motion for natural behavior
- Lightweight and runs on basic Arduino boards
- Compatible with SH1106 or SSD1306 128x64 OLED displays

---

## 🧰 Hardware Required
| Component | Description |
|------------|--------------|
| Arduino Board | UNO / Nano / ESP32 / etc. |
| SH1106 128x64 OLED | I2C interface display |
| Jumper Wires | For I2C connection |

---

## 💻 Libraries Used
Install from **Arduino Library Manager**:
- `U8g2` by Oliver Kraus  
- `Wire` (comes pre-installed)

---

## ⚙️ Circuit Connection
| OLED Pin | Arduino Pin |
|-----------|-------------|
| VCC | 5V (or 3.3V for ESP32) |
| GND | GND |
| SCL | A5 (or GPIO22 for ESP32) |
| SDA | A4 (or GPIO21 for ESP32) |

---

## 🧩 Code Overview
- **Blink Animation:**  
  The eye “closes” by reducing the vertical height of the ellipse (eye shape), then reopens.  
- **Iris Motion:**  
  The iris moves randomly in X and Y directions for a more natural look.  
- **drawEye():**  
  Draws an ellipse representing the visible part of the eye.

---

## 🕹️ How It Works
1. The OLED displays an ellipse representing an open eye.  
2. The height decreases → simulating a blink.  
3. The iris (center area) moves slightly between blinks.  
4. The process repeats infinitely with realistic motion.

---

## 📸 Preview
![OLED Eye](Screenshot%202025-10-20%20143357.png)

---
