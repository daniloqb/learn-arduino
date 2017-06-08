/*
 * 20160603 - Read Analog Value from LDR sensor
 */



int sensorPin = A0;
int threshold = 25;
int ledPin = 8;

int fanA = 6;
int fanB = 7;
int fanTime = 10000;
int fanState = 0;

long startTime = 0;

void setup() {

pinMode(fanA,OUTPUT);
pinMode(fanB,OUTPUT);

digitalWrite(fanA,LOW);
digitalWrite(fanB,LOW);

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

if(celsius >= threshold && (fanState == 0 || fanState == 2)){
  fanState = 1;
  Serial.print("State: ");
  Serial.println(fanState);

  digitalWrite(fanA,HIGH);
  digitalWrite(fanB,LOW);
}

if (celsius < threshold && fanState == 1){
  fanState = 2;
  Serial.print("State: ");
  Serial.println(fanState);
  startTime = millis();

}

if (fanState == 2 && (millis() - startTime > fanTime )){

  fanState = 0;
  Serial.print("State: ");
  Serial.println(fanState);

  digitalWrite(fanA,LOW);
  digitalWrite(fanB,LOW);

  
}

delay(1000);



}
