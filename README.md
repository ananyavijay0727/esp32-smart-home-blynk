# esp32-smart-home-blynk
IoT smart home automation using ESP32 and Blynk to remotely control lights and fans over Wi-Fi via a smartphone app.
# IoT Smart Home Automation using ESP32 and Blynk

Control home appliances (lights, fans) remotely from a smartphone using an ESP32 over Wi-Fi and the Blynk IoT platform.

![Demo](images/demo.gif)

## Features
- Remote ON/OFF control of 2 appliances (light, fan) through the Blynk mobile app
- Switch states restored automatically when the board reconnects
- Wi-Fi signal strength (RSSI) shown live on the dashboard
- Relays start OFF at boot for safe power-up

## How it works
Phone (Blynk app) -> Blynk Cloud -> Wi-Fi -> ESP32 -> Relay module -> Appliance

![Architecture](docs/architecture.png)

## Hardware
| Component | Qty | Purpose |
|---|---|---|
| ESP32 DevKit | 1 | Wi-Fi microcontroller |
| 2-channel relay module | 1 | Switches AC loads |
| 5V supply | 1 | Powers the board and relays |

Full parts list: [hardware/bom.md](hardware/bom.md) | Pin mapping: [hardware/wiring_table.md](hardware/wiring_table.md)

| ESP32 GPIO | Relay channel | Appliance | Blynk virtual pin |
|---|---|---|---|
| GPIO 26 | IN1 | Light | V0 |
| GPIO 27 | IN2 | Fan | V1 |


## Software
- Arduino IDE with ESP32 board package
- Blynk library
- Language: Embedded C/C++

## Setup
1. Create the Blynk template and datastreams
2. In `firmware/smart_home/`, copy `config.example.h` to `config.h` and fill in your Wi-Fi and Blynk details
3. Open `firmware/smart_home/smart_home.ino` in Arduino IDE, select **ESP32 Dev Module**, and upload
4. Wire the relay module as per the pin table
5. Open the Blynk app and toggle the switches

## Results
- Tested with a light and a fan
- Response time from app tap to relay switch: **[X] seconds** (measured over [Y] trials)


## Safety
This project switches mains voltage. Use an insulated enclosure and proper fusing, and work only with power disconnected.

## Future improvements
- MQTT support and local control without the cloud
- OTA firmware updates
- Energy monitoring with a current sensor
- Voice assistant integration

## Author
Ananya Vijay | ECE, Dayananda Sagar College of Engineering
