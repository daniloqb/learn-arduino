#include <TimedTask.h>

int pin_D0 = 2;
int ledPin = 13;

volatile byte pulsos;
unsigned long timeold;

boolean toggle = false;


void contador(){
  pulsos++;
  pulsos %=3;
}

void clear(){
  pulsos = 0;
}


void debug(){
     Serial.println(pulsos);
}

TimedTask tap = TimedTask(contador,100);
TimedTask serial_print = TimedTask(debug,1000);
TimedTask clear_pulsos = TimedTask(clear,5000,1);



void task (){
  tap.run();
}


void setup() {
 Serial.begin(9600);
 pinMode(pin_D0, INPUT);
 pinMode(ledPin,OUTPUT);
 digitalWrite(ledPin,toggle);
 attachInterrupt(0, task, FALLING);
 clear();
 timeold = 0;

 clear_pulsos.active(false);

}

void loop() {

//  if (millis() - timeold > 1000){
//    detachInterrupt(0);
//    Serial.println(pulsos);
//    timeold = millis();
//    attachInterrupt(0, task, FALLING);
//  }

serial_print.run();

  if (pulsos == 2){
    toggle = !toggle;
    digitalWrite(ledPin, toggle);
    clear();
    clear_pulsos.active(false);
  }

  if (pulsos == 1){
    if (clear_pulsos.active() == false){
      clear_pulsos.active(true);
    }

    clear_pulsos.run();
  }


}
