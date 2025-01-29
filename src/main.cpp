#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

DHT dht(26, DHT21);

const int ledPin = 2;
void setup() {
  pinMode(ledPin, OUTPUT);

  dht.begin();
  delay(2000);

  Serial1.begin(9600);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  digitalWrite(ledPin, HIGH);
  Serial1.print("Temperature: ");
  Serial1.print(temperature);
  Serial1.print("°C");
  Serial1.print(" Humidity: ");
  Serial1.print(humidity);
  Serial1.println("%");
  delay(1000);
  digitalWrite(ledPin, LOW);  
  delay(1000);
}
