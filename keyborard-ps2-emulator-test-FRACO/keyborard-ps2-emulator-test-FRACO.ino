// inclusão de bibliotecas
#include "ps2dev.h"  // to emulate a PS/2 device

// criação de objeto keyboard
PS2dev keyboard(3,2);  // PS2dev object (2:data, 3:clock)

// declaração variaveis
int enabled = 0;  // pseudo variable for state of "keyboard"
unsigned char c;  //char stores data recieved from computer for KBD

void ack()
{
  //acknowledge commands
  while(keyboard.write(0xFA));
}

int keyboardcommand(int command)
{
  unsigned char val;
  switch (command)
  {
  case 0xFF: //reset
    ack();
    //the while loop lets us wait for the host to be ready
    while(keyboard.write(0xAA)!=0);
    break;
  case 0xFE: //resend
    ack();
    break;
  case 0xF6: //set defaults
    //enter stream mode
    ack();
    break;
  case 0xF5: //disable data reporting
    //FM
    enabled = 0;
    ack();
    break;
  case 0xF4: //enable data reporting
    //FM
    enabled = 1;
    ack();
    break;
  case 0xF3: //set typematic rate
    ack();
    keyboard.read(&val); //do nothing with the rate
    ack();
    break;
  case 0xF2: //get device id
    ack();
    keyboard.write(0xAB);
    keyboard.write(0x83);
    break;
  case 0xF0: //set scan code set
    ack();
    keyboard.read(&val); //do nothing with the rate
    ack();
    break;
  case 0xEE: //echo
    //ack();
    keyboard.write(0xEE);
    break;
  case 0xED: //set/reset LEDs
    ack();
    keyboard.read(&val); //do nothing with the rate
    ack();
    break;
  }
}

void setup()
{
  // send the keyboard start up
  while(keyboard.write(0xAA)!=0);
  delay(10);
 
  // initialize the serial port:
  Serial.begin(9600);
 
 
}

void loop()
{

 
  // debug to check for spikes in the sensor etc..
//  Serial.println(average);

  //if host device wants to send a command:
  if( (digitalRead(3)==LOW) || (digitalRead(2) == LOW))
                                                       {
                                                        while(keyboard.read(&c)) ;
                                                        Serial.print("Receiving: " );
                                                        Serial.println(c,HEX);
                                                        keyboardcommand(c);
                                                       }
  else
      {
        
        Serial.println("cinesio");
        // tecla enter
        keyboard.write(0x5A);
        delay(700);
        // tecla c
        keyboard.write(0x21);
        delay(10);
        // tecla i
        keyboard.write(0x43);
        delay(10);
        // tecla n
        keyboard.write(0x31);
         delay(10);
        // tecla e
        keyboard.write(0x24);
        delay(10);
        // tecla s
        keyboard.write(0x1B);
        delay(10);
        // tecla i
        keyboard.write(0x43);
        delay(10);
        // tecla o
        keyboard.write(0x44);
        delay(700);
        // tecla enter
        keyboard.write(0x5A);
                
      }

delay(5000);
 
}
