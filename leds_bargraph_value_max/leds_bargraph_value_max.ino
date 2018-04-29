
#include <TimedTask.h>

const int ledPins[] = {2,3,4,5,6,7,8,9};
const int analogPin = 0;
const int wait = 30;

const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);


const boolean LED_ON = LOW;
const boolean LED_OFF = HIGH;

int sensorValue = 0;
int ledLevel = 0;
int storageValue = 0;
int ledLevelMax = -1;

void clearLevelMax(){

  digitalWrite(ledPins[ledLevelMax], LED_OFF);
  ledLevelMax = -1;
   
}


TimedTask l = TimedTask(clearLevelMax,1000);

void setup() {

  for(int i = 0; i < numLeds; i++){
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LED_OFF);
  }

  Serial.begin(9600);

}

void loop() {

  l.run();

  sensorValue = analogRead(analogPin);
  storageValue = max(sensorValue, storageValue);
  ledLevel = map(storageValue,0,1023,0,numLeds);

   if (ledLevelMax == -1){
    ledLevelMax = ledLevel -1;
   }


  digitalWrite(ledPins[ledLevelMax], LED_ON);

 

  for (int i = 0; i < numLeds; i++){
    if (i < ledLevel ){
      digitalWrite(ledPins[i], LED_ON);
    }
    else{
        digitalWrite(ledPins[i], LED_OFF);
      
    }
  }
  digitalWrite(ledPins[ledLevelMax], LED_ON);


 Serial.print("Analog Value: ");
 Serial.print(sensorValue);
 Serial.print(" StorageValue: ");
 Serial.print(storageValue);
 Serial.print(" LedLevel: ");
 Serial.print(ledLevel);
  Serial.print(" LedLevelMax: ");
 Serial.println(ledLevelMax);
 

 storageValue -= 150;


  
}


