// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "max6675.h"

int SO = A4;
int CS = 5;
int SCLK = 6;

MAX6675 thermocouple(SCLK, CS, SO);

void setup() {
  Serial.begin(9600);

  
  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
   Serial.println(thermocouple.readCelsius());
 
   delay(1000);
}
