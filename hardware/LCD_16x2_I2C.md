# 16×2 I2C LCD

## Overview

The 16×2 I2C LCD provides a local display for live measurements, so the prototype can be used even when the phone dashboard is not open.

## Values displayed

- Voltage in volts (V)
- Current in milliamps (mA)
- Estimated power in watts (W)
- Accumulated energy in kilowatt-hours (kWh)

## Connection to ESP32

| LCD pin | ESP32 connection | Purpose |
| --- | --- | --- |
| VCC | 3.3 V or module-supported supply | LCD power |
| GND | GND | Common reference |
| SDA | GPIO 21 | I2C data |
| SCL | GPIO 22 | I2C clock |

## Software use

The project uses the `LiquidCrystal_I2C` library. The configured I2C address is `0x27`.

```cpp
LiquidCrystal_I2C lcd(0x27, 16, 2);
lcd.init();
lcd.backlight();
```

If no text appears, scan for the correct I2C address and verify the SDA/SCL wiring.
