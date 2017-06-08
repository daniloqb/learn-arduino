#include <SoftwareSerial.h>

SoftwareSerial rfid(2,3); // 2 rx, 3 tx


void setup() {
  rfid.begin(9600);
  Serial.begin(9600);
}

void loop() {
  int i = 0;
  while (rfid.available()){
    char c = rfid.read();
    
    Serial.print(i);
    Serial.print(" ");
    Serial.print(c,BIN);
    Serial.print(" ");
    Serial.print(c,HEX);
    Serial.print(" ");
    Serial.print(c,DEC);
    Serial.print(" ");
    Serial.write(c);
    Serial.println();
    i = (i+1)%14;
  }


}
