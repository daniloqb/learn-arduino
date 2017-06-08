/*
 * 20160603 - Read Analog Value from LDR sensor
 */



int micPin = A5;


void setup() {

Serial.begin(9600);
}

void loop() {

int micValue = analogRead(micPin);
micValue = map(micValue,0,1023,1023,0);
Serial.println(micValue);




}
