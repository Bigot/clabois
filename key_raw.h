#ifndef KEYRAW_H
#define KEYRAW_H

#include "config.h"

// transcrit les codes venus du clavier en le tableau suivant :
// 0, 1, 2 ..... 14,
// 15, 16, ......29,

#define COL1 28
#define COL2 29
#define COL3 30
#define COL4 31
#define COL5 32
#define COL6 33
#define COL7 34
#define COL8 35

#define ROW1 4
#define ROW2 5
#define ROW3 7
#define ROW4 8
#define ROW5 9
#define ROW6 10
#define ROW7 11
#define ROW8 12
#define ROW9 13
#define ROW10 14



//matrix pins
const int col_Pins[COL_NB] =  {COL1,COL2,COL3,COL4,COL5,COL6,COL7,COL8};
const int row_Pins[ROW_NB] =  {ROW1,ROW2,ROW3,ROW4,ROW5,ROW6,ROW7,ROW8, ROW9,ROW10};


static int keymap[]={
  33, 48, 64, 34, 3,
  18, 49, 63, 4, 19,
  39, 54, 70, 40, 9,
  
  24, 55, 69, 10, 25,
  35, 50, 66, 36,  5,
  20, 51, 65,  6, 21,

  37, 52, 68, 38,  7,
  22, 53, 67, 8, 23,
  41, 56, 72, 42, 11,

  26, 57, 71, 12, 27,
  50, 51, 60, 30, 54,
  55, 45, 57,  0, 15,

  43, 58, 74, 44, 13,
  28, 59, 73, 14, 29,
  31, 46, 62, 32,  1,
  
  16, 47, 61,  2, 17
};

class Keyboard_Raw {
  public:
    Keyboard_Raw() ; 
    void init();
    void init_led_pins();
    int scan(int matrix_pressed[KEY_NB]);
    void set_led(int val);
    //void led(x,y);
  private:
    int led_val;
} ;

#endif
