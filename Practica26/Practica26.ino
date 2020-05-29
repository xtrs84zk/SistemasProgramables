int estado = 0;

//conectores que van al sensor ultrasónico
int pin_Trig = 3;
int pin_Echo = 2;
double duracion = 0;
double tiempo = 0;
double distancia = 0;

//conectores que van al puente H
int izquierdaA = 9;
int izquierdaB = 8;
int derechaA = 7;
int derechaB = 6;

void setup()
{
    pinMode(pin_Trig, OUTPUT);
    pinMode(pin_Echo, INPUT);
    pinMode(izquierdaA, OUTPUT);
    pinMode(izquierdaB, OUTPUT);
    pinMode(derechaA, OUTPUT);
    pinMode(derechaB, OUTPUT);
    pinMode(13, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    //Función para verificar si hay datos en el puerto serial
    if (Serial.available() > 0)
    {
        estado = Serial.read(); //se leen los datos que llegan al puerto serial
    }else {
      //carro hacia la derecha
        digitalWrite(izquierdaA, LOW);
        digitalWrite(izquierdaB, LOW);
        digitalWrite(derechaA, HIGH);
        digitalWrite(derechaB, LOW);
    }
    if (estado == 'a')
    {
        //auto hacia adelante
        digitalWrite(izquierdaA, HIGH);
        digitalWrite(izquierdaB, LOW);
        digitalWrite(derechaA, HIGH);
        digitalWrite(derechaB, LOW);
    }
    if (estado == 'b')
    {
        //carro hacia la izquierda
        digitalWrite(izquierdaA, HIGH);
        digitalWrite(izquierdaB, LOW);
        digitalWrite(derechaA, LOW);
        digitalWrite(derechaB, LOW);
    }
    if (estado == 'c')
    {
        //botón de en medio -> detener el auto
        digitalWrite(izquierdaA, LOW);
        digitalWrite(izquierdaB, LOW);
        digitalWrite(derechaA, LOW);
        digitalWrite(derechaB, LOW);
    }
    if (estado == 'd')
    {
        //carro hacia la derecha
        digitalWrite(izquierdaA, LOW);
        digitalWrite(izquierdaB, LOW);
        digitalWrite(derechaA, HIGH);
        digitalWrite(derechaB, LOW);
    }
    if (estado == 'e')
    {
        //carro hacia atrás (?)
        digitalWrite(izquierdaA, LOW);
        digitalWrite(izquierdaB, HIGH);
        digitalWrite(derechaA, LOW);
        digitalWrite(derechaB, HIGH);
    }
    if (estado == 'f')
    {
        digitalWrite(13, HIGH);
        //carro automático
        //usar el sensor ultrasónico
        digitalWrite(pin_Trig, HIGH);
        delay(0.01);
        digitalWrite(pin_Trig, LOW);

        //regresa el tiempo que pasa entre que detecta un HIGH y un LOW
        duracion = pulseIn(pin_Echo, HIGH);
        tiempo = duracion / 2;
        distancia = 0.03432 * tiempo;

        if (distancia >= 2 && distancia <= 15)
        {
            digitalWrite(izquierdaA, LOW);
            digitalWrite(izquierdaB, LOW);
            digitalWrite(derechaA, LOW);
            digitalWrite(derechaB, LOW);
            delay(200);

            //reversa durante 500ms
            digitalWrite(izquierdaA, LOW);
            digitalWrite(izquierdaB, HIGH);
            digitalWrite(derechaA, LOW);
            digitalWrite(derechaB, HIGH);
            delay(100);

            //girar durante 600ms
            digitalWrite(izquierdaA, HIGH);
            digitalWrite(izquierdaB, LOW);
            digitalWrite(derechaA, LOW);
            digitalWrite(derechaB, LOW);
            delay(600);
        }
        else
        {
            //el auto se mueve libremente hacia el frente
            digitalWrite(izquierdaA, HIGH);
            digitalWrite(izquierdaB, LOW);
            digitalWrite(derechaA, HIGH);
            digitalWrite(derechaB, LOW);
        }
    }
    if (estado == 'g')
    {
        //detener auto
        digitalWrite(izquierdaA, LOW);
        digitalWrite(izquierdaB, LOW);
        digitalWrite(derechaA, LOW);
        digitalWrite(derechaB, LOW);
    }
}
