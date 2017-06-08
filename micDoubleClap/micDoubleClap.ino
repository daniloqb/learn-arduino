const int ledPin = 3;

int sample;
int numberOfSamples = 1024;
long averageReading; 

const int threshold=980; 

int state = 0;
long timeout = 3000;
long startTime = 0;


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
    state +=1;
    startTime = millis();
    Serial.print("State: ");
    Serial.println(state);  
 }

 if(state == 2){
  digitalWrite(ledPin, !digitalRead(ledPin));
  state = 0;
  Serial.print("State: ");
  Serial.println(state);
 }

 if((state == 1) && ((millis() - startTime) > timeout)){
  state = 0;
  Serial.print("State: ");
  Serial.println(state);
 }

 Serial.println(averageReading);

}
