
int ledPin = 7;
int tiltSensorPin = 2;
int debounceDelay = 90;

const int firstLedPin = 11;
const int secondLedPin = 12;

int state = 0;
boolean changeStatus = true;

long timeAction = 0;

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


Serial.begin(9600);
  pinMode(tiltSensorPin, INPUT);  
  digitalWrite(tiltSensorPin,HIGH);
  
  pinMode(ledPin,OUTPUT);
  pinMode(firstLedPin,OUTPUT);
  pinMode(secondLedPin,OUTPUT);

  digitalWrite(firstLedPin,LOW);
  digitalWrite(secondLedPin,LOW);
}






void loop() {

  

  if(debounce(tiltSensorPin)){

    digitalWrite(firstLedPin,HIGH);
    digitalWrite(secondLedPin,LOW); 

    if(changeStatus){
        if(state == 1){          
          state = 3;          

          Serial.println("State 1 --> 3");
          
        }else if(state == 0){
          state = 1;         
          timeAction = millis(); 
          Serial.println("State 0 --> 1");
        }
        changeStatus = false;
    }
  } else{
        digitalWrite(firstLedPin,LOW);
    digitalWrite(secondLedPin,HIGH);
    changeStatus = true;
  }


  if((state == 1) && ((millis() - timeAction) > 500)){
    state = 2;
    Serial.println("State 1 --> 2");
  }


  if(state == 2){
    state = 0;
    Serial.println("State 2 --> 0");
  }else if(state == 3){
    state = 0;
    Serial.println("State 3 --> 0");
  }


  


  
}
