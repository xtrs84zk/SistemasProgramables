//El botón presionado envía 0V (LOW)
//El botón no presionado envía 5V
//(input-pullup) implica una resistencia "interna" ergo,
//no se necesita una física, esto en el pinMode.
void setup() {
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,INPUT_PULLUP);//se activa la resistencia interna
}

void loop() {
  if(digitalRead(8) == LOW){ //presionado
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  } else {
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
  }

}
