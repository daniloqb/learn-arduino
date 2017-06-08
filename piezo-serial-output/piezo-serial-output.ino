

int sensor_pin = A0;


void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int sensor_value = analogRead(sensor_pin);
  Serial.println(sensor_value);
  
}
