/*
 * Este sketch utiliza o chip CD4051BE Multiplexador/Demultiplexador Analógico.
 * Com isso até 8 sensores podem ser conectados a uma única porta do arduino
 */



const int select[] = {2,3,4};

const int analogPin = A0;



int getValue(int channel){

  //Serial.print(channel,BIN);
  for( int bit = 0; bit < 3; bit++){

    int pin = select[bit];

    int isBitSet = bitRead(channel,bit);
    digitalWrite(pin,isBitSet);
    
   // Serial.print(" ");
    //Serial.print(isBitSet);
  }
 // Serial.println();
  return analogRead(analogPin);

  
}



void setup() {
  // put your setup code here, to run once:

  for (int i = 0; i< 3; i++){
    pinMode(select[i],OUTPUT);
  }

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int channel = 0; channel < 8; channel++){
    int value = getValue(channel);
    Serial.print("Channel ");
    Serial.print(channel);
    Serial.print(" = ");
    Serial.println(value);
  }

  delay(1000);
}
