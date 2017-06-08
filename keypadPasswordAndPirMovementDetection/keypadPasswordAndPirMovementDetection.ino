const int numRows = 4;
const int numCols = 4;
const int debounceTime = 20;
char password[5] = {'1','9','7','9','\0'};
char input[5] = {};
boolean lock = 1;
int index = 0;

int pirPin = 2;
int state = 0;
boolean movement = false;

int ledRPin = 3;
int ledGPin = 12;
int ledBPin = 13;

const char keymap[numRows][numCols] ={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}  
  };

const int rowPins[numRows] = {4,5,6,7};
const int colPins[numCols] = {8,9,10,11};

void setup() {

  Serial.begin(9600);
  for(int row = 0; row < numRows;row++){
    pinMode(rowPins[row],INPUT);
    digitalWrite(rowPins[row],HIGH);

  for(int column = 0; column < numCols;column++){
    pinMode(colPins[column],OUTPUT);
    digitalWrite(colPins[column],HIGH);
  }

    
  }

  pinMode(pirPin, INPUT);
  state = 0;
  Serial.print("State: ");
  Serial.println(state);

  pinMode(ledRPin,OUTPUT);
  pinMode(ledGPin,OUTPUT);
  pinMode(ledBPin,OUTPUT);

  digitalWrite(ledRPin,LOW);
  digitalWrite(ledGPin,LOW);
  digitalWrite(ledBPin,LOW);

}

void loop() {


  if(digitalRead(pirPin)){
    movement = true;
    Serial.println("Movement detected!");
  }
  else{
    movement = false;
    Serial.println("All is quiet!");
  }

  char key = getKey();

  if((key == 'D') and (state == 3)){
    state = 4;
    Serial.print("State: ");
    Serial.println(state);

  }
  else{
 
  if(index < 4){   
    
    if(key != 0){
      input[index++] = key;
      Serial.println(input);
    }
  }
  else{
    input[index] = '\0';
    int test = strcmp(password,input);
    index = 0;

    if(test == 0)
      lock = !lock;
      
    input[0] = '\0';
    input[1] = '\0';
    input[2] = '\0';
    input[3] = '\0';
    input[4] = '\0';
    
  }
  }

  



 if(lock){
   Serial.print("LOCKED ");
   if (state == 0){
     state = 1;
     Serial.print("State: ");
     Serial.println(state);
   }
 }
 else{
   Serial.print("UNLOCKED ");
   state = 0;
   Serial.print("State: ");
   Serial.println(state);
 }
  Serial.println(input);


  if ((state == 1) && movement){
    state = 3;
    Serial.print("State: ");
    Serial.println(state);
  }else if ((state == 4) && !movement){
    state = 1;
    Serial.print("State: ");
    Serial.println(state);
  }
  


  switch(state){

    case 0:
      digitalWrite(ledRPin,LOW);
      digitalWrite(ledGPin,HIGH);
      digitalWrite(ledBPin,LOW);
    break;
    
    case 1:
    case 4:
      digitalWrite(ledRPin,HIGH);
      digitalWrite(ledGPin,LOW);
      digitalWrite(ledBPin,LOW);
    break;  
    case 3:
      digitalWrite(ledRPin,LOW);
      digitalWrite(ledGPin,LOW);
      digitalWrite(ledBPin,HIGH);
    break;    
    

    
  }

}

char getKey(){

  char key = 0;

  for(int column = 0; column < numCols; column++){

    digitalWrite(colPins[column],LOW);
    for(int row = 0; row < numRows;row++){
      
      if(digitalRead(rowPins[row]) == LOW){
        delay(debounceTime);
        while(digitalRead(rowPins[row]) == LOW);
        key = keymap[row][column];
      }
    }
    digitalWrite(colPins[column],HIGH);
  }
  return key;
}

