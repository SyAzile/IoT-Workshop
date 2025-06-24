#include <Stepper.h>

#define STEPS_PER_REV 2048
#define RPM 10

#define IR_PIN 3

// 28BYJ-48 → Step Motor
// ULN2003  → Step Motor Driver
// +        → 5V
// -        → GND
// IN1      → Pin 8
// IN2      → Pin 10
// IN3      → Pin 9
// IN4      → Pin 11

Stepper motor(STEPS_PER_REV, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  motor.setSpeed(RPM);
  pinMode(IR_PIN, INPUT);  
}

void loop() {
  int STEPS = STEPS_PER_REV / 4;

  if (digitalRead(IR_PIN) == LOW) {
    Serial.println("Closing Gate...");
    motor.step(STEPS);
    
    Serial.println("Please Wait!");
    delay(10000);
    
    Serial.println("Opening Gate...");
    motor.step(-STEPS);
  } 
  else
    Serial.println("Waiting for Someone!");
}