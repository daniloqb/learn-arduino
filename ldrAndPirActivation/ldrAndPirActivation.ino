/*
 * 20160603 - Read Analog Value from LDR sensor
 */



int ldrPin = A0;
int pirPin = 2;
int ledPin = 9;
int dayThreshold = 300;
boolean night = false;
boolean movement = false;
int state = 0;
long onTime = 0;



void setup() {

  pinMode(ledPin,OUTPUT);
  pinMode(pirPin,INPUT);
  Serial.begin(9600);
}

void loop() {

  int ldrValue = analogRead(ldrPin);

  if(ldrValue > dayThreshold){
    Serial.print("Dia: ");
    night = false;
    
  }
  else{
    Serial.print("Noite: ");
    night = true;
    
  }
    Serial.println(ldrValue);

  if(digitalRead(pirPin)){
    movement = true;
    Serial.println("Movement detected!");
  }
  else{
    movement = false;
    Serial.println("All quiet.");
  }
  


  if((movement == true) &&(night == true)){
    digitalWrite(ledPin,HIGH);    
  }
  else{
    digitalWrite(ledPin,LOW);
  }

  delay(1000);


}
