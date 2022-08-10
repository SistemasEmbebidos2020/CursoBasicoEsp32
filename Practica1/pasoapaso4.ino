#include <Arduino.h>

float t = 3.5;
int pasos = 0;
int grados = 270;
int npasos = grados*512/360;

int leds[]={17,5,18,19};
int motorpasos[4][4]={
  {1,0,0,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,0,0,1}
};
void setup() {
  for (int i = 0; i < 4; i++)
  {
  pinMode(leds[i],OUTPUT);
  } 
}

void loop() {
while(pasos <= npasos){
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      digitalWrite(leds[j],motorpasos[i][j]);
    }
    delay(t);
  }
  pasos++;
}
 
for (int i = 0; i < 4; i++)
{
  digitalWrite(leds[i],LOW);
} 
}
