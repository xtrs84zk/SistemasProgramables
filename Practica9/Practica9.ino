void setup() {
  pinMode(A0,INPUT);
  //habilita el monitor serial
  //velocidad máxima 11,200
  Serial.begin(9600);
}

void loop() {
  double lectura = 0;
  double voltaje = 0;
  //lectura de 0 a 1023 
  lectura = analogRead(A0);
  //convertir a voltaje
  //lectura = (lectura*5)/1023;
  voltaje = (lectura*5)/1023;
  //Imprimir al monitor
  Serial.print(voltaje);
  Serial.println("v.");
  //tranqui
  delay(1000);
}
