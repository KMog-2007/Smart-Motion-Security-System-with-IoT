# Smart Motion Security System with IoT

## Task 4 – IoT Cloud Integration and Live Dashboard

---

## Project Overview

This project is a Smart Motion Security System developed using an ESP32 in the Wokwi simulator and connected to the Adafruit IO cloud platform.

The system uses a PIR motion sensor to detect movement. When motion is detected, the ESP32 activates an LED and buzzer. The motion status is also sent to Adafruit IO through Wi-Fi using MQTT and displayed on a real-time web dashboard.

---

## Objective

- Detect motion using a PIR motion sensor
- Activate an LED and buzzer when motion is detected
- Connect the ESP32 to Wi-Fi
- Send sensor readings to an IoT cloud platform
- Display real-time sensor readings on a web dashboard
- Understand basic MQTT communication in IoT applications

---

## Components Used

- ESP32
- PIR Motion Sensor
- LED
- 220Ω Resistor
- Buzzer
- Wokwi Simulator
- Adafruit IO

---

## Pin Connections

| Component | ESP32 Pin |
|-----------|-----------|
| PIR Sensor OUT | GPIO 27 |
| LED | GPIO 26 |
| Buzzer | GPIO 25 |

---

## IoT Cloud Platform

**Adafruit IO** is used as the cloud IoT platform.

A feed named `motion` is used to receive the PIR sensor readings.

### Feed Values

- `0` → No Motion
- `1` → Motion Detected

---

## Software and Tools

- Wokwi Simulator
- Arduino/C++
- Adafruit MQTT Library
- Adafruit IO
- Wi-Fi
- MQTT

---

## Working

1. The PIR sensor detects movement in the surrounding area.
2. The ESP32 reads the output of the PIR sensor.
3. When motion is detected, the LED turns ON.
4. The buzzer is activated as an alert.
5. When no motion is detected, the LED and buzzer remain OFF.
6. The ESP32 connects to the Wokwi Wi-Fi network.
7. The ESP32 sends the motion status to the Adafruit IO `motion` feed using MQTT.
8. Adafruit IO receives the sensor data through the cloud.
9. The received data is displayed on the online dashboard.
10. The dashboard provides a motion status indicator and graph for monitoring the readings.

---

## System Flow

PIR Motion Sensor
        ↓
      ESP32
        ↓
 Motion Detection
     ↙      ↘
   LED      Buzzer
        ↓
      Wi-Fi
        ↓
   Adafruit IO
        ↓
   Motion Feed
        ↓
 Web Dashboard
        ↓
Live Motion Status + Graph

---

## Dashboard

The Adafruit IO dashboard contains:

- Motion Status Indicator
- Motion Data Graph
- Real-time motion readings

The dashboard allows the motion status of the security system to be monitored remotely through the web.

---

## Result

The Smart Motion Security System was successfully connected to the Adafruit IO cloud platform.

The ESP32 successfully published PIR sensor readings to the `motion` feed. The sensor data was received by Adafruit IO and displayed on the online dashboard.

The system successfully demonstrates real-time IoT monitoring using an ESP32, PIR sensor, Wi-Fi, MQTT, and Adafruit IO.

---

## Project Structure

Smart-Motion-Security-System-IoT/
│
├── sketch.ino
├── diagram.json
├── libraries.txt
├── README.md
│
└── screenshots/
    ├── wokwi.png
    ├── adafruit-feed.png
    └── dashboard.png

---

## File Description

| File | Description |
|------|-------------|
| `sketch.ino` | ESP32 program for motion detection and Adafruit IO communication |
| `diagram.json` | Wokwi circuit configuration |
| `libraries.txt` | Required library information |
| `README.md` | Project documentation |
| `screenshots/` | Project, feed, and dashboard screenshots |

---

## Security Note

The Adafruit IO AIO Key is a private credential.

The actual AIO Key should not be uploaded to GitHub or shared publicly.

The GitHub version of the code should use placeholder credentials instead of the real AIO Key.

Example:

#define AIO_USERNAME "YOUR_USERNAME"
#define AIO_KEY "YOUR_AIO_KEY"

---

## Platform

This project was developed and tested using:

- Wokwi ESP32 Simulator
- Adafruit IO Cloud Platform

---

## Conclusion

This project demonstrates how a basic motion security system can be connected to an IoT cloud platform.

By combining an ESP32, PIR motion sensor, Wi-Fi, MQTT, and Adafruit IO, motion data can be detected, transmitted to the cloud, and monitored through a web dashboard in real time.

---

## Author

**K Moganaa**

Electronic Communication Student

Sathyabama Institute of Science and Technology
