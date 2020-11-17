/*
 * Autor: NDev /Napoleón Devesa
 * Fecha: 11 noviembre 2020
 * 
 */


#include <Servo.h>        // Include Servo Library
#include <NewPing.h>      // Include Newping Library

// L298N Control Pins
const int LeftMotorForward = 4;
const int LeftMotorBackward = 5;
const int RightMotorForward = 6;
const int RightMotorBackward = 7;


#define TRIGGER_PIN  A1  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A2  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 250 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 250cm.

int pote=A0;   //Potenciómetro
int valorpote;     //Variable que recoge el valor del potenciómetro

int pwm1;          //Variable del PWM 1
int pwm2;          //Variable del PWM 2


Servo servo_motor;  // Servo's name
Servo servo_motor2;  // Servo's name
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

boolean goesForward = false;
int distance = 100;


void setup()
{
  // Set L298N Control Pins as Output
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  servo_motor.attach(10);   // Attachs the servo on pin 9 to servo object.
  servo_motor.write(115);   // Set at 115 degrees. 
  
  servo_motor2.attach(11);   // Attachs the servo on pin 9 to servo object.
  servo_motor.write(115);   // Set at 115 degrees. 
  
  delay(2000);              // Wait for 2s.
  distance = readPing();    // Get Ping Distance.
  delay(100);               // Wait for 100ms.
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
 

}

void loop(){

  valorpote = analogRead(pote);
  pwm1 = map(valorpote, 0, 1023, 0, 255);
  //pwm2 = map(valorpote, 0, 1023, 255, 0); //El PWM 2 esta invertido respecto al PWM 1

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20)
  {
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distanceRight >= distanceLeft)
    {
      turnRight();
      delay(300);
      moveStop();
    }
    else
    {
      turnLeft();
      delay(300);
      moveStop();
    }
  
  }
  else
  {
    moveForward(); 
  }

    distance = readPing();
}

int lookRight()     // Look Right Function for Servo Motor
{  
  servo_motor.write(50);
  delay(500);
  
  servo_motor2.write(0);
  delay(500);
  
  int distance = readPing();
  delay(100);
  
  servo_motor.write(115);
  
   servo_motor2.write(10);
   
  delay(500);
  return distance;
}

int lookLeft()      // Look Left Function for Servo Motor 
{
  servo_motor.write(180);
  
  servo_motor2.write(5);
  delay(500);
  int distance = readPing();
  delay(100);
  
  servo_motor.write(115);
  servo_motor2.write(25);
  return distance;
}

int readPing()      // Read Ping Function for Ultrasonic Sensor.
{
  delay(100);                 // Wait 100ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  int cm = sonar.ping_cm();   //Send ping, get ping distance in centimeters (cm).
  if (cm==0)
  {
    cm=250;
  }
  return cm;
}

void moveStop()       // Move Stop Function for Motor Driver.
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward()    // Move Forward Function for Motor Driver.

{


    analogWrite(RightMotorForward,pwm1);
    digitalWrite(RightMotorBackward, LOW);
    
    analogWrite(LeftMotorForward,pwm1);
    digitalWrite(LeftMotorBackward, LOW);
}

void moveBackward()   // Move Backward Function for Motor Driver.
{
  digitalWrite(RightMotorForward, LOW);
  analogWrite(RightMotorBackward,pwm1);

  digitalWrite(LeftMotorForward, LOW);
   analogWrite(LeftMotorBackward,pwm1);
  
}

void turnRight()      // Turn Right Function for Motor Driver.
{
  digitalWrite(RightMotorForward, LOW);
    analogWrite(RightMotorBackward,pwm1);
  
 analogWrite(LeftMotorForward,pwm1);
  digitalWrite(LeftMotorBackward, LOW);
}

void turnLeft()       // Turn Left Function for Motor Driver.
{
  analogWrite(RightMotorForward,pwm1);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  analogWrite(LeftMotorBackward,pwm1);
}
