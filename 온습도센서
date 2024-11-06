#include <DHT.h>
DHT dht(12, DHT11);

void setup() {
  Serial.begin(9600);
}
void loop() {
  delay(3000);
  int tem = dht.reedTemperature();
  int hum = dht.reedHumidity();
  Serial.print("Temperature : ");
  Serial.print(tem);
  Serial.print("C ");
  Serial.print("Humidity : ");
  Serial.print(hum);
  Serial.print("% ");
  
}
