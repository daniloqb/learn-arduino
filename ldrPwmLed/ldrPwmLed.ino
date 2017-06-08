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
int ledPin = 9;

void setup() {

  pinMode(ledPin,OUTPUT);
}

void loop() {

  int ldrValue = analogRead(ldrPin);

  ldrValue = map(ldrValue,980,120,0,255);

  analogWrite(ledPin,ldrValue);
  
  delay(1000);


}
