const char HEADER = 'H';
const char DELIMITER = ',';


const int MAXCHARS = 255;

char strValue[MAXCHARS+1];
int strIndex = 0;


char * list;
int listIndex = 0;




void setup() {

  Serial.begin(9600);

}

void loop() {

 char c;
 listIndex = 0;

  if(Serial.available() > 0){
    c = Serial.read();
    Serial.print(c);
    Serial.println(" ");
    delay(40);    
    
    if( c == HEADER){
      strValue[strIndex++] = c;
       while(Serial.available()){
         c = Serial.read();
         
         if(strIndex < MAXCHARS){         
           strValue[strIndex++] = c;
         
         }

         
 
       }
       strIndex = 0;
       list = strtok(&strValue[0],",");
       list = strtok(NULL, ",");
       while(list){
        Serial.println(list);
        list = strtok(NULL, ",");
       }
    }
    else{

      while(Serial.available())
        c = Serial.read();
    
    }
   }
    
}
