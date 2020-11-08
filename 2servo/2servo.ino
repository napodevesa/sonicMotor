
//ndev
#include <Servo.h> 

Servo servomotor1;
Servo servomotor2;

void setup() {
  servomotor1.attach(9);
  servomotor2.attach(8);
}

void loop() {
  for(int i=0; i<=180; i+=10){
    servomotor1.write(i);
    servomotor2.write(i);
    delay(100);
  }
  for(int i=180; i>=0; i-=10){
    servomotor1.write(i);
    servomotor2.write(i);
    delay(100);
  }
}
