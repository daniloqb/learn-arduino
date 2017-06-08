#include <Ultrasonic.h>
#include <Servo.h>


Servo myservo;


const byte trigger_pin = 12;
const byte echo_pin = 13;

int pirPin = 2;
int pirVcc = 7;

int pos = 90;
int pace = -10;


boolean movementDetected = false;
boolean outOfRange = false;
int findState = 0;

void setup() {


  
    myservo.attach(9); 
    pinMode(pirVcc,OUTPUT);
    digitalWrite(pirVcc,HIGH);
    pinMode(trigger_pin,OUTPUT);
    pinMode(echo_pin,INPUT);
    
    pinMode(pirPin,INPUT);
    Serial.begin(9600);
    

  
}

void loop() {

  int tries = 0;
  long duration;
  float distance;

  if(digitalRead(pirPin)){
    Serial.println("Movement detected!");
    movementDetected = true;
    
  }
  else{
    Serial.println("All is quiet!");
    movementDetected = false;
    findState = 0;
    pace *= -1; 

  }


  if(movementDetected){
        
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
     
     if (duration == 0 || distance > 100.0){
      Serial.println("Out of range");
      outOfRange = true;
    }  else
      {
        Serial.print(" distance: "); 
        Serial.println(distance);
        outOfRange = false;
      }

      if(outOfRange){

        
        pos += pace;

        pos = constrain(pos,0,180);     
        Serial.print("Servo position:");
        Serial.println(pos);

         

        if (pos <= 0 || pos >= 180){
          pace *= -1;
         findState++;
        }

       if(findState == 2){
        findState =0;
        pos = 90;
        myservo.write(pos);
       }


        myservo.write(pos);
        
      }
  
  }

delay(10);

}
