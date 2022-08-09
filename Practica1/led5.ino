#include <Arduino.h>
int pins[3] = {17,5,18}; 
/*
 17-blue
 5-green
 18-red
*/
int secuencia[4][3]={  
  {0,0,0},  
  {0,0,1},  
  {0,1,0},    
  {1,0,0}
};

void setup() {
  int sizepins = sizeof(pins) / sizeof(int);
  for (int i = 0; i < sizepins; i++)
  {
  pinMode(pins[i],OUTPUT);
  }
}

void loop() {
for (int i = 0; i < 4; i++)
{
  for (int j = 0; j < 3; j++)
  {
    digitalWrite(pins[j],secuencia[i][j]);
  }
  delay(1000);
}

}
