# 🚨 Presence Detection & Tab Switcher using Arduino, nRF24L01, and AutoHotkey

## 📋 Project Overview

This project is a **proximity-triggered PC automation system** that uses:

- An **HC-SR04 ultrasonic sensor** to detect when someone (like a parent or supervisor) is nearby.
- Two **nRF24L01 RF modules** for wireless communication between:
  - An **Arduino-based transmitter** (detects motion).
  - An **ESP8266-based receiver** (connected to the PC).
- A **JavaScript program** running on the PC that reads messages from the ESP8266 and connects to:
- **AutoHotkey (AHK)**, which automates a tab switch (e.g., hides a game or video when someone approaches).

The communication between the transmitter and receiver is handled using the **RF24 library**.

---

## 🛠️ Hardware Used

| Device         | Role           |
|----------------|----------------|
| Arduino Uno    | Transmitter with HC-SR04 & nRF24L01 |
| ESP8266        | Receiver with nRF24L01 |
| nRF24L01 (x2)  | RF communication |
| HC-SR04        | Ultrasonic distance sensor |
| PC (Windows)   | Runs JS and AHK for automation |

---

## 🔗 System Architecture

```text
[HC-SR04] ─> [Arduino + nRF24L01] -- RF --> [ESP8266 + nRF24L01] ─> [PC JS] ─> [AutoHotkey]
        Detects                  Transmits     Receives      Passes Signal       Switches Tab
