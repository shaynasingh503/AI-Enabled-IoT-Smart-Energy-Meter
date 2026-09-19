# Arduino IDE

## Overview

Arduino IDE is the software used to write, compile, and upload the ESP32 firmware for this project. It also includes Serial Monitor for checking live readings and troubleshooting the prototype.

## Use in this project

- Open and edit the smart energy meter firmware
- Select the ESP32 board and USB serial port
- Install project libraries
- Compile and upload the firmware
- View live values through Serial Monitor at `115200` baud

## Basic workflow

1. Open `firmware/smart_energy_meter.ino`.
2. Select the connected ESP32 board under **Tools → Board**.
3. Select the correct port under **Tools → Port**.
4. Install the required libraries.
5. Click **Upload**.
6. Open Serial Monitor and select `115200` baud.
