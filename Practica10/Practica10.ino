int led1 = 3;
int led2 = 5;
int led3 = 6;
int corrienteParaElPotenciometro = 1;
void setup() {
  pinMode(A0,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(corrienteParaElPotenciometro,HIGH);
  //habilita el monitor serial
  //velocidad máxima 11,200
  Serial.begin(9600);
}

void loop() {
  //for(int i = 0; i<9; i++){digitalWrite(i,HIGH);}
  double lectura = 0;
  double voltaje = 0;
  //se accede a la lectura
  lectura = analogRead(A0);
  //v -> 1.5v .  1.5v -> 300
  //se transforma la lectura en voltaje
  voltaje = (lectura*5)/1023;
  if(voltaje>=0.0 && voltaje <=1.5){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  if(voltaje>=1.5 && voltaje<=3.0){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
  }
  if(voltaje>=3.0){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
  }
  Serial.print(voltaje);
  Serial.println("v.");

}
