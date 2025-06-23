#define LED_RED 10
#define LED_GREEN 9
#define LED_BLUE 8

int pins[] = {LED_RED, LED_GREEN, LED_BLUE};

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

void loop() {
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 256; j++){
      analogWrite(pins[i], j);
      delay(20);
    }

    for(int j = 255; j >= 0; j--){
      analogWrite(pins[i], j);
      delay(20);
    }
  }
}