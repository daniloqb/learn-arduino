/*
 * 20160603 - Read Analog Value from LDR sensor
 */



int sensorPin = A0;
int threshold = 25;
int ledPin = 8;


void setup() {


pinMode(ledPin,OUTPUT);
digitalWrite(ledPin,LOW);

Serial.begin(9600);
}

void loop() {

int sensorValue = analogRead(sensorPin);

long celsius = (sensorValue * 500L) / 1024;

Serial.print(sensorValue);
Serial.print(" Celsius: ");
Serial.println(celsius);

if(celsius >= threshold)
  digitalWrite(ledPin,HIGH);
else
  digitalWrite(ledPin,LOW);

delay(1000);



}
