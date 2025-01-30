#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <LiquidCrystal.h>

DHT dht(26, DHT21);
LiquidCrystal lcd(22,21,5,18,23,19);

const int ledPin = 2;
void setup() {

  lcd.begin(16,2);
  lcd.clear();

  dht.begin();
  delay(2000);
  Serial.begin(115200);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
  lcd.print(humidity);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}
