// this example is public domain. enjoy!
// https://learn.adafruit.com/thermocouple/using-a-thermocouple

#include "max6675.h"
#include <SPI.h>

int thermoDO_1 = 6;
int thermoCS_1 = 5;
int thermoCLK_1 = 4;

MAX6675 thermocouple_1;
int vccPin_1 = 3;
int gndPin_1 = 2;


int thermoDO_2 = 12;
int thermoCS_2 = 11;
int thermoCLK_2 = 10;

MAX6675 thermocouple_2;
int vccPin_2 = 9;
int gndPin_2 = 8;

void setup() {
  Serial.begin(9600);

  thermocouple_1.begin(thermoCLK_1, thermoCS_1, thermoDO_1);  
  thermocouple_2.begin(thermoCLK_2, thermoCS_2, thermoDO_2);
  
  // use Arduino pins
  pinMode(vccPin_1, OUTPUT); digitalWrite(vccPin_1, HIGH);
  pinMode(gndPin_1, OUTPUT); digitalWrite(gndPin_1, LOW);

  pinMode(vccPin_2, OUTPUT); digitalWrite(vccPin_2, HIGH);
  pinMode(gndPin_2, OUTPUT); digitalWrite(gndPin_2, LOW);

  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp

   Serial.print("Termopar 01 C = ");
   Serial.println(thermocouple_1.readCelsius());
   Serial.print("Termopar 02 C = ");
   Serial.println(thermocouple_2.readCelsius());

   delay(1000);
}
