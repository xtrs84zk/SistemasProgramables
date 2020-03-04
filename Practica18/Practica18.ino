#include <DHT.h>
#define DHTPIN 9
#define DHTTYPE DHT11

float gradosCelsiusDHT11 = 0;
DHT dht(DHTPIN,DHTTYPE); //objeto DHT

void setup() {
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
  dht.begin(); //inicializamos el sensor
}

void loop() {

  //Leer la temperatura desde el DHT11
  gradosCelsiusDHT11 = dht.readTemperature(); //celsius

   //se asegura de la lectura
  if(isnan(gradosCelsiusDHT11)){
    Serial.println("Error de lectura de datos");
    return;
  } else { //en caso de recibir información limpia, 
    if(gradosCelsiusDHT11<20.0){ //se enciende sólo el led #1
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(8,HIGH);
    }
    if(gradosCelsiusDHT11>= 20 && gradosCelsiusDHT11<25){ //se enciende sólo el led #2
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(8,HIGH);
    }
    if(gradosCelsiusDHT11>=25){ //se enciende sólo el foco
      digitalWrite(8,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
    }
    Serial.println("");
  Serial.print("La temperatura según el sensor DHT11 es: ");
  Serial.print(gradosCelsiusDHT11);
Serial.println("C°");
  }
}
