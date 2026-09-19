# 💻 Software and IoT Platform

The software layer reads the sensors, calculates values, displays them locally, stores accumulated energy, and sends live readings to the cloud dashboard.

## Software at a glance

| Tool or library | Purpose |
| --- | --- |
| Arduino IDE | Writes, compiles, and uploads firmware to the ESP32 |
| ESP32 Board Package | Lets Arduino IDE recognize and build for ESP32 boards |
| ACS712 library | Reads and helps calibrate the ACS712 current sensor |
| ZMPT101B library | Obtains RMS voltage from the voltage sensor module |
| LiquidCrystal_I2C library | Controls the 16×2 I2C LCD |
| Blynk IoT Platform | Cloud dashboard for remote monitoring |
| EEPROM library | Stores the accumulated energy value across restarts |

## 1. Arduino IDE

Arduino IDE is the development environment used to write, compile, and upload the ESP32 firmware. It also provides Serial Monitor, which is used to inspect live sensor readings and troubleshooting messages.

**Main tasks in this project**

- Open and edit `firmware/smart_energy_meter.ino`
- Select the correct ESP32 board and serial port
- Install required libraries
- Upload firmware through USB
- View real-time output at `115200` baud in Serial Monitor

## 2. ESP32 Board Package

The ESP32 board package adds the ESP32 compiler, board definitions, and upload support to Arduino IDE.

**Arduino IDE setup**

1. Open **File → Preferences**.
2. Add the Espressif ESP32 board-manager URL in **Additional Boards Manager URLs**.
3. Open **Tools → Board → Boards Manager**.
4. Search for `esp32` and install the package from Espressif Systems.
5. Select the ESP32 board model under **Tools → Board**.

## 3. Arduino Libraries

Install these through **Sketch → Include Library → Manage Libraries** before compiling.

| Library | Use in this project |
| --- | --- |
| Blynk | Connects the ESP32 to the Blynk dashboard and sends values to virtual pins |
| ACS712 | Samples AC current and supports midpoint/noise handling |
| ZMPT101B | Reads RMS voltage from the voltage sensor module |
| LiquidCrystal_I2C | Writes Voltage, Current, Power, and Unit to the LCD |

`WiFi`, `Wire`, and `EEPROM` are provided by the ESP32 Arduino framework.

## 4. Blynk IoT Platform

Blynk is the IoT dashboard used to monitor the project from a phone or browser. The project uses four data points:

| Virtual pin | Dashboard value | Unit |
| --- | --- | --- |
| V0 | Voltage | V |
| V1 | Current | mA |
| V2 | Power | W |
| V3 | Energy Unit | kWh |

Create gauges or value-display widgets in Blynk and connect each widget to the matching virtual pin. Configure the display ranges to match your expected prototype values.

## 5. Firmware setup

The safe firmware is available at [`firmware/smart_energy_meter.ino`](../firmware/smart_energy_meter.ino).

1. Copy [`firmware/secrets.example.h`](../firmware/secrets.example.h) to `firmware/secrets.h`.
2. Add your Blynk template ID, device token, Wi-Fi name, and Wi-Fi password to `secrets.h`.
3. Keep `secrets.h` private; it is ignored by Git and must never be uploaded.
4. Upload the sketch to the ESP32.
5. Open Serial Monitor at `115200` baud and verify readings before relying on the dashboard.

## Data flow

```text
Sensors → ESP32 firmware → LCD / Serial Monitor → Wi-Fi → Blynk dashboard
```

## Future software work

- Log timestamped calibrated readings to CSV or a database
- Add daily and weekly energy summaries
- Compare a basic forecast baseline with a simple ML model
- Display forecast-versus-actual energy use
