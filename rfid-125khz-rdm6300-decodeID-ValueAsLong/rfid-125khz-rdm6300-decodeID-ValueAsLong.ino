#include <SoftwareSerial.h>

SoftwareSerial rfid(2,3); // 2 rx, 3 tx

const int startTag = 2;
const int endTag = 3;
const int tagLength = 12;
const int totalLength = tagLength + 2;
char tag[tagLength + 1];
int bytesRead = 0;
long tagValue;


void setup() {
  rfid.begin(9600);
  Serial.begin(9600);
}

void loop() {

  if (rfid.available() >=totalLength){
    if (rfid.read() == startTag){
      tagValue = 0;
      bytesRead = 0;
      while(bytesRead <  tagLength){
        int val = rfid.read();
        if(( val == startTag) || (val == endTag)){
          break;
        }
        tag[bytesRead] = val;
        bytesRead += 1;
      }

      if (rfid.read() == endTag){
        tag[bytesRead] = 0;
        tagValue = atol(tag);
        Serial.print("RFID tag is: ");
        Serial.println(tagValue);
      }
    }
  }


}
