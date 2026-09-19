# ZMPT101B AC Voltage Sensor

## Overview

The ZMPT101B module is used to obtain a low-voltage signal related to the AC supply voltage. The ESP32 reads the sensor output and firmware calculates an estimated RMS voltage.

## Role in this project

- Supplies the voltage input for the energy-meter measurements
- Shows estimated voltage on the LCD, Serial Monitor, and Blynk dashboard
- Provides the voltage value used with current to estimate power

## Connection to ESP32

| ZMPT101B pin | ESP32 connection | Purpose |
| --- | --- | --- |
| VCC | 3.3 V | Module supply |
| GND | GND | Common low-voltage reference |
| OUT | GPIO 35 | Analog voltage-sensor output |

## Software use

The firmware uses the ZMPT101B library and configures sensor sensitivity before taking RMS-voltage readings.

```cpp
ZMPT101B voltageSensor(35, 50.0);
voltageSensor.setSensitivity(500.0F);
```

## Calibration and safety

Compare the displayed voltage with a trusted reference meter and adjust sensitivity as needed. Never connect AC mains directly to an ESP32 pin. Use appropriate isolation, enclosure, and qualified supervision during mains-related testing.
