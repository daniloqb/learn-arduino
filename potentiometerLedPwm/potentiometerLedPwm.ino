int ledPin = 9;
int potPin = A0;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin,OUTPUT);

  digitalWrite(ledPin,LOW);

 Serial.begin(9600);
  

}

void loop() {

  int potValue = analogRead(potPin);

  potValue = map(potValue,0,1023,0,255);

  analogWrite(ledPin,potValue);

  
  delay(500);
  

}
