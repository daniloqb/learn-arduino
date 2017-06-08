#include <NewPing.h>
#include <Servo.h>




const byte trigger_pin = 12;
const byte echo_pin = 13;
const byte max_distance = 200;

int pirPin = 2;
int pirVcc = 7;

int pos = 90;
int pace = -10;


boolean movementDetected = false;
boolean outOfRange = false;
int findState = 0;



Servo myservo;
NewPing sonar(trigger_pin, echo_pin, max_distance);

void setup() {


  
    myservo.attach(9); 
    pinMode(pirVcc,OUTPUT);
    digitalWrite(pirVcc,HIGH);

    pinMode(pirPin,INPUT);
    Serial.begin(9600);
    
    pinMode(trigger_pin,OUTPUT);
    pinMode(echo_pin,INPUT);
    

    

  
}

void loop() {

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

      distance = sonar.ping_cm();
     
     if (distance <= 0 || distance > 100.0){
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
