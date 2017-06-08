/*
 * 20160603 - Read Analog Value from LDR sensor
 */



int ldrPin = A0;


void setup() {

Serial.begin(9600);
}

void loop() {

int ldrValue = analogRead(ldrPin);
Serial.println(ldrValue);




}
