#include <ps2.h>

/*
 * an arduino sketch to interface with a ps/2 mouse.
 * Also uses serial protocol to talk back to the host
 * and report what it finds.
 */

/*
 * Pin 5 is the mouse data pin, pin 6 is the clock pin
 * Feel free to use whatever pins are convenient.
 */
PS2 mouse(3, 2);

const int xLed = 10;
const int yLed = 11;

int xPos = 0;
int yPos = 0;

int xBright = 128;
int yBright = 128;

const byte REQUEST_DATA = 0xeb;

int mouseRange = 255;

/*
 * initialize the mouse. Reset it, and place it into remote
 * mode, so we can get the encoder data on demand.
 */
void mouse_init()
{
  mouse.write(0xff);  // reset
  mouse.read();  // ack byte
  mouse.read();  // blank */
  mouse.read();  // blank */
  mouse.write(0xf0);  // remote mode
  mouse.read();  // ack
  delayMicroseconds(100);
}

void setup()
{

  pinMode(xLed,OUTPUT);
  pinMode(yLed,OUTPUT);
  Serial.begin(9600);
  mouse_init();
}

/*
 * get a reading from the mouse and report it back to the
 * host via the serial line.
 */
void loop()
{
  char mstat;
  char mx;
  char my;

  /* get a reading from the mouse */
  mouse.write(REQUEST_DATA);  // give me data!
  mouse.read();      // ignore ack
  mstat = mouse.read();

  if(mstat & 1) xPos = 0;
  if(mstat & 2) yPos = 0;

  mx = mouse.read();
  my = mouse.read();


  if(mx != 0 || my != 0){
    xPos = xPos + mx;
    xPos = constrain(xPos,-mouseRange,mouseRange);
    xBright =   map(xPos, -mouseRange,mouseRange,0,255);
    analogWrite(xLed,xBright);

    yPos = yPos + my;
    yPos = constrain(yPos,-mouseRange,mouseRange);
    yBright =   map(yPos, -mouseRange,mouseRange,0,255);
    analogWrite(yLed,yBright);
  }
}
