
#include "MAX7219_Bassett.h"
#include "MAX7219_alphanumeric.h"

const int peripheralSelectPin = 10;

void MAX7219_Write(byte address, byte value) {
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
  //Use MAX7219 dusplay test setting to turn on all LEDs

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

/*
void WriteChar(byte myArray[]){

  byte RowReg = 0x01;
  byte currentElement;
    
  for(int i=0; i<8; i++){
    currentElement = myArray[i];
    MAX7219_Write(RowReg, currentElement); //Turn on LED
    delay(10);  
    RowReg++; 
    }
}*/



//***** new version to fix hardware mistake*********
void WriteChar(byte myArray[]){

  byte RowReg = 0x01;
  byte currentElement;
  byte theMirror = 0;
    
    for(int i=0; i<8; i++){
      currentElement = myArray[i]; 
      //currentElement = holder2[i]; 
      theMirror = mirrorByte(currentElement);     
      MAX7219_Write(RowReg, theMirror); //Turn on LED
      delay(10);  
      RowReg++; 
      }
}

//AI written function to mirror bytes
byte mirrorByte(byte b) {
  byte mirrored = 0;
  for (int i = 0; i < 8; i++) {
    mirrored |= ((b >> i) & 0x01) << (7 - i);
  }
    return mirrored;
}

void mirrorByteArray(byte b[]){
  byte currentElement;
  byte theMirror = 0;
    
    for(int i=0; i<8; i++){
      currentElement = b[i]; 
      theMirror = mirrorByte(currentElement);     
      b[i] = theMirror;
      }
  
  }


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
  }

/*
void cascade_mode(){

  const int no_op_reg = 0x00;
  
}*/
