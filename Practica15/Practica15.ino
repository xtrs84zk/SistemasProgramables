#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11

float gradosCelsius = 0;
float humedad = 0;
float gradosF = 0;
DHT dht(DHTPIN,DHTTYPE); //objeto DHT
void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  dht.begin(); //inicializamos el sensor

}

void loop() {
  gradosCelsius = dht.readTemperature(); //celsius
  humedad = dht.readHumidity(); //humedad
  gradosF = dht.readTemperature(true); //farenheit

  //se asegura de la lectura
  if(isnan(gradosCelsius) || isnan(humedad) || isnan(gradosF)){
    Serial.println("Error de lectura de datos");
    return;
  } else { //en caso de recibir información limpia, se imprime
  Serial.println("");
  Serial.print("La temperatura es: ");
  Serial.print(gradosCelsius);
  Serial.print("C°, o bien, ");
  Serial.print(gradosF);
  Serial.println("F°");
  Serial.print("La humedad está al ");
  Serial.print(humedad);
  Serial.println("%");
  }

  //encender un led si la temperatura es 18 -> 21
  if(gradosCelsius>=18.0 && gradosCelsius <21){
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  } //el otro entre 15 y 25
  if(gradosCelsius>= 21.0 && gradosCelsius<28.0){
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  }//finalmente, si es mayor a 25 un tercer led
  if(gradosCelsius>=28.0){
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
  }
}
