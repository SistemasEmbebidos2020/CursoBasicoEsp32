#include <Arduino.h>

int bt1 = 23;
int cnt=1;
int pins[3] = {17,5,18}; 
/*
 17-blue
 5-green
 18-red
*/
int secuencia1[4][3]={  
  {0,0,0},  
  {0,0,1},  
  {0,1,0},    
  {1,0,0}
};

int secuencia2[4][3]={  
  {0,0,0},  
  {0,1,1},  
  {1,1,0},    
  {1,0,1}
};

int secuencia3[4][3]={  
  {0,0,0},  
  {1,0,1},  
  {0,1,1},    
  {1,1,0}
};

void setup() {
  int sizepins = sizeof(pins) / sizeof(int);
  for (int i = 0; i < sizepins; i++)
  {
  pinMode(pins[i],OUTPUT);
  }
  pinMode(bt1,INPUT_PULLDOWN); //configuración pull down internamente
}


void loop() {
  while (digitalRead(bt1))
  {
    delay(30);
    if (!digitalRead(bt1))
      {
        if (cnt < 3)
        cnt ++;
        else 
        cnt = 1;
      }
  }
  switch (cnt)
  {
  case 1:
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        digitalWrite(pins[j],secuencia1[i][j]);
      }
      delay(1000);
    }
    break;

  case 2:
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        digitalWrite(pins[j],secuencia2[i][j]);
      }
      delay(1000);
    }
    break;

  case 3:
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        digitalWrite(pins[j],secuencia3[i][j]);
      }
      delay(1000);
    }
    break;

  default:
    break;
  }
}
