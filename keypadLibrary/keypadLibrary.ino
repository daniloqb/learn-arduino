#include <Keypad.h>



const byte numRows = 4;
const byte numCols = 4;

char keymap[numRows][numCols] ={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}  
  };

byte rowPins[numRows] = {4,5,6,7};
byte colPins[numCols] = {8,9,10,11};

Keypad kpd = Keypad(makeKeymap(keymap),rowPins,colPins,numRows,numCols);

void setup() {

  Serial.begin(9600);
      
  

}

void loop() {

  char key = kpd.getKey();

  if(key != 0){
    Serial.print("Got key ");
    Serial.println(key);
  }

}



