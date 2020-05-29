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

    char codigo;
    String valor = "";

    while (Serial.available() > 0)
    { // Preguntamos si existe datos leidos por serial
        String linea = Serial.readString();
        for (int i = 0; i < linea.length(); i++)
        {
            int caracter = linea[i];
            if (isDigit(caracter))
            {                            // Preguntamos si es digito
                valor += (char)caracter; // Guardamos el valor leido
            }
            else if (caracter != '\n')
            {                      // Preguntamos si es distinto a salto de linea
                codigo = caracter; // Guardamos el codigo leido
            }
            else
            {
                break;
            }
        }
    }
    Serial.println(codigo);
    delay(10);
    switch (codigo)
    
    {
    case 'A':
        avanzar();
        break;
    case 'I':
        izquierda();
        break;
    case 'R':
        retroceder();
        break;
    case 'D':
        derecha();
        break;
    case 'S':
        parar();
        break;
    case 'Y':
        sentientMode();
        break;
    case 't':
        parar();
        break;
    }

    delay(10);
}

void avanzar()
{
    digitalWrite(13, LOW);
    //carro hacia delante
    //avanza llanta izquierda
    digitalWrite(izquierdaA, HIGH);
    digitalWrite(izquierdaB, LOW);
    //avanza llanta derecha
    digitalWrite(derechaA, HIGH);
    digitalWrite(derechaB, LOW);
}

void retroceder()
{
    digitalWrite(13, LOW);
    //carro hacia atrás
    //retrocede llanta izquierda
    digitalWrite(izquierdaA, LOW);
    digitalWrite(izquierdaB, HIGH);
    //retrocede llanta derecha
    digitalWrite(derechaA, LOW);
    digitalWrite(derechaB, HIGH);
}

void parar()
{
    digitalWrite(13, LOW);
    //carro detenido
    //detiene llanta izquierda
    digitalWrite(izquierdaA, LOW);
    digitalWrite(izquierdaB, LOW);
    //detiene llanta derecha
    digitalWrite(derechaA, LOW);
    digitalWrite(derechaB, LOW);
}

void izquierda()
{
    digitalWrite(13, LOW);
    //carro hacia la derecha
    //avanza llanta izquierda
    digitalWrite(izquierdaA, LOW);
    digitalWrite(izquierdaB, HIGH);
    //retrocede llanta derecha
    digitalWrite(derechaA, HIGH);
    digitalWrite(derechaB, LOW);
}

void derecha()
{
    digitalWrite(13, LOW);
    //carro hacia la derecha
    //avanza llanta izquierda
    digitalWrite(izquierdaA, HIGH);
    digitalWrite(izquierdaB, LOW);
    //retrocede llanta derecha
    digitalWrite(derechaA, LOW);
    digitalWrite(derechaB, HIGH);
}

void sentientMode()
{
    //carro automático
    digitalWrite(13, HIGH);
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
