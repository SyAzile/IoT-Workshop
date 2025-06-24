#define LED_RED 10
#define LED_GREEN 9
#define LED_BLUE 8
#define IP_PIN A1

int LED_PINS[] = {LED_RED, LED_GREEN, LED_BLUE};

void glow(int pin){
  for(int i = 0; i < 3; i++){
    if(i == pin)
      digitalWrite(LED_PINS[i], HIGH);
    else
      digitalWrite(LED_PINS[i], LOW);
  }

  if(pin == 0)
    Serial.println("Too much moisture!!!");
  else if(pin == 1)
    Serial.println("Perfect");
  else if(pin == 2)
    Serial.println("Very less moisture!!!");
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int ip = analogRead(IP_PIN);
  float moist = (100 - (ip / 1023.00) * 100);

  Serial.println("moist: " + String(moist) + "%");
  if(moist > 50.00)
    glow(0);
  else if(moist < 50.00 && moist > 40.00)
    glow(1);
  else
    glow(2);


  delay(1000);
}