// header file for SPI communication between the Arduino and the MAX7219
// Written by Jacob Bassett

#ifndef MAX7219_BASSETT_H
#define MAX7219_BASSETT_H

#include <Arduino.h>
#include <SPI.h>

void MAX7219_Write(byte address, byte value);

void LED_intensity(int power);

void scan_limit(int num_dig);

void MAX7219_display_test();

void shutdown_mode();

void normal_mode();

void decode_mode_init();

void cascade_mode();

void LEDscan();

void WriteChar(byte myArray[]);

byte mirrorByte(byte b);

void mirrorByteArray(byte b[8]);

void rotate90(byte input[8]);
#endif 
