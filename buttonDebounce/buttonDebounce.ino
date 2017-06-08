
int ledPin = 7;
int buttonPin = 2;
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


Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin,OUTPUT);

}






void loop() {

  

  if(debounce(buttonPin)){
        digitalWrite(ledPin,toggle);
        toggle = !toggle;
        count++;
        Serial.println(count);
  }

  
}
