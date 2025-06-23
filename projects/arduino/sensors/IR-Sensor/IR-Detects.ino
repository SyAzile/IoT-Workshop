#define LED_GREEN 10
#define LED_BLUE 9
#define IR_PIN 2

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(IR_PIN, INPUT);
}

void loop() {
  if(digitalRead(IR_PIN) == LOW){
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, HIGH);
  }
  else {
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_GREEN, HIGH);
  }
  delay(10);
}