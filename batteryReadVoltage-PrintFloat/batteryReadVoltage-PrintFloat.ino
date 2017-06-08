

int batteryPin = A0;
float voltageReference = 5.0;


void setup() {

  Serial.begin(9600);

}

void loop() {

  int value = analogRead(batteryPin);
  Serial.println(value);
  float volts = ((float)value/1023)*voltageReference;

  Serial.print(volts);
  Serial.println("V");
  delay(1000);
  
}
