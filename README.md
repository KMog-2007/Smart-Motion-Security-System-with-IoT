# Smart Motion Security System with IoT

## Task 4 – IoT Cloud Integration and Live Dashboard

This project is an IoT-based Smart Motion Security System developed using an ESP32 in the Wokwi simulator and connected to the Adafruit IO cloud platform.

The system detects motion using a PIR sensor. When motion is detected, the ESP32 activates an LED and buzzer. At the same time, the motion status is sent to Adafruit IO through Wi-Fi using MQTT and displayed on a real-time web dashboard.

## Objective

- Detect motion using a PIR sensor
- Activate an LED and buzzer when motion is detected
- Connect the ESP32 to Wi-Fi
- Send sensor readings to an IoT cloud platform
- Display real-time motion data on an online dashboard
- Understand basic MQTT-based IoT communication

## Components Used

- ESP32
- PIR Motion Sensor
- LED
- 220Ω Resistor
- Buzzer
- Wokwi Simulator
- Adafruit IO

## Pin Connections

| Component | ESP32 Pin |
|---|---|
| PIR Sensor OUT | GPIO 27 |
| LED | GPIO 26 |
| Buzzer | GPIO 25 |

## IoT Cloud Platform

**Adafruit IO** was used as the cloud IoT platform.

A feed named `motion` was created to receive the sensor readings.

### Feed Values

- `0` → No Motion
- `1` → Motion Detected

## Software and Tools

- Wokwi Simulator
- Arduino/C++
- Adafruit MQTT Library
- Adafruit IO
- Wi-Fi
- MQTT

## Working

1. The PIR sensor detects movement in the surrounding area.
2. The ESP32 reads the output of the PIR sensor.
3. When motion is detected, the LED turns ON.
4. The buzzer is activated as an alert.
5. When no motion is detected, the LED and buzzer remain OFF.
6. The ESP32 connects to the Wokwi Wi-Fi network.
7. The motion status is published to the Adafruit IO `motion` feed using MQTT.
8. Adafruit IO receives the sensor data.
9. The data is displayed on the online dashboard using a status indicator and graph.

## System Flow

```text
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
Live Motion Status
     + Graph
