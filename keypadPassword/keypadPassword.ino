const int numRows = 4;
const int numCols = 4;
const int debounceTime = 20;
char password[5] = {'1','9','7','9','\0'};
char input[5] = {};
boolean lock = 1;
int index = 0;

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

}

void loop() {

 
  if(index < 4){
    
    char key = getKey();
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

  



 if(lock)
   Serial.print("LOCKED ");
 else
   Serial.print("UNLOCKED ");

  Serial.println(input);

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

