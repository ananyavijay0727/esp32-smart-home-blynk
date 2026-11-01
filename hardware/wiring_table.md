# Wiring

Update the GPIO numbers if you used different pins (they must match `smart_home.ino`).

## Low-voltage side (ESP32 <-> relay module)

| ESP32 pin | Relay module pin | Notes |
|---|---|---|
| GPIO 26 | IN1 | Light channel |
| GPIO 27 | IN2 | Fan channel |
| 5V / VIN | VCC | Relay module supply |
| GND | GND | Common ground |

## Relay outputs (appliance side)

| Relay channel | Appliance | Blynk virtual pin |
|---|---|---|
| CH1 | Light | V0 |
| CH2 | Fan | V1 |

Each appliance's live wire goes through the relay's **COM** and **NO** (normally open) terminals, so the appliance is OFF when the relay is not energised.

## Safety
- This circuit switches **mains AC voltage**. Disconnect power before wiring.
- Use an insulated enclosure and keep mains wiring physically separate from the low-voltage side.
- Fuse the live line.
