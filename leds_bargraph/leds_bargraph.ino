

const int ledPins[] = {2,3,4,5,6,7,8,9};
const int analogPin = 0;
const int wait = 30;

const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);


const boolean LED_ON = LOW;
const boolean LED_OFF = HIGH;

int sensorValue = 0;
int ledLevel = 0;

void setup() {

  for(int i = 0; i < numLeds; i++){
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LED_OFF);
  }

  Serial.begin(9600);

}

void loop() {

  sensorValue = analogRead(analogPin);
  ledLevel = map(sensorValue,0,1023,0,numLeds);

  for (int i = 0; i < numLeds; i++){
    if (i < ledLevel ){
      digitalWrite(ledPins[i], LED_ON);
    }
    else{
      digitalWrite(ledPins[i], LED_OFF);
    }
  }

 Serial.print("Analog Value: ");
 Serial.print(sensorValue);
 Serial.print(" LedLevel: ");
 Serial.println(ledLevel);
  
}


