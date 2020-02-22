void setup() {
  pinMode(10,OUTPUT);
}

void loop() {
  //Se incrementa la intensidad percibida cada 10ms
  for(int i = 0; i<256; i++){
  analogWrite(10,i);
  delay(10);
  }
}
