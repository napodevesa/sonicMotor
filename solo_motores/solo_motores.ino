
const int in1 = 10, in2 = 9; // Pines asignados al primer motor
const int in3 = 8, in4 = 7;  // Pines asignados al segundo motor

void setup() {
  Serial.begin(9600); // Configuracion del puerto serial de comunicacion
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT); // Configuracion de salida de los pines del primer motor
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT); // Configuracion de salida de los pines del segundo motor
  
  Serial.println("Tenemos los siguientes comandos:"); // Mensaje inicial
  Serial.println("Letra a: Rotacion del primer motor en sentido horario");
  Serial.println("Letra b: Rotacion del primer motor en sentido antihorario");
  Serial.println("Letra c: Rotacion del segundo motor en sentido horario");
  Serial.println("Letra d: Rotacion del segundo motor en sentido antihorario");
  Serial.println("Letra e: Detener motores");
}

void loop() {
  if (Serial.available()) { // Verificaion que el puerto serial recibe datos                                  
   delay(10);                                              
   rotacion_motor(); // Rutina rotacion de motor                        
    while (Serial.available() > 0){Serial.read();} // Rutina de limpieza del buffer del puerto serial
  }
}

void rotacion_motor(){          // RUTINA DE PRUEBA DE MOTORES DC

                                // RUTINA DE ROTACION 1
  if (Serial.peek() == 'a'){ // Discriminacion de la letra correspondiente a la primera rutina
    Serial.println("Motor 1: Rotancion horaria"); // Indicacion por pantalla de la rotacion  
    digitalWrite(in1, HIGH); digitalWrite(in2, LOW); // Activacion del motor 1 en sentido horario
    digitalWrite(in3, LOW); digitalWrite(in4, LOW);  // Desactivacion del motor 2  
  }

                                // RUTINA DE ROTACION 2
  if (Serial.peek() == 'b'){ // Discriminacion de la letra correspondiente a la segunda rutina
    Serial.println("Motor 1: Rotancion antihoraria"); // Indicacion por pantalla de la rotacion    
    digitalWrite(in1, LOW); digitalWrite(in2, HIGH); // Activacion del motor 1 en sentido horario
    digitalWrite(in3, LOW); digitalWrite(in4, LOW);  // Desactivacion del motor 2  
  }

                                // RUTINA DE ROTACION 3
  if (Serial.peek() == 'c'){ // Discriminacion de la letra correspondiente a la tercera rutina 
    Serial.println("Motor 2: Rotancion horaria"); // Indicacion por pantalla de la rotacion    
    digitalWrite(in3, HIGH); digitalWrite(in4, LOW); // Activacion del motor 1 en sentido horario
    digitalWrite(in1, LOW); digitalWrite(in2, LOW);  // Desactivacion del motor 2  
  }

                                // RUTINA DE ROTACION 4
  if (Serial.peek() == 'd'){ // Discriminacion de la letra correspondiente a la cuarta rutina  
    Serial.println("Motor 2: Rotancion antihoraria"); // Indicacion por pantalla de la rotacion    
    digitalWrite(in3, LOW); digitalWrite(in4, HIGH); // Activacion del motor 1 en sentido horario
    digitalWrite(in1, LOW); digitalWrite(in2, LOW);  // Desactivacion del motor 2  
  }
                                // RUTINA DE ROTACION 5
  if (Serial.peek() == 'e'){ // Discriminacion de la letra correspondiente a la quinta rutina 
    Serial.println("Detener motores"); // Indicacion por pantalla de la rotacion    
    digitalWrite(in1, LOW); digitalWrite(in2, LOW); // Activacion del motor 1 en sentido horario
    digitalWrite(in3, LOW); digitalWrite(in4, LOW);  // Desactivacion del motor 2  
  }  
}
