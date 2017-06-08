


const int tiltSensorPin = 2;
const int firstLedPin = 11;
const int secondLedPin = 12;
const int ledPin = 7;
boolean ledStatus = false;
boolean changeStatus = true;


int debounceDelay = 90;
int toggle= HIGH;
int count = 0;

bool debounce(int pin){

  bool state;
  bool previousState;

  previousState = digitalRead(pin);

  for(int counter = 0; counter < debounceDelay; counter++){
    
    delay(1);
    state = digitalRead(pin);

    if(state != previousState){
      counter = 0;
      previousState = state;
    }
    
    
  }
  
  return state;  
  
}




void setup() {
  // put your setup code here, to run once:

  pinMode(tiltSensorPin,INPUT);
  digitalWrite(tiltSensorPin,HIGH);



  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  

}

void loop() {
  // put your main code here, to run repeatedly:


  if(debounce(tiltSensorPin)){
    digitalWrite(firstLedPin,HIGH);
    digitalWrite(secondLedPin,LOW); 
    if(changeStatus){
      ledStatus = !ledStatus;
      digitalWrite(ledPin,ledStatus);
      changeStatus = false;
    }
  }
  else{
    digitalWrite(firstLedPin,LOW);
    digitalWrite(secondLedPin,HIGH);
    changeStatus = true;
  }



}
