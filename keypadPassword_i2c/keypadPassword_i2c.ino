#include <Keypad_I2C.h>


#define I2CADDR 0x27





const int debounceTime = 20;
char password[5] = {'1','9','7','9','\0'};
char input[5] = {};
boolean lock = 1;
int index = 0;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


// Digitran keypad, bit numbers of PCF8574 i/o port
byte rowPins[ROWS] = {0, 1, 2, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 6, 7}; //connect to the column pinouts of the keypad


Keypad_I2C kpd( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574 );


void setup() {
  
  Wire.begin( );
  kpd.begin( makeKeymap(keys) );
  Serial.begin(9600);

}

void loop() {

 
  if(index < 4){
    
    char key = kpd.getKey();
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

