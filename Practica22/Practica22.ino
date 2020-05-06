int pin_Trig = 3;
int pin_Echo = 2;
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
}
