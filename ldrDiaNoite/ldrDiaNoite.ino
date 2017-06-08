/*
 * 20160603 - Read Analog Value from LDR sensor
 */



int ldrPin = A0;
int ledPin = 9;
int dayThreshold = 300;



void setup() {

  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int ldrValue = analogRead(ldrPin);

  if(ldrValue > dayThreshold){
    Serial.print("Dia: ");
    digitalWrite(ledPin,LOW);
  }
  else{
    Serial.print("Noite: ");
    digitalWrite(ledPin,HIGH);
  }
  
  Serial.println(ldrValue);

  delay(1000);


}
