const char HEADER = 'H';
const char DELIMITER = ',';


const int MAXCHARS = 5;

char strValue[MAXCHARS+1];
int strIndex = 0;


int intValues[6];
int intIndex = 0;




void setup() {

  Serial.begin(9600);

}

void loop() {

 char c;
 intIndex = 0;

  if(Serial.available() > 0){
    c = Serial.read();
    Serial.print(c);
    Serial.println(" ");
    delay(40);    
    
    if( c == HEADER){
       while(Serial.available()){
         c = Serial.read();
         
         if(strIndex < MAXCHARS && isDigit(c)){
         
           strValue[strIndex++] = c;
         //  Serial.print(strValue[strIndex-1]);
         
         }
         else{

          if(strIndex > 0){
           strValue[strIndex] = 0;
           strIndex =0;

           
   
           intValues[intIndex++] = atoi(strValue);
           
           Serial.print(strValue);
           Serial.print(": ");
           Serial.print(intValues[intIndex-1],DEC);
           Serial.println(" ");
         
         }
         }
 
       }
       Serial.println();
    }
    else{

      while(Serial.available())
        c = Serial.read();
    
    }
   }
    
}
