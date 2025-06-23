#define LED_RED 10
#define LED_GREEN 9
#define LED_BLUE 8

void glow(int r, int g, int b) {
  analogWrite(LED_RED, r);
  analogWrite(LED_GREEN, g);
  analogWrite(LED_BLUE, b);
}

void setup() {
  Serial.begin(9600);
  
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    while(Serial.available() < 3)
      delay(10);

    int r = Serial.parseInt();
    int g = Serial.parseInt();
    int b = Serial.parseInt();
      
    Serial.println("R: " + String(r) + ", G: " + String(g) + ", B: " + String(b));
    glow(r, g, b);
  }
}