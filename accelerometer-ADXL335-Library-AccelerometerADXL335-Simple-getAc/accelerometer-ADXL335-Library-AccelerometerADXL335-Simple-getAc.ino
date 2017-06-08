
#include "ADXL335.h"
float x;
float y;
float z;

ADXL335 accelerometer;


void setup() { 
  
  Serial.begin(9600);
  accelerometer.begin();
  

}

void loop() {
  
  accelerometer.getAcceleration(&x,&y,&z);

  Serial.print("x: ");Serial.print(x);Serial.print('\t');
  Serial.print("y: ");Serial.print(y);Serial.print('\t');
  Serial.print("z: ");Serial.print(z);Serial.println();
  delay(500);

}
