# ⚡ AI-Enabled IoT Smart Energy Meter

> ### An ESP32-powered smart energy meter with live LCD and Blynk monitoring—built as a foundation for predictive energy analytics.

**⚡ Measure electrical parameters &nbsp;|&nbsp; 📱 Monitor remotely &nbsp;|&nbsp; 📊 Build toward energy forecasting**

![Live ESP32 energy-meter prototype with LCD and Blynk dashboard](assets/images/live-prototype.jpeg)

*Live prototype: ESP32, 16×2 LCD, connected load, and Blynk dashboard displaying Voltage, Current, Power, and Unit.*

## ✨ Key Features

- **ESP32-based sensing** for voltage and current measurements
- **Three live interfaces:** LCD, Serial Monitor, and Blynk dashboard
- **Remote monitoring** of Voltage, Current, Power, and cumulative Energy Unit
- **EEPROM-backed storage** to preserve accumulated energy after restart
- **Data-first AI roadmap:** calibrated logging followed by next-day energy forecasting
## Hardware
| Component | Purpose |
| --- | --- |
| ESP32 | Controller, Wi-Fi connectivity, and analog acquisition |
| ACS712 | Current sensing |
| ZMPT101B | Isolated AC voltage sensing |
| 16x2 I2C LCD | Local display |
| Blynk Cloud | Remote dashboard |

For complete component descriptions, connections, safety guidance, and the measurement relationship, see [Hardware documentation](hardware/README.md).

## 💻 Software and IoT

The ESP32 firmware is developed in Arduino IDE and uses the ESP32 Board Package, ACS712, ZMPT101B, LiquidCrystal_I2C, Blynk, WiFi, and EEPROM libraries. The Blynk dashboard receives Voltage (`V0`), Current (`V1`), Power (`V2`), and Energy Unit (`V3`).

See the detailed [Software and IoT documentation](software/README.md) for installation, Blynk pin mapping, and safe firmware setup.
## System architecture
```text
AC load → ACS712 + ZMPT101B → ESP32 → LCD / Serial Monitor / Blynk Dashboard
```
## Project status
| Capability | Status |
| --- | --- |
| ESP32 sensor acquisition | Demonstrated |
| LCD and Serial Monitor output | Demonstrated |
| Blynk dashboard | Demonstrated |
| Energy calibration | In progress |
| Timestamped data logging and forecasting | Planned |
## Important measurement note
Energy integration must use elapsed time: `energy_kWh += power_W × elapsed_seconds / 3,600,000`.

Before using logged values for analysis, compare voltage, current, and energy against a trusted reference meter across several loads. This educational prototype is not a certified billing meter.
## Safety
This project involves mains-related sensing. Do not use a breadboard, jumper wires, or exposed terminals as a permanent AC installation. Use suitable isolation, fusing, enclosure, strain relief, and qualified supervision. The ESP32 must receive only low-voltage sensor outputs.
## Reports
- [Prototype research report](output/pdf/Smart_Energy_Meter_Prototype_Research_Report.pdf)
- [Research paper](AI_Enabled_IoT_Smart_Energy_Meter_Research_Paper.docx)
## Team
Shayna Singh · Rupali Patel · Bhavya Sharma  
VIT Bhopal University
