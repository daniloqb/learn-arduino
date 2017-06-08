#include <Ultrasonic.h>

const byte trigger_pin = 12;
const byte echo_pin = 13;


void setup() {

  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  Serial.begin(9600);
}

void loop() {

  int tries = 0;
  long duration;
  float distance;


  
  
  do{

      digitalWrite(trigger_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin,LOW);
    
    duration = pulseIn(echo_pin,HIGH,50000);
    distance = duration/58.2;


  if ( duration == 0 ) {
            delay(100);
            pinMode(echo_pin, OUTPUT);
            digitalWrite(echo_pin, LOW);
            delay(100);
            pinMode(echo_pin, INPUT);
        }
    } while (duration == 0 && ++tries < 3);
    if (duration == 0){
      Serial.println("Out of range");
    }  else
      {
        
  Serial.print("duration: ");
  Serial.print(duration);
  Serial.print(" distance: ");
  Serial.println(distance);

      }

  delay(1000);
}
