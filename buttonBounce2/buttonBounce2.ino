
#include <Bounce2.h>

#define BUTTON_PIN 2
#define LED_PIN 13

bool toggle = LOW;
int count = 0;

// Instantiate a Bounce object
Bounce debouncer = Bounce(); 

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN,INPUT);

  // After setting up the button, setup the Bounce instance :
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(50); // interval in ms

  //Setup the LED :
  pinMode(LED_PIN,OUTPUT);

}

void loop() {
  // Update the Bounce instance :
  debouncer.update();

  // Get the updated value :
  int value = debouncer.read();

  // Turn on or off the LED as determined by the state :
 if(value){
  toggle = !toggle;
  digitalWrite(LED_PIN,toggle);

  count++;
  Serial.println(count);
 }

}


