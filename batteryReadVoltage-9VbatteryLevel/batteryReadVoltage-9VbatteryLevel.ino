
int batteryPin = A0;

const float referenceVolts = 5;

const float R1 = 1000;
const float R2 = 1000;

const float resistorFactor = 1023.0 / (R2/(R2+R1));

/*
 *  5.0V   -- 1023
 *  4.5V   -- 920
 */

void setup() {
  Serial.begin(9600);
}

void loop() {

    int value = analogRead(batteryPin);

    float volts = map(value,0,920,0,9);
    Serial.println(value);
    Serial.print(volts);
    Serial.println('V');
    delay(1000);
   /* 
    *  
    int batteryLevel = map(value,0,675,0,100);

    Serial.print(batteryLevel);
    Serial.println("%");
    delay(1000);
    *
    */
}
