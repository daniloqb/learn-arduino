/*
 * 20160603 - Read Analog Value from LDR sensor
 */



int sensorPin = A0;


void setup() {

Serial.begin(9600);
}

void loop() {

int sensorValue = analogRead(sensorPin);

float milivolts = ( sensorValue / 1024.0) * 5000;
float celsius = milivolts / 10;

Serial.print(sensorValue);
Serial.print(" Milivolts: ");
Serial.print(milivolts);
Serial.print(" Celsius: ");
Serial.println(celsius);

delay(1000);



}
