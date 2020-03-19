#include <Servo.h>

//Generando objeto Servo
Servo servo;
int virajeActual = 180;
int hasBeenChanged = 0;

void setup() {
  int ServoPin = 6;
  pinMode(ServoPin,OUTPUT);
  //Se inicializa el servo
  servo.attach(ServoPin);
  pinMode(8,INPUT_PULLUP);//se activa la resistencia interna para el push button
}

void loop() {
  if(digitalRead(8) == LOW){ //presionado
    if(hasBeenChanged == 0){
      if(virajeActual == 180){
        virajeActual = 0;
        delay(200);
      } else {
        virajeActual = 180;
        delay(200);
      }
    hasBeenChanged = 1;
    }
  } else {
    hasBeenChanged = 0;
  }
  servo.write(virajeActual);
}
