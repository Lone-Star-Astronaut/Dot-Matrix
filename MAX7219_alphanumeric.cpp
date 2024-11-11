#include "MAX7219_alphanumeric.h"

/*
//Upper case letters
byte A_upper[8] = { B00011000, B00100100, B01000010, B01000010, B01111110, B01000010, B01000010, B01000010 }; // A
byte B_upper[8] = { B11111100, B10000010, B10000010, B11111100, B10000010, B10000010, B11111100, B00000000 }; // B
byte C_upper[8] = { B01111100, B10000010, B10000000, B10000000, B10000000, B10000010, B01111100, B00000000 }; // C
byte D_upper[8] = { B11111100, B10000010, B10000010, B10000010, B10000010, B10000010, B11111100, B00000000 }; // D
byte E_upper[8] = { B11111110, B10000000, B10000000, B11111100, B10000000, B10000000, B11111110, B00000000 }; // E
byte F_upper[8] = { B11111110, B10000000, B10000000, B11111100, B10000000, B10000000, B10000000, B00000000 }; // F
byte G_upper[8] = { B01111100, B10000100, B10000000, B10111100, B10000100, B10000100, B01111100, B00000000 }; // G
byte H_upper[8] = { B10000010, B10000010, B10000010, B11111110, B10000010, B10000010, B10000010, B00000000 }; // H
byte I_upper[8] = { B11111100, B00100000, B00100000, B00100000, B00100000, B00100000, B11111100, B00000000 }; // I
byte J_upper[8] = { B11111000, B00010000, B00010000, B00010000, B00010000, B10010000, B11100000, B00000000 }; // J
byte K_upper[8] = { B10000100, B10001000, B10010000, B11100000, B10010000, B10001000, B10000100, B00000000 }; // K
byte L_upper[8] = { B10000000, B10000000, B10000000, B10000000, B10000000, B10000000, B11111110, B00000000 }; // L
byte M_upper[8] = { B10000010, B11000110, B10101010, B10010010, B10000010, B10000010, B10000010, B00000000 }; // M
byte N_upper[8] = { B10000010, B11000010, B10100010, B10010010, B10001010, B10000110, B10000010, B00000000 }; // N
byte O_upper[8] = { B01111100, B10000010, B10000010, B10000010, B10000010, B10000010, B01111100, B00000000 }; // O
byte P_upper[8] = { B11111100, B10000010, B10000010, B11111100, B10000000, B10000000, B10000000, B00000000 }; // P
byte Q_upper[8] = { B01111100, B10000010, B10000010, B10000010, B10010010, B10001010, B01110100, B00000000 }; // Q
byte R_upper[8] = { B11111100, B10000010, B10000010, B11111100, B10010000, B10001000, B10000100, B00000000 }; // R
byte S_upper[8] = { B01111100, B10000010, B10000000, B01111100, B00000010, B10000010, B01111100, B00000000 }; // S
byte T_upper[8] = { B11111100, B00100000, B00100000, B00100000, B00100000, B00100000, B00100000, B00000000 }; // T
byte U_upper[8] = { B10000010, B10000010, B10000010, B10000010, B10000010, B10000010, B01111100, B00000000 }; // U
byte V_upper[8] = { B10000010, B10000010, B10000010, B10000010, B10000010, B01000100, B00111000, B00000000 }; // V
byte W_upper[8] = { B10000010, B10000010, B10000010, B10010010, B10101010, B11000110, B10000010, B00000000 }; // W
byte X_upper[8] = { B10000010, B10000010, B01000100, B00111000, B01000100, B10000010, B10000010, B00000000 }; // X
byte Y_upper[8] = { B10000010, B10000010, B01000100, B00111000, B00010000, B00010000, B00010000, B00000000 }; // Y
byte Z_upper[8] = { B11111110, B00000010, B00000100, B00011000, B00100000, B01000000, B11111110, B00000000 }; // Z

*/

//implement a better method here using an array of arrays to access each individual letter. 
//That way you can just numerically look up a letter.
byte Upper_Case[26][8] = {{ B00011000, B00100100, B01000010, B01000010, B01111110, B01000010, B01000010, B01000010 }, //A
                          { B11111100, B10000010, B10000010, B11111100, B10000010, B10000010, B11111100, B00000000 }, //B
                          { B01111100, B10000010, B10000000, B10000000, B10000000, B10000010, B01111100, B00000000 }, //C
                          { B11111100, B10000010, B10000010, B10000010, B10000010, B10000010, B11111100, B00000000 }, //D
                          { B11111110, B10000000, B10000000, B11111100, B10000000, B10000000, B11111110, B00000000 }, //E
                          { B11111110, B10000000, B10000000, B11111100, B10000000, B10000000, B10000000, B00000000 }, //F
                          { B01111100, B10000100, B10000000, B10111100, B10000100, B10000100, B01111100, B00000000 }, //G
                          { B10000010, B10000010, B10000010, B11111110, B10000010, B10000010, B10000010, B00000000 }, //H
                          { B11111100, B00100000, B00100000, B00100000, B00100000, B00100000, B11111100, B00000000 }, //I
                          { B11111000, B00010000, B00010000, B00010000, B00010000, B10010000, B11100000, B00000000 }, //J
                          { B10000100, B10001000, B10010000, B11100000, B10010000, B10001000, B10000100, B00000000 }, //K
                          { B10000000, B10000000, B10000000, B10000000, B10000000, B10000000, B11111110, B00000000 }, //L
                          { B10000010, B11000110, B10101010, B10010010, B10000010, B10000010, B10000010, B00000000 }, //M
                          { B10000010, B11000010, B10100010, B10010010, B10001010, B10000110, B10000010, B00000000 }, //N
                          { B01111100, B10000010, B10000010, B10000010, B10000010, B10000010, B01111100, B00000000 }, //O
                          { B11111100, B10000010, B10000010, B11111100, B10000000, B10000000, B10000000, B00000000 }, //P
                          { B01111100, B10000010, B10000010, B10000010, B10010010, B10001010, B01110100, B00000000 }, //Q
                          { B11111100, B10000010, B10000010, B11111100, B10010000, B10001000, B10000100, B00000000 }, //R
                          { B01111100, B10000010, B10000000, B01111100, B00000010, B10000010, B01111100, B00000000 }, //S
                          { B11111100, B00100000, B00100000, B00100000, B00100000, B00100000, B00100000, B00000000 }, //T
                          { B10000010, B10000010, B10000010, B10000010, B10000010, B10000010, B01111100, B00000000 }, //U
                          { B10000010, B10000010, B10000010, B10000010, B10000010, B01000100, B00111000, B00000000 }, //V
                          { B10000010, B10000010, B10000010, B10010010, B10101010, B11000110, B10000010, B00000000 }, //W
                          { B10000010, B10000010, B01000100, B00111000, B01000100, B10000010, B10000010, B00000000 }, //X
                          { B10000010, B10000010, B01000100, B00111000, B00010000, B00010000, B00010000, B00000000 }, //Y
                          { B11111110, B00000010, B00000100, B00011000, B00100000, B01000000, B11111110, B00000000 }  //Z                       
                          };

byte holder[8] = { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000 };

byte holder2[8] = { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000 };
