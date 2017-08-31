#include <TimedTask.h>


int sensor_pin = A0;
int numberOfSamples  = 1000;
long averageReading;
int sensor_value;


int ledPin = 13;

volatile byte pulsos;


boolean toggle = false;


void readings(){
    long sumOfSamples = 0;
  for (int i = 0; i < numberOfSamples; i++){
    sensor_value = analogRead(sensor_pin);
    if (sensor_value > 0)
      sumOfSamples += sensor_value;
  }

  averageReading = sumOfSamples/numberOfSamples;
  contador();
}

void contador(){
  if (averageReading > 35){
    pulsos++;
    pulsos %=3;
  }
}

void clear(){
  pulsos = 0;
}


void debug(){
     Serial.print("pulsos: ");
     Serial.println(pulsos);
     
}

TimedTask tap = TimedTask(readings,100);
TimedTask serial_print = TimedTask(debug,1000);
TimedTask clear_pulsos = TimedTask(clear,5000,1);






void setup() {
 Serial.begin(9600);
 pinMode(ledPin,OUTPUT);
 digitalWrite(ledPin,toggle);

 clear();

 clear_pulsos.active(false);

}

void loop() {

 tap.run();

//readings();

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
