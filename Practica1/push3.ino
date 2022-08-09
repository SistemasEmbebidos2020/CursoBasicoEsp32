#include <Arduino.h>
int led1 = 17; 
int bt1 = 23;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(bt1,INPUT_PULLUP); //configuración pull up internamente
}

void loop() {
  
  if (digitalRead(bt1)==0)
  {
    digitalWrite(led1,HIGH);
  }
  else digitalWrite(led1,LOW);

}

