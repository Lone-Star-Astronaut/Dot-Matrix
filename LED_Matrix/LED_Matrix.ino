
//Include the SPI library:
#include <SPI.h>
//#include <math.h>
#include "MAX7219_Bassett.h"
#include "MAX7219_alphanumeric.h"

// set pin 10 as the peripheral select for the MAX7219
const int peripheralSelectPin = 10;

byte sprite_crab_body[8] = {
    B00110000,
    B01111000,
    B11111100,
    B10110111,
    B11111111,
    B01001000,
    B10110100,
    B01001011
};

byte sprite_crab_body2[8] = {
    B00110000,
    B01111000,
    B11111100,
    B10110111,
    B11111111,
    B01001000,
    B10110100,
    B10000100
};

byte output[8] = { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000 };

byte rotated[8] = { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000 };

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  while(!Serial){
    ; // wait for serial power to connect. Needed for native USB.
  }

  // set the slaveSelectPin as an output:
  pinMode(peripheralSelectPin, OUTPUT);
  
  // initialize SPI: max clk is 10MHz, but chose 2MHz
  //SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
  SPI.begin();
  // initialize MAX7219
  // LED_intensity(0x08); // roughly a 50% duty cycle
  //scan_limit(0x07);    // scan all 8 columns of matrix

  byte decode_mode_reg = 0x09;
  MAX7219_Write(decode_mode_reg, 0x00); //set no decode mode

  byte ScanLimReg = 0x0B;
  MAX7219_Write(ScanLimReg, 0x07); //Scan across all 8-digits or in this case all 8 rows (columns?)

  LED_intensity(0x01);
  // MAX7219_display_test(); 
  //delay(2000);
  normal_mode();
}


/******************************************************************
 *                        MAIN LOOP IS HERE
 ******************************************************************/
void loop() {
 // put your main code here, to run repeatedly:
  LED_intensity(0x0F);
  LEDscan();
  Serial.println("Enter text in ALL CAPS ONLY: ");
  while(Serial.available() == 0){}
  String teststr = Serial.readString();
  teststr.trim();

//*KEEP THIS CODE***********************************************************************
//Convert character array to ASCII then reference Upper_Case[] array for correct bytes
  //char Str1[] = "ILOVEJACKIE";
  // char Str1[] = teststr;
  //int myArraySize = sizeof(Str1)/sizeof(Str1[0]);

/*Copilot code*/
    char* Str1 = new char[teststr.length() + 1];
    teststr.toCharArray(Str1, teststr.length() + 1);

    int myArraySize = teststr.length() + 1;
/*end of Copilot code*/

  for(int i = 0; i < myArraySize-1; i++){
    int j = Str1[i] - 65;
    textScroll_2(Upper_Case[j]); //this is the OG code here. DONT DELETE
    
  }  
/***************************************************************************************/

delete[] Str1; // Free allocated memory
}


/*NOTE: const byte data type helps to prevent input from being altered*/
void textScroll_2(const byte input[8]){
  int j = 7;
  //WriteChar(output);
  for(int i = 0; i < 7; i++){
    output[7] = input[i];
    WriteChar(output);
    for(int i = 0; i < 7; i++){
     output[i] = output[i+1];
      }
    }
  }

