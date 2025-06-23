#include <dht.h>

#define LED_RED 10
#define LED_GREEN 9
#define LED_BLUE 8
#define DHT_PIN 2

dht DHT;

int LED_PINS[] = {LED_RED, LED_GREEN, LED_BLUE};

void glow(int pin){
  for(int i = 0; i < 3; i++){
    if(i == pin)
      digitalWrite(LED_PINS[i], HIGH);
    else
      digitalWrite(LED_PINS[i], LOW);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
}

void loop() {
  int chk = DHT.read11(DHT_PIN);
  float tmp = DHT.temperature, humid = DHT.humidity;

  Serial.println("Temperature: " + String(tmp) + "°C" + " Humidity: " + String(humid) + "%");

  if(tmp > 30.0)
    glow(0);
  else if (tmp < 30.0 && tmp > 25.0)
    glow(1);
  else
    glow(2);

  delay(2000);
}