// header file for SPI communication between the Arduino and the MAX7219
// Written by Jacob Bassett

#ifndef MAX7219_ALPHANUMERIC_H
#define MAX7219_ALPHANUMERIC_H

#include <Arduino.h>
#include <SPI.h>

extern byte a_lower[8];



//implement a better method here using an array of arrays to access each individual letter. 
//That way you can just numerical look up a letter.
extern byte Upper_Case[58][8];

//use this byte to perform bitwise operations to implement scrolling text
extern byte holder[8];

extern byte holder2[8];
#endif
