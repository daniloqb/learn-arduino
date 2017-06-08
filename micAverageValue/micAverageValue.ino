const int ledPin = 8;

int sample;
int numberOfSamples = 1024;
long averageReading; 

const int threshold=800; 


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  long sumOfSamples = 0;
  for (int i=0; i<numberOfSamples; i++) { //take many readings and average them
    sample = analogRead(0);
    sumOfSamples +=sample;
  }
  
  averageReading = sumOfSamples/numberOfSamples;
  
  if (averageReading<threshold){
    digitalWrite(ledPin, !digitalRead(ledPin));
  
 }
  Serial.println(averageReading);

}
