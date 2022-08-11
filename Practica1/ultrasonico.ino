#include <Arduino.h>

int pins[]={16,4,17,5,18,19};  //A1 A2 B1 B2
#define TRIGGER 4
#define ECHO 16
#define BUZZER 19
#define LEDAZUL 17
#define LEDVERDE 5
#define LEDROJO 18

const float sonido = 34300.0; // Velocidad del sonido en cm/s
const float umbral1 = 30.0;
const float umbral2 = 20.0;
const float umbral3 = 10.0;

// Método que inicia la secuencia del Trigger para comenzar a medir
void iniciarTrigger()
{
  // Ponemos el Triiger en estado bajo y esperamos 2 ms
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
 
  // Ponemos el pin Trigger a estado alto y esperamos 10 ms
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
 
  // Comenzamos poniendo el pin Trigger en estado bajo
  digitalWrite(TRIGGER, LOW);
}

float calcularDistancia()
{
  // La función pulseIn obtiene el tiempo que tarda en cambiar entre estados, en este caso a HIGH
  unsigned long tiempo = pulseIn(ECHO, HIGH);
 
  // Obtenemos la distancia en cm, hay que convertir el tiempo en segudos ya que está en microsegundos
  // por eso se multiplica por 0.000001
  float distancia = tiempo * 0.000001 * sonido / 2.0;
 
  return distancia;
}

void alertas(float distancia)
{
  if (distancia < umbral1 && distancia >= umbral2)
  {
    // Encendemos el LED verde
    digitalWrite(LEDVERDE, HIGH);
  }
  else if (distancia < umbral2 && distancia > umbral3)
  {
    // Encendemos el LED amarillo
    digitalWrite(LEDAZUL, HIGH);
  }
  else if (distancia <= umbral3)
  {
    // Encendemos el LED rojo
    digitalWrite(LEDROJO, HIGH);

  }
}
void apagarLEDs()
{
  // Apagamos todos los LEDs
  digitalWrite(LEDVERDE, LOW);
  digitalWrite(LEDAZUL, LOW);
  digitalWrite(LEDROJO, LOW);
}
void setup() {
  for (int i = 1; i < 6; i++)
  {
  pinMode(pins[i],OUTPUT);
  } 
  pinMode(ECHO,INPUT);
}

void loop() {

  // Preparamos el sensor de ultrasonidos
  iniciarTrigger();
 
  // Obtenemos la distancia
  float distancia = calcularDistancia();
  digitalWrite(BUZZER, LOW);
  apagarLEDs();
  // Lanzamos alerta si estamos dentro del rango de peligro
  if (distancia < umbral1)
  {
    // Lanzamos alertas
    digitalWrite(BUZZER, HIGH);
    alertas(distancia);
  }
 
}
