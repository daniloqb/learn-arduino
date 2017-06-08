


const int tiltSensorPin = 2;
const int firstLedPin = 11;
const int secondLedPin = 12;

void setup() {
  // put your setup code here, to run once:

  pinMode(tiltSensorPin,INPUT);
  digitalWrite(tiltSensorPin,HIGH);

  pinMode(firstLedPin,OUTPUT);
  pinMode(secondLedPin,OUTPUT);

  digitalWrite(firstLedPin,LOW);
  digitalWrite(secondLedPin,LOW);
  

}

void loop() {
  // put your main code here, to run repeatedly:


  if(digitalRead(tiltSensorPin)){
    digitalWrite(firstLedPin,HIGH);
    digitalWrite(secondLedPin,LOW);    
  }
  else{
    digitalWrite(firstLedPin,LOW);
    digitalWrite(secondLedPin,HIGH);
  }

}
