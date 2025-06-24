#define IP_PIN A1

void setup() {
  Serial.begin(9600);
}

void loop() {
  int ip = analogRead(IP_PIN);
  float moisture = (100 - (ip / 1023.00) * 100);

  Serial.println("Moisture: " + String(moisture) + "%");
  delay(1000);
}