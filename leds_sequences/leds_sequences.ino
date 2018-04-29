
const int led_pins[8] = {2,3,4,5,6,7,8,9};
const int num_leds = 8;
const int LED_OFF = HIGH;
const int LED_ON = LOW;
byte data = 0;

unsigned long time_passed = 0;
unsigned long fps = 0;
unsigned long delay_ms = 0;
const unsigned long fps_max = 10;

int repeat = 5;



void handle_leds(byte data){

  byte mask = 0x01;

  for (int i = 0; mask; i++){
    digitalWrite(led_pins[i], !(data & mask));
    mask = mask << 1;
  }
}

void tick(){

 unsigned long old_delay = delay_ms;
 
 if (millis() - time_passed > 1000){

    if (fps > fps_max){
      delay_ms = fps / ((fps / 1000) * fps_max);
    }

    if (delay_ms > 255){
      delay_ms = old_delay;
    }
    
    Serial.println(fps);
    Serial.println(delay_ms);
    time_passed = millis();
    fps = 0;
  }

  fps++;
}


void setup() {

 for (int i =0; i < num_leds; i++){
  pinMode(led_pins[i], OUTPUT);
  digitalWrite(led_pins[i], LED_OFF);
 }


  Serial.begin(9600);
}

void loop() {




 /*
  * Passo 1
  */
 Serial.println("Passo 1");
 for (int k = 0; k < repeat; k++){
 
   data = 0x01;
   for (int i = 0; i < num_leds; i++){
  
    tick();

     handle_leds(data);
     data = data << 1;
     delay(delay_ms);
 
   }
 }

 
 /*
  * Passo 2
  */
 Serial.println("Passo 2");
 for (int k = 0; k < repeat; k++){
 
   data = 0x01 << 7;
   for (int i = 0; i < num_leds; i++){
  
    tick();

     handle_leds(data);
     data = data >> 1;
     delay(delay_ms);
 
   }
 }


 
 /*
  * Passo 3
  */
 Serial.println("Passo 3");
 for (int k = 0; k < repeat; k++){
 
   data = 0x01;
   for (int i = 0; i < num_leds; i++){
  
    tick();

     handle_leds(data);
     data = data << 1;
     delay(delay_ms);
 
   }

      data = 0x01 << 7;
   for (int i = 0; i < num_leds; i++){
  
    tick();

     handle_leds(data);
     data = data >> 1;
     delay(delay_ms);
 
   }
   
 }


 /*
  * Passo 4
  */
 Serial.println("Passo 4 ");
 for (int k = 0; k < repeat; k++){

  data = 0x00;
  for (int i = 0; i < num_leds+1; i++){
     tick();

     handle_leds(data);
     data = (data << 1) + 1;
     delay(delay_ms);
  }
 
 }
  
 /*
  * Passo 5
  */
 Serial.println("Passo 5 ");
 for (int k = 0; k < repeat; k++){

  data = 0x00;
  for (int i = 0; i < num_leds+1; i++){
     tick();

     handle_leds(data);
     data = (data >> 1) + 0x80;
     delay(delay_ms);
  }
 
 }



 /*
  * Passo 6
  */
 Serial.println("Passo 6 ");
 for (int k = 0; k < repeat; k++){

  data = 0x01;
  for (int i = 0; i < num_leds; i++){
     tick();

     handle_leds(data);
     data = (data << 1) + 1;
     delay(delay_ms);
  }

    data = 0x80;
  for (int i = 0; i < num_leds; i++){
     tick();

     handle_leds(data);
     data = (data >> 1) + 0x80;
     delay(delay_ms);
  }
 
 }

  /*
  * Passo 7
  */
 Serial.println("Passo 7 ");
 for (int k = 0; k < repeat; k++){

  data = 0x01;
  for (int i = 0; i < num_leds; i++){
     tick();

     handle_leds(data);
     data = (data << 1) + 1;
     delay(delay_ms);
  }

    data = 0xFF;
  for (int i = 0; i < num_leds; i++){
     tick();

     handle_leds(data);
     data = (data >> 1) ;
     delay(delay_ms);
  }
 
 }

  /*
  * Passo 8
  */
 Serial.println("Passo 8 ");
 for (int k = 0; k < repeat; k++){

  
  for (int i = 0; i < 4; i++){
     tick();
     data = 0xAA;
     handle_leds(data);
     delay(delay_ms);
     data = 0x55;
     handle_leds(data);
     delay(delay_ms);
  }
 
 }


  /*
  * Passo 9
  */
 Serial.println("Passo 9 ");

 byte data1 = 0x00;
 byte data2 = 0x00;

 
 for (int k = 0; k < repeat; k++){

  data = 0x18;


  
  for (int i = 0; i < 4; i++){
     tick();
     
     handle_leds(data);
     
     data1 = 0xF0 & data;
     data2 = 0x0F & data;

     data1 = data1 << 1;
     data2 = data2 >> 1;
   
     data = data1 | data2;
     
     delay(delay_ms);

     
  }
 
 }


  /*
  * Passo 10
  */
 Serial.println("Passo 10 ");

 data1 = 0x00;
 data2 = 0x00;

 
 for (int k = 0; k < repeat; k++){

  data = 0x18;


  
  for (int i = 0; i < 4; i++){
     tick();
     
     handle_leds(data);
     
     data1 = 0xF0 & data;
     data2 = 0x0F & data;

     data1 = (data1 << 1) + 0x10;
     data2 = (data2 >> 1) + 0x08;
   
     data = data1 | data2;
     
     delay(delay_ms);

     
  }
 
 }


  /*
  * Passo 11
  */
 Serial.println("Passo 11 ");
     
 for (int k = 0; k < repeat; k++){
    tick();

    data = 0xFF;

    handle_leds(data);
    delay(delay_ms);

    data = 0x00;

    handle_leds(data);
    delay(delay_ms);
     
  
 
 }
 

/*
 * FIM
 */

}

