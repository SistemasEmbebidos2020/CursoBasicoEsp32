#include <Arduino.h>
int obst = 4;
int p = 0;
int pin7seg[7] = {17, 15, 18, 19, 21, 22, 23}; // a,b,c,d,e,f,g
/*
      a           ──
    f   b        |  |
      g           ──
    e   c        |  |
      d           ──    //ascii 196
*/
int segAC[10][7] = {
    // 7seg anodo comun
    {0, 0, 0, 0, 0, 0, 1}, // 0
    {1, 0, 0, 1, 1, 1, 1}, // 1
    {0, 0, 1, 0, 0, 1, 0}, // 2
    {0, 0, 0, 0, 1, 1, 0}, // 3
    {1, 0, 0, 1, 1, 0, 0}, // 4
    {0, 1, 0, 0, 1, 0, 0}, // 5
    {1, 1, 0, 0, 0, 0, 0}, // 6
    {0, 0, 0, 1, 1, 1, 1}, // 7
    {0, 0, 0, 0, 0, 0, 0}, // 8
    {0, 0, 0, 1, 1, 0, 0}  // 9
};

int segCC[10][7] = {
    // 7seg catodo comun
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {0, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 0, 0, 1, 1}  // 9
};

void setup()
{
  for (int i = 0; i < 7; i++)
  {
    pinMode(pin7seg[i], OUTPUT);
  }
  pinMode(obst, INPUT);
  for (int j = 0; j < 7; j++)
      {
        digitalWrite(pin7seg[j], segAC[0][j]);
      }
}

void loop()
{
  if (!(digitalRead(obst)))
  {
    delay(25);
    if ((digitalRead(obst)))
    {
      if (p < 9)
        p++;
      else
        p = 0;
      for (int j = 0; j < 7; j++)
      {
        digitalWrite(pin7seg[j], segAC[p][j]);
      }
    }
  }
}
