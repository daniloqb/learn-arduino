
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
}

void loop() {

    int value = analogRead(batteryPin);

    int batteryLevel = map(value,0,675,0,100);

    Serial.print(batteryLevel);
    Serial.println("%");
    delay(1000);
}
