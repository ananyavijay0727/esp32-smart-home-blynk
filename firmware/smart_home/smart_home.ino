/*
 * IoT Smart Home Automation using ESP32 and Blynk
 * ------------------------------------------------
 * Controls two relay channels (light, fan) from the Blynk mobile app
 * over Wi-Fi, and reports Wi-Fi signal strength back to the dashboard.
 *
 * Blynk datastreams (Virtual Pins):
 *   V0 -> Light switch   (Integer, 0/1)
 *   V1 -> Fan switch     (Integer, 0/1)
 *   V2 -> Wi-Fi RSSI     (Integer, dBm, read-only)
 *
 * Setup: copy config.example.h to config.h and fill in your credentials.
 * Libraries: Blynk (by Volodymyr Shymanskyy), ESP32 board package.
 *
 * NOTE: adjust the GPIO numbers below to match YOUR wiring.
 */

#include "config.h"          // credentials (must define BLYNK_* before the includes below)

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ---------- Pin configuration (change to match your circuit) ----------
const int RELAY_LIGHT_PIN = 26;
const int RELAY_FAN_PIN   = 27;

// Most 5V relay modules are ACTIVE-LOW (LOW = relay ON).
// Set to false if your module switches ON with a HIGH signal.
const bool RELAY_ACTIVE_LOW = true;

// ---------- Virtual pins ----------
#define VPIN_LIGHT 0
#define VPIN_FAN   1
#define VPIN_RSSI  2

BlynkTimer timer;

// Drive a relay, taking the module's active level into account
void setRelay(int pin, bool on) {
  bool level = RELAY_ACTIVE_LOW ? !on : on;
  digitalWrite(pin, level ? HIGH : LOW);
}

// Called when the Light switch changes in the app
BLYNK_WRITE(VPIN_LIGHT) {
  bool state = param.asInt();
  setRelay(RELAY_LIGHT_PIN, state);
  Serial.printf("Light -> %s\n", state ? "ON" : "OFF");
}

// Called when the Fan switch changes in the app
BLYNK_WRITE(VPIN_FAN) {
  bool state = param.asInt();
  setRelay(RELAY_FAN_PIN, state);
  Serial.printf("Fan -> %s\n", state ? "ON" : "OFF");
}

// Runs every time the board (re)connects to Blynk:
// restore the last switch states saved on the server
BLYNK_CONNECTED() {
  Blynk.syncVirtual(VPIN_LIGHT, VPIN_FAN);
}

// Send Wi-Fi signal strength to the dashboard
void sendStatus() {
  Blynk.virtualWrite(VPIN_RSSI, WiFi.RSSI());
}

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_LIGHT_PIN, OUTPUT);
  pinMode(RELAY_FAN_PIN, OUTPUT);

  // Start with everything OFF
  setRelay(RELAY_LIGHT_PIN, false);
  setRelay(RELAY_FAN_PIN, false);

  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASS);

  timer.setInterval(5000L, sendStatus);   // every 5 seconds
}

void loop() {
  Blynk.run();
  timer.run();
}
