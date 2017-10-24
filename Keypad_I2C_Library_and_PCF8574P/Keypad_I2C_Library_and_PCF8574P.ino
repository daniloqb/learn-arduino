#include <Keypad_I2C.h>

// A0, A1, A2 all to GND
#define I2CADDR 0x27


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

void setup(){
  Wire.begin( );
  kpd.begin( makeKeymap(keys) );
  Serial.begin(9600);
  Serial.println( "start" );
}
void loop(){
  
  char key = kpd.getKey();
  
  if (key){
    Serial.println(key);
  }
}
