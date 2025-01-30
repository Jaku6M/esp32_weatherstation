#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

DHT dht(26, DHT21);

const int ledPin = 2;
void setup() {
  pinMode(ledPin, OUTPUT);

  dht.begin();
  delay(2000);

  Serial.begin(115200);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  digitalWrite(ledPin, HIGH);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C");
  Serial.print(" Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  delay(1000);
  digitalWrite(ledPin, LOW);  
  delay(1000);
}
