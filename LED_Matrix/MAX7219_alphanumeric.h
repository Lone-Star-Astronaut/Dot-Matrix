// header file for SPI communication between the Arduino and the MAX7219
// Written by Jacob Bassett

#ifndef MAX7219_ALPHANUMERIC_H
#define MAX7219_ALPHANUMERIC_H

#include <Arduino.h>
#include <SPI.h>

/*
extern byte A_upper[8];
extern byte B_upper[8];
extern byte C_upper[8];
extern byte D_upper[8];
extern byte E_upper[8];
extern byte F_upper[8];
extern byte G_upper[8];
extern byte H_upper[8];
extern byte I_upper[8];
extern byte J_upper[8];
extern byte K_upper[8];
extern byte L_upper[8];
extern byte M_upper[8];
extern byte N_upper[8];
extern byte O_upper[8];
extern byte P_upper[8];
extern byte Q_upper[8];
extern byte R_upper[8];
extern byte S_upper[8];
extern byte T_upper[8];
extern byte U_upper[8];
extern byte V_upper[8];
extern byte W_upper[8];
extern byte X_upper[8];
extern byte Y_upper[8];
extern byte Z_upper[8];

*/
extern byte a_lower[8];



//implement a better method here using an array of arrays to access each individual letter. 
//That way you can just numerical look up a letter.
extern byte Upper_Case[26][8];

//use this byte to perform bitwise operations to implement scrolling text
extern byte holder[8];

extern byte holder2[8];
#endif
