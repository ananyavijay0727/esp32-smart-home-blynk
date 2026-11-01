# Blynk Setup

1. Create an account at https://blynk.cloud and open **Developer Zone -> Templates -> New Template**.
2. Name: `Smart Home` (hardware: **ESP32**, connection: **WiFi**).
3. Add datastreams (**Datastreams -> New -> Virtual Pin**):

| Name | Virtual Pin | Type | Range | Default |
|---|---|---|---|---|
| Light | V0 | Integer | 0-1 | 0 |
| Fan | V1 | Integer | 0-1 | 0 |
| WiFi Signal | V2 | Integer | -100 to 0 | 0 |

4. **Web Dashboard:** add two Switch widgets (bound to V0 and V1) and a Gauge or Label for V2.
5. **Mobile Dashboard:** repeat the same widgets in the Blynk app.
6. Save the template, then **Devices -> New Device -> From template**.
7. Copy the generated `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME` and `BLYNK_AUTH_TOKEN` into your local `config.h`.

> Never commit `config.h`. If your auth token is ever exposed, regenerate it in the device settings.