/*
void rotate90(byte input[8]){
  //create variables to hold temporary values
  bool setget = false;
  byte tempByte = 0x00;
  int c;
  
  //grab a byte in 8x8 byte array
  for(int i = 0; i < 7; i++){
    tempByte = input[i];
    //tempByte = mirrorByte(tempByte);
    c = 0;
  //Read bits and set bits  
    for(int j = 7; j > 0; j--){
      setget = bitRead(tempByte, j);
      bitWrite(holder2[c], i, setget);
      c++;
      }
    }
  }*/





    /*
    switch (i){
      case 0: //move all of first byte to index 7 of all bytes in new 8x8 byte array
        //grab a bit within the single byte
        for(int j = 7; j > 0; j--){
          setget = bitRead(tempByte, j);
          bitWrite(holder2[c], i, setget);
          c++;
          } 
        break;
      case 1: //move all of first byte to index 6 of all bytes in new 8x8 byte array
        //grab a bit within the single byte
        for(int j = 7; j > 0; j--){
          setget = bitRead(tempByte, j);
          bitWrite(holder2[c], i, setget);
          c++;
          }
        break;
      case 2: //move all of first byte to index 5 of all bytes in new 8x8 byte array
        //grab a bit within the single byte
        for(int j = 7; j > 0; j--){
          setget = bitRead(tempByte, j);
          bitWrite(holder2[c], i, setget);
          c++;
          } 
        break;
      case 3: //move all of first byte to index 4 of all bytes in new 8x8 byte array
        //grab a bit within the single byte
        for(int j = 7; j > 0; j--){
          setget = bitRead(tempByte, j);
          bitWrite(holder2[c], i, setget);
          c++;
          }
        break;
      case 4: //move all of first byte to index 3 of all bytes in new 8x8 byte array
        //grab a bit within the single byte
        for(int j = 7; j > 0; j--){
          setget = bitRead(tempByte, j);
          bitWrite(holder2[c], i, setget);
          c++;
          }
        break;
      case 5: //move all of first byte to index 2 of all bytes in new 8x8 byte array
        //grab a bit within the single byte
        for(int j = 7; j > 0; j--){
          setget = bitRead(tempByte, j);
          bitWrite(holder2[c], i, setget);
          c++;
          }
        break;
      case 6: //move all of first byte to index 1 of all bytes in new 8x8 byte array
        //grab a bit within the single byte
        for(int j = 7; j > 0; j--){
          setget = bitRead(tempByte, j);
          bitWrite(holder2[c], i, setget);
          c++;
          }
        break;
      case 7: //move all of first byte to index 0 of all bytes in new 8x8 byte array
        //grab a bit within the single byte
        for(int j = 7; j > 0; j--){
          setget = bitRead(tempByte, j);
          bitWrite(holder2[c], i, setget);
          c++;
          }
        break;
        
      //default: //not sure what to do here.....
        //break;
        delay(200);
        //tempByte = 0x00;             
      }          
    }
  }*/ 


/*
void MAX7219_Write(int address, int value) {
  //take the select pin low to select the chip:

  digitalWrite(peripheralSelectPin, LOW);
  delay(5);
  // send in the address and value via SPI:
  SPI.transfer(address);
  SPI.transfer(value);
  delay(5);
  // take the select pin high to de-select the chip:
  digitalWrite(peripheralSelectPin, HIGH);
  
}


void LED_intensity(int power){
  //set the intensity of the LEDs via PWM
  //power should be a value between 0xX0 to 0xXF 
 
  //MAX7219 address for setting LED intensity
  const int intensity_register = 0x0A;
  
  //Update LED intensity
  MAX7219_Write(intensity_register, power);

}

void scan_limit(int num_dig){
  //Choose whether you want to display 1 to 8 digits
  //num_dig should be a value between 0xX0 and 0xX7
 
  //MAX7219 address for scan limit register
  const int scan_lim_reg = 0x0B;

  //Update scan limit
  MAX7219_Write(scan_lim_reg, num_dig);
  
}


void MAX7219_display_test(){
  //Use MAX7219 display test setting to turn on all LEDs

  //display test mode register
  const int test_register = 0x0F;

  //run display test for 1.5 seconds
  MAX7219_Write(test_register, 0x01);
  delay(1500);

  //exit display test mode
  MAX7219_Write(test_register, 0x00);
  
}

void shutdown_mode(){
  //set MAX7219 to shutdown mode

  const int shutdown_reg = 0x0C;
  MAX7219_Write(shutdown_reg, 0x00);

  
}

void normal_mode(){
  //set MAX7219 to a normal operating mode

  const int shutdown_reg = 0x0C;
  MAX7219_Write(shutdown_reg, 0x01);

  
}

void decode_mode_init(){
  //set MAX7219 to decode mode
  const int decode_mode_reg = 0x09;
  MAX7219_Write(decode_mode_reg, 0x00);

  
}

void cascade_mode(){

  const int no_op_reg = 0x00;
  
  
}

void LEDscan(){
//Light up a single LED and propagate through the whole 8x8 diplay

  byte RowReg = 0x01;
  byte Col = 0x01;

  
  for(int c=0; c < 8; c++){
    
    for(int i=0; i<9; i++){

      MAX7219_Write(RowReg, Col); //Turn on LED
      //delay(10);
      
      MAX7219_Write(RowReg, 0x00); //Turn off LED
      //delay(10);

      
      Col = Col << 1;
      
     
    }
    RowReg++;
    Col = 0x01;
  }
}


void WriteChar(byte myArray[]){

  byte RowReg = 0x01;
  byte currentElement;
    
    for(int i=0; i<8; i++){

      currentElement = myArray[i];
      MAX7219_Write(RowReg, currentElement); //Turn on LED
      delay(10);  
    RowReg++; 
    }
}
*/
