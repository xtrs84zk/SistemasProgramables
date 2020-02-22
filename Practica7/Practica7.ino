int tiempoEnDuracion = 500;
void setup() {
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  //a)
  //Se encienden todos 
    digitalWrite(11,HIGH);
    delay(tiempoEnDuracion);
    digitalWrite(10,HIGH);
    delay(tiempoEnDuracion);
    digitalWrite(9,HIGH);
    delay(tiempoEnDuracion);
    digitalWrite(6,HIGH);
    delay(tiempoEnDuracion);
    digitalWrite(5,HIGH);
    delay(tiempoEnDuracion);
    //b)
    //Se apagan todos
    digitalWrite(5,LOW);
    delay(tiempoEnDuracion);
    digitalWrite(6,LOW);
    delay(tiempoEnDuracion);
    digitalWrite(9,LOW);
    delay(tiempoEnDuracion);
    digitalWrite(10,LOW);
    delay(tiempoEnDuracion);
    digitalWrite(11,LOW);
    delay(tiempoEnDuracion);
    //c)
    //Se encienden todos al mismo tiempo
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH); 
    delay(1000);
    //d)
    //Se apagan todos al mismo tiempo
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(1000);
    //e)
    //Todos pwn 0-100% y del 100-0%
    for(int i = 1; i < 255; i++){
      analogWrite(11,i);
      analogWrite(10,i);
      analogWrite(9,i);
      analogWrite(6,i);
      analogWrite(5,i);
      delay(10);
    }
    for(int i = 255; i > 0; i--){
      analogWrite(5,i);
      analogWrite(6,i);
      analogWrite(9,i);
      analogWrite(10,i);
      analogWrite(11,i);
      delay(10);
    }
    
}
