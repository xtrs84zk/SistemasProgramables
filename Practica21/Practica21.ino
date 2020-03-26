#include <Servo.h>            //Se incluye la librería
Servo servo;                  //Creando objeto servo
int virajeActual = 180;       //Se inicializa el riaje en 180°
int hasBeenChanged = 0;       //variable de control para saber si el viraje ha cambiado en la última iteración

void setup() {
  int ServoPin = 6;           //Se establece qué pin utilizará el servomotor
  pinMode(ServoPin,OUTPUT);   //Se establece el pin del servomotor como salida
  pinMode(8,INPUT_PULLUP);    //Se activa la resistencia interna para el push button
  servo.attach(ServoPin);     //Se inicializa el servo
  servo.write(virajeActual);  //Se aplica el viraje definido arriba
  servo.detach();             //¿Por qué mantendrías alimentado el servo?
}

void loop() {
  if(digitalRead(8) == LOW){  //el botón está presionado
  servo.attach(ServoPin);     //si se presiona el botón, se energiza el servo
    if(hasBeenChanged == 0){  //¿el viraje cambió en la última iteración?
      if(virajeActual == 180){//si el viraje actual es 180
        virajeActual = 0;     //orientarlo a 0
        delay(200);           //evitar que se lea varias veces un sólo clic
      } else {                //la otra orientación posible en este código
        virajeActual = 180;   //se establece a 180
        delay(200);           //evitar que se lea varias veces un sólo clic
      }
    hasBeenChanged = 1;       //se establece que la orientación cambió ésta iteración
    }
    servo.write(virajeActual); //se aplica el viraje definido arriba
    servo.detach();             //por qué mantendrías alimentado el servo?
  } else {                    //el botón no está presionado
    hasBeenChanged = 0;       //se establece que no hubo cambios esta iteración
  }
}
