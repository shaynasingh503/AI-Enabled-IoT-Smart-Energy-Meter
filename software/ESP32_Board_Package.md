# ESP32 Board Package

## Overview

The ESP32 Board Package enables Arduino IDE to compile and upload programs for ESP32 development boards. It provides the board definitions, compiler tools, Wi-Fi support, and core libraries used by the project.

## Installation steps

1. Open **Arduino IDE → File → Preferences**.
2. Add the Espressif ESP32 board-manager URL under **Additional Boards Manager URLs**.
3. Open **Tools → Board → Boards Manager**.
4. Search for `esp32`.
5. Install the package published by **Espressif Systems**.
6. Select the ESP32 model that matches the board used in the project.

## Why it is required

- Adds ESP32 board support to Arduino IDE
- Enables Wi-Fi, EEPROM, I2C, and GPIO functionality
- Provides the compiler and uploader for the ESP32
