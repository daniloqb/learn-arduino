int ledPin = 13;
int buttonA = 2;
int buttonB = 3;

int debounceDelay =1000;



unsigned long switchTime(int pin, boolean &state, unsigned long &startTime);

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin,OUTPUT);
  pinMode(buttonA, INPUT);
  pinMode(buttonB,INPUT);

  digitalWrite(ledPin,LOW);
  digitalWrite(buttonA, HIGH);
  digitalWrite(buttonB,HIGH);

  Serial.begin(9600);


}

void loop() {

  unsigned long buttonAState;
  unsigned long buttonBState;
/* TEST A
 *  
  Serial.print("button A time = ");
  time = switchATime();
  Serial.println(time);

  Serial.print("button B time = ");
  time = switchBTime();
  Serial.println(time);


  delay(1000);

  */

/*TEST B
 * 
 *
 time = switchATime();

 if(time > debounceDelay)
  Serial.println("Button A was pressed");

  time = switchBTime();

 if(time > debounceDelay)
  Serial.println("Button B was pressed");

*/

 buttonAState = switchATime();
 buttonBState = switchBTime();

 if(buttonAState > debounceDelay)
  digitalWrite(ledPin,HIGH);  

 if(buttonBState > debounceDelay)
  digitalWrite(ledPin,LOW);
}




unsigned long switchTime(int pin, boolean &state, unsigned long &startTime){


  if(digitalRead(pin) != state){
    state = !state;
    startTime = millis();
  }

  if(state == LOW)
    return millis() - startTime;
  else
    return 0; 

}

long switchATime(){
  static unsigned long startTime;
  static boolean state;

  return switchTime(buttonA,state,startTime);
}

long switchBTime(){
  static unsigned long startTime;
  static boolean state;

  return switchTime(buttonB,state,startTime);
}




