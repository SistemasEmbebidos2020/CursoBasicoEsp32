#include <Arduino.h>

int leds[]={17,5,18,19};  //A1 A2 B1 B2

void izquierda(){  
  digitalWrite(leds[0],HIGH);
  digitalWrite(leds[1],LOW);
  digitalWrite(leds[2],LOW);
  digitalWrite(leds[3],LOW);
}
void derecha(){  
  digitalWrite(leds[0],LOW);
  digitalWrite(leds[1],LOW);
  digitalWrite(leds[2],HIGH);
  digitalWrite(leds[3],LOW);
}

void adelante(){  
  digitalWrite(leds[0],HIGH);
  digitalWrite(leds[1],LOW);
  digitalWrite(leds[2],HIGH);
  digitalWrite(leds[3],LOW);
}

void atras(){  
  digitalWrite(leds[0],LOW);
  digitalWrite(leds[1],HIGH);
  digitalWrite(leds[2],LOW);
  digitalWrite(leds[3],HIGH);
}

void stop(){  
  digitalWrite(leds[0],LOW);
  digitalWrite(leds[1],LOW);
  digitalWrite(leds[2],LOW);
  digitalWrite(leds[3],LOW);
}
void setup() {
  for (int i = 0; i < 4; i++)
  {
  pinMode(leds[i],OUTPUT);
  } 
}

void loop() {
  izquierda();
  delay(2000);
  derecha();
  delay(2000);
  adelante();
  delay(3000);  
  stop();
  delay(500);  
  atras();
  delay(3000);
  stop();
  delay(5000);
}
