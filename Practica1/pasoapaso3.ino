#include <Arduino.h>
int led1 = 17;
int led2 = 5;
int led3 = 18;
int led4 = 19;
float t = 3.5;
int pasos = 0;

int grados = 90;
int npasos = grados*512/360;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  
}

void loop() {

while(pasos <= npasos){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  delay(t);
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
  delay(t);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  delay(t);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,HIGH);
  delay(t);
  pasos++;
}
 
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);

 
}