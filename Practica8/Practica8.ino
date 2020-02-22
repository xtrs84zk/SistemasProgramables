void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  //a)
  //encender todos derecha -> izquierda 1/2 segundo
  for(int i = 1; i<6; i++ ){
    digitalWrite(i,HIGH);
    delay(500);
  }
  //b)
  //apagar todos izquierda -> derecha 1/4 segundo
  for(int i = 5; i>0; i-- ){
    digitalWrite(i,LOW);
    delay(250);
  }

  //c)
  //encender "1, 3, 5"
  digitalWrite(1,HIGH);
  delay(1000);
  digitalWrite(3,HIGH);
  delay(1000);
  digitalWrite(5,HIGH);
  delay(1000);
    
  //d)
  //apagar 5, 3, 1
  digitalWrite(5,LOW);
  delay(1000);
  digitalWrite(3,LOW);
  delay(1000);
  digitalWrite(1,LOW);
  delay(1000);
}
