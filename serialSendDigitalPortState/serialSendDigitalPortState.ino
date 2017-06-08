
const char HEADER = 'H';

int portsState;

void setup() {

  Serial.begin(9600);
 
  for(int i=2;i<=13;i++){
    pinMode(i,INPUT_PULLUP);
    
    }

}

void loop() {

portsState = 0;

for(int i=2;i<=13;i++){

    bitWrite(portsState,i-2,digitalRead(i));
}

Serial.print(HEADER);
Serial.println(portsState,BIN);


delay(2000);

  
}
