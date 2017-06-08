#include <Ultrasonic.h>


const byte trigger_pin =  12;
const byte echo_pin =  13;


Ultrasonic ultrasonic(trigger_pin,echo_pin);

void setup() {

  Serial.begin(9600);

}

void loop() {

float cmuSec;

long uSec = ultrasonic.timing();

cmuSec = ultrasonic.convert(uSec,Ultrasonic::CM);

Serial.print("uS: ");
Serial.print(uSec);
Serial.print(" ,cm: ");
Serial.println(cmuSec);

delay(1000);
  
}
