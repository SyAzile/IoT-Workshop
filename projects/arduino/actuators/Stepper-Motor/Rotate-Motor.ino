#include <Stepper.h>
#define REV 2048

// 28BYJ-48 Step Motor
Stepper motor(REV, 8, 9, 10, 11);

void setup() {
  motor.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Clockwise");
  motor.step(REV);
  delay(1000);

  Serial.println("Anti-Clockwise");
  motor.step(-REV);
  delay(500);
}