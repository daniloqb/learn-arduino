

int sensor_pin = A0;
int numberOfSamples  = 500;
long averageReading;
int sensor_value;

const int threshold = 50;

int ledpin = 13;
bool ledstatus;


void setup() {
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
  digitalWrite(ledpin,LOW);
  ledstatus = LOW;

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

  if (averageReading > threshold){
    ledstatus = !ledstatus;
    digitalWrite(ledpin,ledstatus);
  }
  
  Serial.println(averageReading);
    
}
