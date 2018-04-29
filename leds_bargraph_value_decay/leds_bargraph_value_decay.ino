

const int ledPins[] = {2,3,4,5,6,7,8,9};
const int analogPin = 0;
const int wait = 30;

const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);


const boolean LED_ON = LOW;
const boolean LED_OFF = HIGH;

int sensorValue = 0;
int ledLevel = 0;
int storageValue = 0;

void setup() {

  for(int i = 0; i < numLeds; i++){
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LED_OFF);
  }

  Serial.begin(9600);

}

void loop() {

  sensorValue = analogRead(analogPin);
  storageValue = max(sensorValue, storageValue);
  ledLevel = map(storageValue,0,1023,0,numLeds);
  

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
 Serial.print(" StorageValue: ");
 Serial.print(storageValue);
 Serial.print(" LedLevel: ");
 Serial.println(ledLevel);
 

 storageValue -= 30;

  
}


