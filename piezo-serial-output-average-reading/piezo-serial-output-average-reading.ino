

int sensor_pin = A0;
int numberOfSamples  = 500;
long averageReading;
int sensor_value;


void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  long sumOfSamples = 0;
  for (int i = 0; i < numberOfSamples; i++){
    sensor_value = analogRead(sensor_pin);
    if (sensor_value > 0)
      sumOfSamples += sensor_value;
  }

  averageReading = sumOfSamples/numberOfSamples;
  Serial.println(averageReading);
    
}
