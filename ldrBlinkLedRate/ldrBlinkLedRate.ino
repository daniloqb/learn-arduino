/*
 * 20160603 - Read Analog Value from LDR sensor
 */



int ldrPin = A0;
int ledPin = 9;



void setup() {

  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);

}

void loop() {

  int ldrValue = analogRead(ldrPin);

  digitalWrite(ledPin,HIGH);
  delay(ldrValue);

  digitalWrite(ledPin,LOW);
  delay(ldrValue);


}
