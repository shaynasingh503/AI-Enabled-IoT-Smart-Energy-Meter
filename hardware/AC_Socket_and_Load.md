# AC Socket and Load

## Overview

The AC socket and connected load create the demonstration circuit being monitored by the energy meter. The load causes current to flow through the sensing path, allowing voltage, current, power, and energy values to be observed.

## Role in this project

- Provides a real electrical load for prototype testing
- Makes live readings visible on the LCD, Serial Monitor, and Blynk dashboard
- Supports calibration tests against a trusted reference meter

## Safety requirements

- Do not treat a breadboard or loose jumper wires as a permanent mains installation.
- Use insulated terminals, appropriate fusing, strain relief, and a protective enclosure.
- Ensure connections are checked and supervised by a qualified person.
- Keep the ESP32 connected only to low-voltage sensor outputs.
- Do not use the prototype for electricity billing or other safety-critical decisions.

## Testing guidance

Begin with a known, simple load. Compare the displayed voltage, current, power, and energy total with a trusted meter. Record the error at multiple loads before using the readings for data analysis.
