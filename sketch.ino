#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

// ========================================
// Smart IoT Motion Security System
// Task 4 - Adafruit IO
// ========================================

// Pins
#define PIR_PIN 27
#define LED_PIN 26
#define BUZZER_PIN 25

// Wokwi WiFi
#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""

// Adafruit IO
#define AIO_SERVER "io.adafruit.com"
#define AIO_SERVERPORT 1883

// Enter your Adafruit IO details
#define AIO_USERNAME "YOUR_USERNAME"
#define AIO_KEY "YOUR_AIO_KEY"

// WiFi client
WiFiClient client;

// MQTT client
Adafruit_MQTT_Client mqtt(
  &client,
  AIO_SERVER,
  AIO_SERVERPORT,
  AIO_USERNAME,
  AIO_KEY
);

// Adafruit IO motion feed
Adafruit_MQTT_Publish motionFeed =
  Adafruit_MQTT_Publish(
    &mqtt,
    AIO_USERNAME "/feeds/motion"
  );

// Variables
int lastMotion = -1;
unsigned long lastPublish = 0;


// ========================================
// Connect to WiFi
// ========================================

void connectWiFi() {

  Serial.print("Connecting to WiFi");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected!");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}


// ========================================
// Connect to Adafruit IO
// ========================================

void connectMQTT() {

  int8_t ret;

  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to Adafruit IO...");

  while ((ret = mqtt.connect()) != 0) {

    Serial.println(mqtt.connectErrorString(ret));

    mqtt.disconnect();

    delay(5000);

    Serial.print("Retrying...");
  }

  Serial.println();
  Serial.println("Connected to Adafruit IO!");
}


// ========================================
// Setup
// ========================================

void setup() {

  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println();
  Serial.println("========================================");
  Serial.println(" Smart IoT Motion Security System");
  Serial.println(" Task 4 - Adafruit IO");
  Serial.println("========================================");

  connectWiFi();
  connectMQTT();
}


// ========================================
// Main Loop
// ========================================

void loop() {

  // Reconnect if MQTT connection is lost
  if (!mqtt.connected()) {
    connectMQTT();
  }

  mqtt.processPackets(10);

  // Read PIR sensor
  int motion = digitalRead(PIR_PIN);


  // ========================================
  // Local Security System
  // ========================================

  if (motion == HIGH) {

    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    Serial.println("Motion Detected!");

  } else {

    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("No Motion");
  }


  // ========================================
  // Send Data to Adafruit IO
  // ========================================

  if (motion != lastMotion ||
      millis() - lastPublish >= 10000) {

    Serial.print("Sending to Adafruit IO: ");
    Serial.println(motion);

    // Explicitly convert to int32_t
    int32_t motionValue = (int32_t)motion;

    if (motionFeed.publish(motionValue)) {

      Serial.println("Data published successfully!");

    } else {

      Serial.println("Failed to publish data!");
    }

    lastMotion = motion;
    lastPublish = millis();
  }

  delay(1000);
}
