void setup() {
  pinMode(10,OUTPUT);
}

void loop() {
  //on at 100%
  analogWrite(10,255);
  delay(500);
  //on at 50
  analogWrite(10,127);
  delay(500);
  //on at 20
  analogWrite(10,51);
  delay(500);
  //on at 5%
  analogWrite(10,13);
  delay(500);

  
//  for(int i = 0; i<256; i++){
//  analogWrite(10,i);
//  delay(40);
//  }

}
