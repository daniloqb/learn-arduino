
int pirPin = 2;
int ledPin = 13;


void setup() {

    pinMode(pirPin,INPUT);
    pinMode(ledPin,OUTPUT);
    Serial.begin(9600);  

  
}

void loop() {

    if (digitalRead(pirPin)) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Movement detected!");
  }
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("All is quiet!");
  }

  delay(1000);

}
