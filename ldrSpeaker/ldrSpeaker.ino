/*
 * 20160603 - Read Analog Value from LDR sensor
 * 
 * ldr with a 4.7k
 * Using map function to set the correct value 
 * 
 * 
 *long map(long x, long in_min, long in_max, long out_min, long out_max)
 *{
 *  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
 *}
 * 
 * 
 */



int ldrPin = A0;
int speakerPin = 9;

const int minDuration = 1;
const int maxDuration = 10;

void setup() {

  pinMode(speakerPin,OUTPUT);
}

void loop() {

  int ldrValue = analogRead(ldrPin);

  ldrValue = map(ldrValue,120,980,minDuration,maxDuration);
  ldrValue = constrain(ldrValue,minDuration,maxDuration);

   digitalWrite(speakerPin,HIGH);
   delay(ldrValue);
   digitalWrite(speakerPin,LOW);
   delay(ldrValue);
   
  

}
