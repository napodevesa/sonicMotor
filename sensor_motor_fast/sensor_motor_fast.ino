/*
Author: ndev / Napoleón Devesa
Day: 9 SEP 2020

*/

#include <Servo.h> 

Servo servomotor1;
Servo servomotor2;
const int PinTrig = 2;
const int PinEcho = 3;

// Constante velocidad sonido en cm/s
const float VelSon = 34000.0;
float distancia;


void setup() {
  Serial.begin(9600);
  servomotor1.attach(9);
  servomotor2.attach(8);
  pinMode(PinTrig, OUTPUT);
  pinMode(PinEcho, INPUT);
}

void loop() {
  for(int i=0; i<=180; i+=10){
  
    servomotor1.write(i);
    servomotor2.write(i);
        
        iniciarTrigger();
            unsigned long tiempo = pulseIn(PinEcho, HIGH);
            distancia = tiempo * 0.000001 * VelSon / 2.0;
            Serial.print(distancia);
            Serial.print("cm");
            Serial.println();
            delay(100);
    
    
    delay(100);
    
  }
  for(int i=180; i>=0; i-=10){
    
    servomotor1.write(i);
    servomotor2.write(i);
    
        iniciarTrigger();
            unsigned long tiempo = pulseIn(PinEcho, HIGH);
            distancia = tiempo * 0.000001 * VelSon / 2.0;
            Serial.print(distancia);
            Serial.print("cm");
            Serial.println();
            
    delay(100);
  }
}


void iniciarTrigger()
{
  // Ponemos el Triiger en estado bajo y esperamos 2 ms
  digitalWrite(PinTrig, LOW);
  delayMicroseconds(2);
  
  // Ponemos el pin Trigger a estado alto y esperamos 10 ms
  digitalWrite(PinTrig, HIGH);
  delayMicroseconds(10);
  
  // Comenzamos poniendo el pin Trigger en estado bajo
  digitalWrite(PinTrig, LOW);
}
