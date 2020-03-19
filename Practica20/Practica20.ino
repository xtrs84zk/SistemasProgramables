/** El botón presionado envía 0V (LOW)
El botón no presionado envía 5V
(input-pullup) implica una resistencia "interna" ergo,
no se necesita una física, esto en el pinMode.
**/
void setup() {
  //establecer los pin a utilizar como salida para los led
  pinMode(6,OUTPUT); //led izquierdo
  pinMode(7,OUTPUT); //led derecho
  pinMode(8,INPUT_PULLUP);//se activa la resistencia interna
}

void loop() {
  if(digitalRead(8) == LOW){ //botón presionado
    digitalWrite(6,HIGH); //enciende led izquierdo
    digitalWrite(7,LOW); //apaga led derecho
  } else { //botón "al aire"
    digitalWrite(6,LOW); //apaga led izquierdo
    digitalWrite(7,HIGH); //enciende led derecho
  }
}
