#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ACS712.h>
#include <ZMPT101B.h>
#include <EEPROM.h>
#include "secrets.h"

// Install the ACS712 and ZMPT101B libraries before compiling.
// Copy secrets.example.h to secrets.h, then set the credentials locally.
ACS712 ACS(34, 3.3, 4095, 125);
ZMPT101B voltageSensor(35, 50.0);
LiquidCrystal_I2C lcd(0x27, 16, 2);
BlynkTimer timer;

constexpr size_t EEPROM_SIZE = 512;
constexpr int UNIT_ADDRESS = 0;
constexpr int VALID_ADDRESS = 8;
constexpr uint8_t EEPROM_VALID_MARKER = 0xA5;

float unitKWh = 0.0F;
unsigned long lastMeasurementMs = 0;

void saveEnergy() {
  EEPROM.writeFloat(UNIT_ADDRESS, unitKWh);
  EEPROM.write(VALID_ADDRESS, EEPROM_VALID_MARKER);
  EEPROM.commit();
}

void showReadings(int voltage, int currentMilliamp, int powerW) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.print(voltage);
  lcd.print(" C:");
  lcd.print(currentMilliamp);
  lcd.print("mA");
  lcd.setCursor(0, 1);
  lcd.print("P:");
  lcd.print(powerW);
  lcd.print("W U:");
  lcd.print(unitKWh, 2);
}

void measureAndPublish() {
  const unsigned long now = millis();
  const float elapsedSeconds = (now - lastMeasurementMs) / 1000.0F;
  lastMeasurementMs = now;

  const int noiseMilliamp = ACS.getNoisemV();
  float averageMilliamp = 0.0F;
  for (int i = 0; i < 100; i++) {
    averageMilliamp += ACS.mA_AC();
  }
  averageMilliamp = (averageMilliamp / 100.0F) - noiseMilliamp;
  const int currentMilliamp = averageMilliamp > 5.0F ? static_cast<int>(averageMilliamp) : 0;

  const float measuredVoltage = voltageSensor.getRmsVoltage();
  const int voltage = measuredVoltage > 50.0F ? static_cast<int>(measuredVoltage) : 0;
  const float powerW = voltage * (currentMilliamp / 1000.0F);
  const int displayedPowerW = static_cast<int>(powerW);

  // Correct time-based integration: W × seconds / 3,600,000 = kWh.
  unitKWh += powerW * elapsedSeconds / 3600000.0F;
  saveEnergy();

  showReadings(voltage, currentMilliamp, displayedPowerW);
  Serial.printf("Voltage: %d V | Current: %d mA | Power: %d W | Energy: %.6f kWh\n", voltage, currentMilliamp, displayedPowerW, unitKWh);

  Blynk.virtualWrite(V0, voltage);
  Blynk.virtualWrite(V1, currentMilliamp);
  Blynk.virtualWrite(V2, displayedPowerW);
  Blynk.virtualWrite(V3, unitKWh);
}

void setup() {
  Serial.begin(115200);
  EEPROM.begin(EEPROM_SIZE);
  if (EEPROM.read(VALID_ADDRESS) == EEPROM_VALID_MARKER) {
    unitKWh = EEPROM.readFloat(UNIT_ADDRESS);
  }

  ACS.autoMidPoint();
  voltageSensor.setSensitivity(500.0F);
  lcd.init();
  lcd.backlight();
  lcd.print("Energy Meter");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  lastMeasurementMs = millis();
  timer.setInterval(500L, measureAndPublish);
}

void loop() {
  Blynk.run();
  timer.run();
}
