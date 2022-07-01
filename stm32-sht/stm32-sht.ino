#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SHT3x.h>
SHT3x Sensor;

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  Sensor.Begin();
  lcd.init();

  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Weather Station");
  lcd.setCursor(0,1);
  lcd.print("STM32 | SHT31");
  delay(3000);

  lcd.clear();

}

void loop() {
  
  Sensor.UpdateData();

  float t = Sensor.GetTemperature();
  float f = Sensor.GetTemperature(SHT3x::Far);
  float h = Sensor.GetRelHumidity();
  float a = Sensor.GetAbsHumidity();
  
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");

  lcd.setCursor(0,1);
  lcd.print(t);
  lcd.print("C");
  lcd.print(" | ");
  lcd.print(f);
  lcd.print("F");

  delay (3000);

  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("U/R: ");
  lcd.print(h);
  lcd.print("%");

  lcd.setCursor(0,1);
  lcd.print("U/A: ");
  lcd.print(a);
  lcd.print(" Torr");
  
  delay (3000);

  lcd.clear();
}
