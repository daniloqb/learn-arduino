/*
 * 20160603 - Read Analog Value from LDR sensor
 */



int sensorPin = A0;


void setup() {

Serial.begin(9600);
}

void loop() {

int sensorValue = analogRead(sensorPin);

Serial.println(sensorValue);

delay(1000);



}
