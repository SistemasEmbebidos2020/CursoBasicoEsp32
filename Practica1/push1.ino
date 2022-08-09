#include <Arduino.h>
int led1 = 17; 
int bt1 = 23;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(bt1,INPUT);
}

void loop() {
  //configuración pull down externamente
  if (digitalRead(bt1)==1)
  {
    digitalWrite(led1,HIGH);
  }
  else digitalWrite(led1,LOW);

}
