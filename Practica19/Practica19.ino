#include <Servo.h>

//Generando objeto Servo
Servo servo;

void setup() {
  int ServoPin = 6;
  pinMode(ServoPin,OUTPUT);
  //Se inicializa el servo
  servo.attach(ServoPin);
}

void loop() {
  int gradosADondeGirar = 0;
  servo.write(gradosADondeGirar);
  delay(1000);
  gradosADondeGirar = 180;
  servo.write(gradosADondeGirar);
  delay(500);
  //desenergizar el servo
  //servo.detach();
  delay(500);
}
