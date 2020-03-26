#include <Servo.h>

//Generando objeto Servo
Servo servo;

//mover el servomotor de 0 a 180 pasando por cada grado 
//delay de 25ms

//y de regreso

void setup() {
  int ServoPin = 9;
  pinMode(ServoPin,OUTPUT);
  servo.attach(ServoPin); //Se inicializa el servo
}

void loop() {
    for(int i = 0; i<= 180; i++){
        servo.write(i);
        delay(25);
    }
    for(int i = 179; i>=0; i--){
        servo.write(i);
        delay(25);
    }
}


