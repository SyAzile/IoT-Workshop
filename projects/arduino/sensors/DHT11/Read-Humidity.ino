#include <dht.h>
#define DHT_PIN 8   

dht DHT;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int chk = DHT.read11(DHT_PIN);
  Serial.println("Humidity: " + String(DHT.humidity) + "%"); 
  delay(2000);
}