int sensorPin = A5;

int numberOfLeds = 6;

const int numberOfSamples = 16;
int sample;
long signal[numberOfSamples];
long runningAverage;
long sumOfSamples;
int counter =0;

//int threshold[] = {0,47,99,159,227,308,407,535,715,800,900};
int threshold[] = {0,47,227,535,715,800,900};


void setup(){

  for(int i = 8; i < 14; i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }

  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);



  for( int i = 0; i <= numberOfSamples; i++){

    sample = analogRead(sensorPin);
    sample = map(sample,0,1023,1023,0);
    
    signal[i] = abs(sample);
    sumOfSamples = sumOfSamples + signal[i];
  }

  for(int i = 8; i<14; i++){
    digitalWrite(i,HIGH);
    delay(100);
  }
  for(int i = 8; i<14;i++){
    digitalWrite(i,LOW);
  }

  Serial.begin(9600);
}

void loop(){

  counter = ++counter % numberOfSamples;
  sumOfSamples -= signal[counter];

  sample = analogRead(sensorPin);
  sample = map(sample,0,1023,1023,0);

  signal[counter] = abs(sample);

  sumOfSamples = sumOfSamples + signal[counter];

  runningAverage = sumOfSamples/numberOfSamples;

  Serial.print("RunningAverage:" );
  Serial.println(runningAverage);
  Serial.println();


  for(int i=0; i<=numberOfLeds; i++){

    if(runningAverage > threshold[i]){
      digitalWrite(8+i,HIGH);
      delay(10);
    }
  }

  for(int i=0; i <= numberOfLeds;i++){
    digitalWrite(i+8,LOW);
  }
}

