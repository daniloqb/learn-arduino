/**

Geting Started

A sketch to list the available serial ports and display characters received

*/


import processing.serial.*;

Serial myPort;
int portIndex = 0;
int val;

void setup(){

size(200,200);
println(Serial.list());
println(" Connecting to -> " + Serial.list()[portIndex]);
myPort = new Serial(this,Serial.list()[portIndex],9600); 

}


void draw(){
 
  if( myPort.available() > 0){
     val = myPort.read();
     print(val);
    
  }
  
}