#define LED_PIN 10

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println("Enter '1' to turn LED ON or '0' to turn LED OFF:");
}

void loop() {
  int data;
  while(Serial.available() > 0){
    data = Serial.read();
    if(data == '1'){
      digitalWrite(LED_PIN, HIGH);
      Serial.println("ON");
    }
    else if(data == '0'){
      digitalWrite(LED_PIN, LOW);
      Serial.println("OFF");
    }
  }
}