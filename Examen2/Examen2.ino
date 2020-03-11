#include <DHT.h>
#define DHTPIN 8
#define DHTTYPE DHT11

float gradosCelsiusDHT11 = 0;
DHT dht(DHTPIN,DHTTYPE); //objeto DHT
void setup() {
  Serial.begin(9600);
  dht.begin(); //inicializamos el sensor

  //se inicializan los led
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  //Leer la temperatura desde el DHT11
  gradosCelsiusDHT11 = dht.readTemperature(); //celsius

  
  //se asegura de la lectura
  if(isnan(gradosCelsiusDHT11)){
    Serial.println("Error de lectura de datos");
    return;
  } else { //en caso de recibir información limpia, se imprime
    
  Serial.println("");
  Serial.print("La temperatura según el sensor DHT11 es: ");
  Serial.print(gradosCelsiusDHT11);

  if(gradosCelsiusDHT11 < 18.3){
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
  }
  if(gradosCelsiusDHT11 >= 18.3 && gradosCelsiusDHT11 < 25){
    //pwm
    for(int i = 0; i<255; i++){
      analogWrite(5,i);
      analogWrite(6,i);
      analogWrite(9,i);
      analogWrite(10,i);
      delay(10);
    }
    for(int i = 255; i>1; i--){
      analogWrite(5,i);
      analogWrite(6,i);
      analogWrite(9,i);
      analogWrite(10,i);
      delay(10);
    }
  } 
  if(gradosCelsiusDHT11 >= 25) {
    //secuencia
    digitalWrite(5,HIGH);
    delay(300);
    digitalWrite(6,HIGH);
    delay(300);
    digitalWrite(9,HIGH);
    delay(300);
    digitalWrite(10,HIGH);
    delay(300);

    digitalWrite(10,LOW);
    delay(300);
    digitalWrite(9,LOW);
    delay(300);
    digitalWrite(6,LOW);
    delay(300);
    digitalWrite(5,LOW);
    delay(300);
  }
  }
}
