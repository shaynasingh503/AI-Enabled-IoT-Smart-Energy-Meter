# Blynk IoT Platform

## Overview

Blynk is the cloud platform used to monitor the energy meter remotely from a phone or browser. The ESP32 sends live readings through Wi-Fi to dashboard widgets.

## Dashboard data mapping

| Virtual pin | Value | Unit |
| --- | --- | --- |
| V0 | Voltage | V |
| V1 | Current | mA |
| V2 | Power | W |
| V3 | Energy Unit | kWh |

Create gauges or value-display widgets in Blynk and attach each one to the matching virtual pin.

## Secure configuration

The Blynk device token and Wi-Fi credentials are stored only in a private local file named `firmware/secrets.h`. Start by copying [`firmware/secrets.example.h`](../firmware/secrets.example.h), then add your own values locally.

Never commit or upload `secrets.h`, Blynk tokens, or Wi-Fi passwords.

## Data flow

```text
Sensors → ESP32 → Wi-Fi → Blynk Cloud → Mobile dashboard
```
