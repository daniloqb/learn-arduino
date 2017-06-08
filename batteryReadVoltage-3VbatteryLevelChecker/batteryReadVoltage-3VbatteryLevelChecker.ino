
int batteryPin = A0;
int ledPin = 13;
int threshold = 550;


/*
 *  5.0V   -- 1023
 *  3.3V -- 675
 *  2.7V -- 550
 */

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,HIGH);
}

void loop() {

    int value = analogRead(batteryPin);

    int batteryLevel = map(value,0,675,0,100);

    Serial.print(batteryLevel);
    Serial.println("%");

    if (value < threshold){
      digitalWrite(ledPin,LOW);
      delay(100+batteryLevel);
      digitalWrite(ledPin,HIGH);
      delay(batteryLevel);
      
      
    }
    
}
