// this example is public domain. enjoy!
// https://learn.adafruit.com/thermocouple/using-a-thermocouple

#include "max6675.h"
#include <SPI.h>


MAX6675 thermocouple_1;
MAX6675 thermocouple_2;

int thermocouple_1_pin = 8;
int thermocouple_2_pin = 9;


void setup() {
  Serial.begin(9600);
  SPI.begin();

  thermocouple_1.begin(thermocouple_1_pin);  
  thermocouple_2.begin(thermocouple_2_pin);
  

  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp

   Serial.print("Termopar 01 C = ");
   Serial.println(thermocouple_1.readCelsius());
   delay(1000);
   Serial.print("Termopar 02 C = ");
   Serial.println(thermocouple_2.readCelsius());

   delay(1000);
}
