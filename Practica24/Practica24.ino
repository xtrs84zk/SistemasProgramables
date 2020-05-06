int pin_Trig = 3;
int pin_Echo = 2;
int ledUno = 5;
int ledDos = 6;
double duracion = 0;
double tiempo = 0,
double distancia = 0;
  
void setup() {
  pinMode(pin_Trig,OUTPUT);
  pinMode(pin_Echo,INPUT);
  Serial.begin(3600);
}

void loop() {
  digitalWrite(pin_Trig,HIGH);
  delay(0.01);
  digitalWrite(pin_Trig,LOW);

  //regresa el tiempo que pasa entre que detecta un HIGH y un LOW
  duracion = pulseIn(pin_Echo,HIGH);
  tiempo = duracion/2;
  distancia = 0.03432*tiempo;

  Serial.println(distancia);
  delay(500);

  //si la distancia es >= 2 y <= 15cm .: encender led 1
  if(distancia>= 2 && distancia <= 15){
    digitalWrite(ledUno,HIGH);
    digitalWrite(ledDos,LOW); 
  }
  //si no .: encender led dos
  if(distancia >= 15 ) {
    digitalWrite(ledUno,LOW);
    digitalWrite(ledDos,HIGH);
  }
}
