/*
SwitchTime sketch
Countdown timer that decrements every tenth of a second
lights an LED when 0
Pressing button increments count, holding button down increases
rate of increment
*/


const int ledPin = 13;
const int buttonPin = 2;

int count = 0;
const int debounceTime = 20;
const int fastIncrement = 1000;
const int veryFastIncrement  =4000;


void setup() {
  // put your setup code here, to run once:

 pinMode(ledPin,OUTPUT);
 pinMode(buttonPin,INPUT);

 digitalWrite(buttonPin,HIGH);
 digitalWrite(ledPin,LOW);

 Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:


  int duration = switchTime();

  if(duration > veryFastIncrement){
    count += 10;
  }
  else if(duration > fastIncrement){
    count += 4;
  }
  else if(duration > debounceTime){
    count += 1;
  }
  else{
    
    if(count == 0){
      digitalWrite(ledPin,HIGH);
    }
    else{
      digitalWrite(ledPin,LOW);
      count -= 1;
    }
    
  }

  Serial.println(count);
  delay(100);
  
}



long switchTime(){

 static unsigned long startTime;
 static boolean state;


  if(digitalRead(buttonPin) != state){

    state = !state;
    startTime = millis();
  }

  if(state == LOW){
    return millis() - startTime;
  }
  else{
    return 0;
  }

  
}

