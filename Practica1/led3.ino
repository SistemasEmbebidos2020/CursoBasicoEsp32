#include <Arduino.h>
int leds [4] = {13,14,15,16};

void setup() {
  for (int i = 0; i < 4; i++)
  {
  pinMode(leds[i],OUTPUT);
  }
  
}

void loop() {
  for (int i = 0; i < 4; i++)
  {
  digitalWrite(leds[i],HIGH);
  delay(1000);
  digitalWrite(leds[i],LOW);
  delay(1000);
  }
}
