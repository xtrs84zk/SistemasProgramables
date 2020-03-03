#include <DHT.h>
#define DHTPIN 8
#define DHTTYPE DHT11
#define LM35PIN A0

float gradosCelsiusDHT11 = 0;
float promedio = 0;
DHT dht(DHTPIN,DHTTYPE); //objeto DHT
void setup() {
  pinMode(LM35PIN,INPUT);
  Serial.begin(9600);
  dht.begin(); //inicializamos el sensor

}

void loop() {
  //Leer la temperatura desde el DHT11
  gradosCelsiusDHT11 = dht.readTemperature(); //celsius

  //Se declaran variables para la lectura, el voltaje y temperatura en C°
  float lectura = 0;
  float voltaje = 0;
  //Se lee desde el pin de temperatura
  lectura = analogRead(LM35PIN);
  //Se realizan las conversiones necesarias
  voltaje = (lectura*5)/1023; 
  float gradosCelsiusLMK35 = voltaje*100;

  
  //se asegura de la lectura
  if(isnan(gradosCelsiusDHT11)){
    Serial.println("Error de lectura de datos");
    return;
  } else { //en caso de recibir información limpia, se imprime
   promedio = (gradosCelsiusLMK35 + gradosCelsiusDHT11)/2;
  
  Serial.println("");
  Serial.print("La temperatura según el sensor DHT11 es: ");
  Serial.print(gradosCelsiusDHT11);
  Serial.print("C°, mientras que en el LMK35 es: ");
  Serial.print(gradosCelsiusLMK35);
  Serial.println("C°");
  Serial.print("Además, el promedio es: ");
  Serial.println(promedio);
  delay(3000);
  }
}
