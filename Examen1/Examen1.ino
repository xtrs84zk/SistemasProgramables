int primerLed = 5;
int segundoLed = 6;
int tercerLed = 9;
int cuartoLed = 10;
int quintoLed = 11;

void setup() {
  pinMode(primerLed,OUTPUT);
  pinMode(segundoLed,OUTPUT);
  pinMode(tercerLed,OUTPUT);
  pinMode(cuartoLed,OUTPUT);
  pinMode(quintoLed,OUTPUT);
}

void loop() {
  //a)
  //todos prenden por un segundo y se apagan por un segundo
  digitalWrite(primerLed,HIGH);
  digitalWrite(segundoLed,HIGH);
  digitalWrite(tercerLed,HIGH);
  digitalWrite(cuartoLed,HIGH);
  digitalWrite(quintoLed,HIGH);
  delay(1000);

  digitalWrite(primerLed,LOW);
  digitalWrite(segundoLed,LOW);
  digitalWrite(tercerLed,LOW);
  digitalWrite(cuartoLed,LOW);
  digitalWrite(quintoLed,LOW);
  delay(1000);

  //b)
  //de derecha a izquierda, prenden 5°,3° y 1° x 1seg.
  digitalWrite(quintoLed,HIGH);
  delay(1000);
  digitalWrite(tercerLed,HIGH);
  delay(1000);
  digitalWrite(primerLed,HIGH);
  delay(1000);

  //apaga 1°, 3° y 5° por un segundo
  digitalWrite(primerLed,LOW);
  delay(1000);
  digitalWrite(tercerLed,LOW);
  delay(1000);
  digitalWrite(quintoLed,LOW);
  delay(1000);

  //c)
  //1°,3° y 5° PWM del 0-100% y del 100% al 0°
  for(int i = 0; i<256; i++){
  analogWrite(primerLed,i);
  analogWrite(tercerLed,i);
  analogWrite(quintoLed,i);
  delay(10);
  }
  for(int i = 255; i>0; i--){
    analogWrite(primerLed,i);
  analogWrite(tercerLed,i);
  analogWrite(quintoLed,i);
  delay(10);
  }

  //delay, quizá

  //d)
  //secuencia de izq a derecha x 1/8s 
  digitalWrite(primerLed,HIGH);
  delay(125);
  digitalWrite(segundoLed,HIGH);
  delay(125);
  digitalWrite(tercerLed,HIGH);
  delay(125);
  digitalWrite(cuartoLed,HIGH);
  delay(125);
  digitalWrite(quintoLed,HIGH);
  delay(125);

  //apagar de derecha a izquierda x 1/8s
  digitalWrite(quintoLed,LOW);
  delay(125);
  digitalWrite(cuartoLed,LOW);
  delay(125);
  digitalWrite(tercerLed,LOW);
  delay(125);
  digitalWrite(segundoLed,LOW);
  delay(125);
  digitalWrite(primerLed,LOW);
  delay(125);

  delay(1000);
}
