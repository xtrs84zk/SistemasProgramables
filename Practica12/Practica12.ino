//Sensor de temperatura más leds
void setup() {
  //Se establece el pin A0 como entrada analógica
  pinMode(A0,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //Se declaran variables para la lectura, el voltaje y temperatura en C°
  double lectura = 0;
  double voltaje = 0;
  //Se lee desde el arduino[A0]
  lectura = analogRead(A0);
  //Se realizan las conversiones necesarias
  voltaje = (lectura*5)/1023; 
  double gradosCentigrados = voltaje*100;
  double gradosFarenheit = (gradosCentigrados * 9/5) + 32;
  //Se muestra la temperatura.
  Serial.print("Temperatura: ");
  Serial.print(gradosCentigrados);
  Serial.print("C°");
  Serial.print(" o bien, ");
  Serial.print(gradosFarenheit);
  Serial.println("F°");


  //encender un led si la temperatura es menor a 15
  if(gradosCentigrados<15.0){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  } //el otro entre 15 y 25
  if(gradosCentigrados>= 15.0 && gradosCentigrados<25.0){
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  }//finalmente, si es mayor a 25 un tercer led
  if(gradosCentigrados>=25.0){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
  }
  delay(1000);
}
