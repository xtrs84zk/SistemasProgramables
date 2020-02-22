void setup() {
  //Establecemos todos los pin a utilizar como puertos de salida
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  //Enciende y apaga y apaga el primer led.
  digitalWrite(2,HIGH);
  delay(1000);
  digitalWrite(2,LOW);
  delay(1000);

   //Enciende y apaga el segundo led.
  digitalWrite(3,HIGH);
  delay(1000);
  digitalWrite(3,LOW);
  delay(1000);

    //Enciende y apaga el tercer led.
  digitalWrite(4,HIGH);
  delay(1000);
  digitalWrite(4,LOW);
  delay(1000);

    //Enciende y apaga el cuarto led.
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(5,LOW);
  delay(1000);

    //Enciende y apaga el quinto led.
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(6,LOW);
  delay(1000);
}
