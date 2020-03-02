#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11

float gradosC = 0;
float humedad = 0;
float gradosF = 0;
DHT dht(DHTPIN,DHTTYPE); //objeto DHT
void setup() {
  Serial.begin(9600);
  dht.begin(); //inicializamos el sensor

}

void loop() {
  gradosC = dht.readTemperature(); //celsius
  humedad = dht.readHumidity(); //humedad
  gradosF = dht.readTemperature(true); //farenheit

  //se asegura de la lectura
  if(isnan(gradosC) || isnan(humedad) || isnan(gradosF)){
    Serial.println("Error de lectura de datos");
    return;
  } else { //en caso de recibir información limpia, se imprime
  Serial.println("");
  Serial.print("La temperatura es: ");
  Serial.print(gradosC);
  Serial.print("C°, o bien, ");
  Serial.print(gradosF);
  Serial.println("F°");
  Serial.print("La humedad está al ");
  Serial.print(humedad);
  Serial.println("%");
  }
  
}
