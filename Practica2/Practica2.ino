//
int t = 400;

void setup() {
 
  //Establecemos todos los pin a utilizar como puertos de salida
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  //Nueva metodología
  for(int i= 2; i < 7; i++){
    digitalWrite(i,HIGH);
    delay(t);
  }
  for(int i= 6; i>1; i--){
    digitalWrite(i,LOW);
    delay(t);
  }
//  //Enciende y apaga y apaga el primer led.
//  digitalWrite(2,HIGH);
//  delay(t);
//
//   //Enciende el segundo led.
//  digitalWrite(3,HIGH);
//  delay(t);
//
//    //Enciende el tercer led.
//  digitalWrite(4,HIGH);
//  delay(t);
//
//    //Enciende el cuarto led.
//  digitalWrite(5,HIGH);
//  delay(t);
//
//    //Enciende el quinto led.
//  digitalWrite(6,HIGH);
//  delay(t);
//
//  //Apaga los led en el orden inverso
//  digitalWrite(6,LOW);
//  delay(t);
//
//  digitalWrite(5,LOW);
//  delay(t);
//
//  digitalWrite(4,LOW);
//  delay(t);
//
//  digitalWrite(3,LOW);
//  delay(t);
//  
//  digitalWrite(2,LOW);
//  delay(t);
//
}
