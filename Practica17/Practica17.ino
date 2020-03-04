void setup() {
  pinMode(8,OUTPUT);

}

void loop() {
  //Mantener encendido 10 segundos
  digitalWrite(8,LOW);
  delay(10000);
  //Mantener apagado 5 segundos
  digitalWrite(8,HIGH);
  delay(5000);
}
