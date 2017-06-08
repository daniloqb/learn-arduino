


int state = 0;
long timeAction = 0;
boolean changeStatus = true;

int debounceDelay = 90;

int tiltSensorPin = 2;
const int ledRPin = 3;
const int ledGPin = 5;
const int ledBPin = 6;



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
  
  pinMode(ledRPin,OUTPUT);
  pinMode(ledGPin,OUTPUT);
  pinMode(ledBPin,OUTPUT);
  
  digitalWrite(ledRPin,LOW);
  digitalWrite(ledGPin,LOW);
  digitalWrite(ledBPin,LOW);
}






void loop() {

  

  if(debounce(tiltSensorPin)){

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
    changeStatus = true;
  }


  if((state == 1) && ((millis() - timeAction) > 500)){
    state = 2;
    Serial.println("State 1 --> 2");
  }


  if(state == 2){
     state = 0;
     Serial.println("State 2 --> 0");
     analogWrite(ledRPin,random(256));
     analogWrite(ledGPin,random(256));
     analogWrite(ledBPin,random(256));
     
  }else if(state == 3){
     state = 0;
     Serial.println("State 3 --> 0");
     digitalWrite(ledRPin,LOW);
     digitalWrite(ledGPin,LOW);
     digitalWrite(ledBPin,LOW);
  }


  


  
}
