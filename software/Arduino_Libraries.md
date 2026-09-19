# Arduino Libraries

## Overview

Libraries provide the firmware functions needed to communicate with the sensors, LCD, EEPROM, Wi-Fi, and Blynk dashboard.

## Required libraries

| Library | Role in the project |
| --- | --- |
| Blynk | Sends readings from the ESP32 to the Blynk dashboard |
| ACS712 | Reads AC current and supports midpoint/noise handling |
| ZMPT101B | Obtains RMS voltage from the voltage sensor module |
| LiquidCrystal_I2C | Controls the 16×2 I2C LCD |

`WiFi`, `Wire`, and `EEPROM` are provided by the ESP32 Arduino framework.

## Installation

In Arduino IDE, open **Sketch → Include Library → Manage Libraries**. Search for and install each required library before compiling the firmware.

## Firmware include files

```cpp
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal_I2C.h>
#include <ACS712.h>
#include <ZMPT101B.h>
#include <EEPROM.h>
```
