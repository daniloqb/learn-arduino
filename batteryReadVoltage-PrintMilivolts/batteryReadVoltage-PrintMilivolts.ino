
int batteryPin = A0;


void setup() {
  Serial.begin(9600);
}

void loop() {

    long value = analogRead(batteryPin);

    int volts = (value * (500000/1023))/100;
    Serial.print(volts);
    Serial.println("mV");
    delay(1000);
}
