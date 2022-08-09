#include <Arduino.h>
int led1 = 17; 
int bt1 = 23;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(bt1,INPUT_PULLDOWN); //configuración pull down internamente
}

void loop() {
  if (digitalRead(bt1))
  {
    delay(30);
    if (!digitalRead(bt1))
      {
        int stado = digitalRead(led1);
        digitalWrite(led1,!stado);
      }
  }
}
