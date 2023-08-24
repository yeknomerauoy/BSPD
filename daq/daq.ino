// Wire Peripheral Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI Peripheral device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
char c[32];
int n=0;

void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  n=0;
  while(0 < Wire.available()) // loop through all but the last
  {
    c[n] = Wire.read();
    n++; // receive byte as a character
  }
  Serial.println(c);
  for(int i=n; i<n+4; i++)c[i]= 1+c[i-1];
  Wire.beginTransmission(4);
  Wire.write(c);
  Wire.endTransmission();
  Serial.println(c);
  delay(500);
}