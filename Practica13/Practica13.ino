//Sensor de temperatura en celsius y farenheit
void setup() {
  //Se establece el pin A0 como entrada analógica
  pinMode(A0,INPUT);
  pinMode(2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //Se declaran variables para la lectura, el voltaje y temperatura en C° y F°
  double lectura = 0;
  double voltaje = 0;
  //Se lee desde el arduino[A0]
  lectura = analogRead(A0);
  //Se realizan las conversiones necesarias
  voltaje = (lectura*5)/1023; 
  double gradosCentigrados = voltaje*100;
  double gradosFarenheit = (gradosCentigrados * 9/5) + 32;
  //Se muestra la temperatura.
  Serial.print("Temperatura: ");
  Serial.print(gradosCentigrados);
  Serial.print("C°");
  Serial.print(" o bien, ");
  Serial.print(gradosFarenheit);
  Serial.println("F°");
  delay(1000);
}
