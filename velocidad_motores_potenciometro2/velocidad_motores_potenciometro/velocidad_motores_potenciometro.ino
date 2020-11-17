

int IN3 = 5; 
int IN4 = 4;
int IN2 = 10; 
int IN1 = 9;

int pote=A0;   //Potenciómetro
int valorpote;     //Variable que recoge el valor del potenciómetro

int pwm1;          //Variable del PWM 1
int pwm2;          //Variable del PWM 2

void setup()
{
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  
  pinMode (IN2, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN1, OUTPUT);    // Input3 conectada al pin 5
}
void loop()
{

   //Almacenamos el valor del potenciómetro en la variable
  valorpote=analogRead(pote);
  
  pwm1 = map(valorpote, 0, 1023, 0, 255);
  pwm2 = map(valorpote, 0, 1023, 255, 0); //El PWM 2 esta invertido respecto al PWM 1

  //Sacamos el PWM de las dos salidas usando analogWrite(pin,valor)
  analogWrite(IN3,pwm1);
  analogWrite(IN4,pwm2);
  
analogWrite(IN1,pwm1);
  analogWrite(IN2,pwm2);
  /*
  // Motor gira en un sentido
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); 
  delay(4000);
  // Motor no gira
  digitalWrite (IN4, LOW); 
  delay(500);
  // Motor gira en sentido inverso
  digitalWrite (IN3, HIGH);
  delay(4000);
  // Motor no gira
  digitalWrite (IN3, LOW); 
  delay(5000);
  */
}
