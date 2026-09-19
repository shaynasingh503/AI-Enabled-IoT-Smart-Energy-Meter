# 🔧 Hardware Components

This project uses low-cost modules to measure electrical parameters, display readings locally, and publish them through Wi-Fi. The prototype is intended for learning and demonstration; it is not a certified billing meter.

## Hardware at a glance

| Component | Role in the project |
| --- | --- |
| ESP32 Development Board | Main controller, analog acquisition, Wi-Fi, and data processing |
| ZMPT101B | Isolated AC voltage-sensor module |
| ACS712 | Hall-effect current-sensor module |
| 16×2 I2C LCD | Local display for live readings |
| AC socket and load | Demonstrates the electrical load being monitored |

## 1. ESP32 Development Board

The ESP32 is the central controller. It reads the analog sensor outputs, calculates estimated electrical values, updates the LCD, stores cumulative energy in EEPROM, and connects to Blynk over Wi-Fi.

**Why it is used**

- Built-in 2.4 GHz Wi-Fi for IoT monitoring
- ADC-capable GPIO pins for the sensor outputs
- I2C support for the LCD
- EEPROM emulation for persistent energy storage
- Compatible with Arduino IDE and widely available libraries

**Project interfaces**

| ESP32 interface | Connected item | Purpose |
| --- | --- | --- |
| GPIO 34 (ADC) | ACS712 output | Current-related analog signal |
| GPIO 35 (ADC) | ZMPT101B output | Voltage-related analog signal |
| I2C SDA/SCL | 16×2 LCD | Local display communication |
| Wi-Fi | Blynk Cloud | Remote dashboard updates |

See [ESP32 details](ESP32.md) for the original board documentation.

## 2. ZMPT101B AC Voltage Sensor

The ZMPT101B module provides an isolated low-voltage signal related to the AC supply voltage. The ESP32 reads this output and firmware calculates an estimated RMS voltage.

**Role in this project**

- Supplies the voltage input used for estimated power calculation
- Helps show live voltage on the LCD, Serial Monitor, and Blynk dashboard
- Requires sensitivity calibration using a trusted reference meter

**Important:** Never connect AC mains directly to an ESP32 pin. Verify the module wiring, isolation, and calibration before testing.

## 3. ACS712 Current Sensor

The ACS712 is a Hall-effect current sensor. Current flowing through the monitored load path produces a measurable analog output, which the ESP32 samples using GPIO 34.

**Role in this project**

- Provides current measurements for the connected load
- Enables estimated power calculation together with voltage
- Requires midpoint/noise handling and calibration for reliable results

The firmware performs an ACS712 midpoint setup at startup and averages readings to reduce noise.

## 4. 16×2 I2C LCD

The 16×2 LCD gives immediate local feedback without requiring a phone or Internet connection. It displays voltage, current, power, and accumulated energy information.

**Why I2C is useful**

- Uses only two communication lines in addition to power and ground
- Keeps the wiring cleaner than a parallel LCD connection
- Is supported by the `LiquidCrystal_I2C` Arduino library

The typical configured I2C address in this project is `0x27`. Confirm your LCD address if no text appears.

## 5. AC Socket and Load

The AC socket and connected load form the demonstration load path. They make it possible to observe changing voltage, current, and estimated power values in a real test setup.

**Safety requirements**

- Do not use a breadboard or loose jumper wires as a permanent mains installation.
- Use suitable insulation, terminals, fusing, strain relief, and an enclosure.
- Test only under qualified supervision.
- Treat prototype readings as educational until calibrated against a trusted meter.

## Measurement relationship

```text
Voltage sensor output ─┐
                       ├── ESP32 ── LCD / Serial Monitor / Blynk
Current sensor output ─┘

Estimated Power (W) = Voltage (V) × Current (A)
Energy (kWh) = accumulated Power × elapsed time
```
