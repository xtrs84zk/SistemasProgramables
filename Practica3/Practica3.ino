int t = 125;
void setup() {
   //Establecemos todos los pin a utilizar como puertos de salida
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  // se enciende el 2 aparte para no confundir al ciclo
  digitalWrite(2,HIGH);
    delay(t);
    digitalWrite(2,LOW);
    delay(t);

    // se encienden durante un cuarto de segundo y luego al revés
  for(int i = 3; i<7; i++){
    digitalWrite(i,HIGH);
    delay(t);
    digitalWrite(i,LOW);
    delay(t);
  }
  for(int i = 5; i>2; i--){
    digitalWrite(i,HIGH);
    delay(t);
    digitalWrite(i,LOW);
    delay(t);
  }

}
