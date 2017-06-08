int ledPin = 13;
int potPin = A0;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin,OUTPUT);

  digitalWrite(ledPin,LOW);

 Serial.begin(9600);
  

}

void loop() {

  int potValue = analogRead(potPin);

  potValue = map(potValue,0,1023,0,100);

  Serial.print(potValue);
  Serial.println("%");

  
  delay(500);
  

}
