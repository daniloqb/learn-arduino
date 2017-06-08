

const char HEADER = 'H';
const char DELIMITER = ',';

int vA0,vA1,vA2,vA3,vA4,vA5;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {

  vA0 = analogRead(A0);
  vA1 = analogRead(A1);
  vA2 = analogRead(A2);
  vA3 = analogRead(A3);
  vA4 = analogRead(A4);
  vA5 = analogRead(A5);



  /*
   * C style
   */
  char sendValues[50];

  sprintf(sendValues,"%c%c%d%c%d%c%d%c%d%c%d%c%d",
          HEADER,DELIMITER,
          vA0,DELIMITER,
          vA1,DELIMITER,
          vA2,DELIMITER,
          vA3,DELIMITER,vA4,
          DELIMITER,vA5);

  
  /* Arduino style
   *  
  String sendValues = "";
  sendValues = HEADER;
  sendValues += DELIMITER;
  sendValues += vA0;
  sendValues += DELIMITER;
  sendValues += vA1;
  sendValues += DELIMITER;
  sendValues += vA2;
  sendValues += DELIMITER;
  sendValues += vA3;
  sendValues += DELIMITER;
  sendValues += vA4;
  sendValues += DELIMITER;
  sendValues += vA5;
  */

  
  Serial.println(sendValues);
  delay(3000);
}
