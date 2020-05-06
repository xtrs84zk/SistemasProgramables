#include <Servo.h>        //Se incluye la librería
Servo servo;              //Creando objeto servo
int virajeActual = 0;     //Se inicializa el viraje en 180°
int hasBeenChanged = 0;   //variable de control para saber si el viraje ha cambiado en la última iteración
int ServoPin = 6;         //Se establece qué pin utilizará el servomotor
int pinDelLed = 5;        //pin del primer led
int pinDelSegundoLed = 3; //pin del segundo led
//pin número 8 -> pin del botón

void setup()
{
  //Se establece el pin A0 como entrada analógica
  pinMode(A0, INPUT);                //sensor lm35
  pinMode(pinDelSegundoLed, OUTPUT); //establecer el led 2 como salida
  Serial.begin(9600);                //inicializar el puerto serial
  pinMode(ServoPin, OUTPUT);         //Se establece el pin del servomotor como salida
  pinMode(pinDelLed, OUTPUT);        //establecer el led 1 como salida
  pinMode(8, INPUT_PULLUP);          //Se activa la resistencia interna para el push button
  servo.attach(ServoPin);            //Se inicializa el servo
  servo.write(virajeActual);         //Se aplica el viraje definido arriba
  servo.detach();                    //¿Por qué mantendrías alimentado el servo?
}

void loop()
{
  //usando temperatura
  double lectura = 0;
  double voltaje = 0;
  //Se lee desde el arduino[A0]
  lectura = analogRead(A0);
  //Se realizan las conversiones necesarias
  voltaje = (lectura * 5) / 1023;
  double gradosCentigrados = voltaje * 100;
  Serial.print("Temperatura: ");
  Serial.println(gradosCentigrados);
  if (gradosCentigrados > 29.0) //si la temperatura es mayor a 29°, alimentar automáticamente
  {
    servo.attach(ServoPin);             //energizar el servomotor
    analogWrite(pinDelSegundoLed, 255); //encender el led 2
    servo.write(0);                     //girar el servo a alimentar
    delay(2000);                        //esperar 2 segundos
    servo.write(180);                   //regresar el servo a arriba
    delay(200);                         //esperar .2 segundos
    servo.detach();                     //desenergizar el servomotor
    analogWrite(pinDelSegundoLed, 0);   //apagar el led
    delay(1000);                        //esperar un segundo
    while (gradosCentigrados > 29)      //si la temperatura sigue en 29°
    {                                   //hacer que parpadee el led
      for (int i = 0; i < 256; i++)
      {
        analogWrite(pinDelSegundoLed, i);
        delay(2);
      }
      for (int i = 254; i > 1; i--)
      {
        analogWrite(pinDelSegundoLed, i);
        delay(2);
      }
    }
  }
  else
  {
    //usando el botón
    if (digitalRead(8) == LOW)
    {                          //presionado
      servo.attach(ServoPin);  //energizando el servo
      if (hasBeenChanged == 0) //bandera
      {
        if (virajeActual == 180) //si el viraje está en 180, hacerlo 0
        {
          virajeActual = 0;
          digitalWrite(pinDelLed, HIGH);
        }
        else //si el viraje es 0, hacerlo 180
        {
          virajeActual = 180;
        }
        servo.write(virajeActual);    //escribir el viraje al servomotor
        delay(2000);                  //esperar dos segundos
        digitalWrite(pinDelLed, LOW); //apagar el led
        servo.write(180);             //girar el servo a normal
        servo.detach();               //desenergizar el servo
        hasBeenChanged = 1;           //modificar la bandera
      }
    }
    else
    {
      hasBeenChanged = 0;
    }
  }
}