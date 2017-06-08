int ledPin = 13;
int potPin = A0;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin,OUTPUT);

  digitalWrite(ledPin,LOW);

 Serial.begin(9600);
  

}

void loop() {

  Serial.println(analogRead(potPin));
  delay(500);
  

}
