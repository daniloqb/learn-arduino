const int numRows = 4;
const int numCols = 4;
const int debounceTime = 20;

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

  char key = getKey();

  if(key != 0){
    Serial.println(key);
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

