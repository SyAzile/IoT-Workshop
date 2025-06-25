#define RED_PIN   27
#define GREEN_PIN 12
#define BLUE_PIN  26

void glow(bool red, bool green, bool blue, int delayTime = 1000) {
  digitalWrite(RED_PIN, red);
  digitalWrite(GREEN_PIN, green);
  digitalWrite(BLUE_PIN, blue);
  delay(delayTime);
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  glow(true, false, false);
  glow(false, true, false);
  glow(false, false, true);
  glow(true, true, true);
  glow(false, false, false);
}