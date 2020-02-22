int timeOnDelay = 10;
int selectedPin = 5;
void setup() {
  pinMode(selectedPin,OUTPUT);
}

void loop() {
  //Se incrementa la intensidad percibida cada 10ms
  for(int i = 1; i<255; i++){
    analogWrite(selectedPin,i);
    delay(timeOnDelay);
  }
  //Se decrementa la intensidad percibida cada 10ms
  for(int i = 255; i>1; i--){
    analogWrite(selectedPin,i);
    delay(timeOnDelay);
  }
}
