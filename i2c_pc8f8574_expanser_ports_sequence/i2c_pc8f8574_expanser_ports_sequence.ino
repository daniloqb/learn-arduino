// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#define IC_ADDR 0x27

#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop() {
  Wire.beginTransmission(IC_ADDR); // transmit to device #8
  
  Wire.write(x | x << 4);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  x++;

  x %= 16;
  
  delay(500);
}
