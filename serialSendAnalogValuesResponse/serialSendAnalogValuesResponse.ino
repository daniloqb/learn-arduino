

const char HEADER = 'H';
const char DELIMITER = ',';

int val,vA0,vA1,vA2,vA3,vA4,vA5;
char sendValues[50];
unsigned char trigger = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {

  
 trigger = 0;
 
  if (Serial.available()){

    char c = Serial.read();

    switch(c){

      case '0':
        val = analogRead(A0);
        sprintf(sendValues,"%c%c%d%",HEADER,DELIMITER,val);
        trigger = 1;
      break;

      case '1':
       val = analogRead(A1);
        sprintf(sendValues,"%c%c%d%",HEADER,DELIMITER,val);
        trigger = 1;
      break;
      
      case '2':
        val = analogRead(A2);
        sprintf(sendValues,"%c%c%d%",HEADER,DELIMITER,val);
        trigger = 1;
      break;
      
      case '3':
        val = analogRead(A3);
        sprintf(sendValues,"%c%c%d%",HEADER,DELIMITER,val);
        trigger = 1;
      break;
      
      case '4':
        val = analogRead(A4);
        sprintf(sendValues,"%c%c%d%",HEADER,DELIMITER,val);
        trigger = 1;
      break;
      
      case '5':
        val = analogRead(A5);
        sprintf(sendValues,"%c%c%d%",HEADER,DELIMITER,val);
        trigger = 1;
      break;
      
      case 'A':
        vA0 = analogRead(A0);
        vA1 = analogRead(A1);
        vA2 = analogRead(A2);
        vA3 = analogRead(A3);
        vA4 = analogRead(A4);
        vA5 = analogRead(A5);
        
        sprintf(sendValues,"%c%c%d%c%d%c%d%c%d%c%d%c%d",
        HEADER,DELIMITER,
        vA0,DELIMITER,
        vA1,DELIMITER,
        vA2,DELIMITER,
        vA3,DELIMITER,vA4,
        DELIMITER,vA5);
        
        trigger = 1;
      break;
      default:
        sprintf(sendValues,"%c%c%d%",HEADER,DELIMITER,0);
        trigger = 1;
      break;
      break;
    
   }
    
  }
 
  if (trigger){  
    Serial.println(sendValues);
  }
}
