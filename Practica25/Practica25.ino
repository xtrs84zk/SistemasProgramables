int estado = 0;
void setup()
{
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    //Función para verificar si hay datos en el puerto serial
    if (Serial.available() > 0)
    {
        estado = Serial.read(); //se leen los datos que llegan al puerto serial
    }
    Serial.println(estado);
    delay(1000);

    if(estado == 'a'){
        //auto hacia adelante
        digitalWrite(2,HIGH);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
    } 
    if(estado == 'b'){
        //carro hacia la izquierda
        digitalWrite(2,LOW);
        digitalWrite(3,HIGH);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
    }
    if(estado == 'c'){
        //botón de en medio -> detener el auto
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
    }
    if(estado == 'd'){
        //carro hacia la derecha
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
    }
    if(estado == 'e'){
        //carro hacia atrás (?)
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
    }
    if(estado == 'f'){
        //carro automático
        //usar el sensor ultrasónico
    }
    if(estado == 'g'){
        //detener auto
    }
}