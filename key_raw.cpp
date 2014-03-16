#include "key_raw.h"
#include "debug.h"
#include <WProgram.h>

Keyboard_Raw::Keyboard_Raw() {}

void init_matrix_pins() {
    for (int i=0; i < ROW_NB; i++) { // 10 row
    pinMode(row_Pins[i], INPUT_PULLUP );
  }
  for (int i=0; i < COL_NB; i++) { // 8 col
    pinMode(col_Pins[i], OUTPUT );
    digitalWrite(col_Pins[i], HIGH); 
  }
}

void leds_flash(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  delay(20);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);  
  delay(20);  
}

void Keyboard_Raw::init_led_pins() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  leds_flash();
  leds_flash();  
  led_val = 0 ;
}

void Keyboard_Raw::init() {
  init_led_pins();
  init_matrix_pins();
}

void Keyboard_Raw::set_led(int value ) {
  if( value == led_val) { return; } else {
    led_val=value; 
    switch ( led_val ) {
    case 0: // KOS 
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      break; 
    case 1: //MIN
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      break; 
    case 2: //MAJ
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      break; 
    case 3: //NUM
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      break; 
    case 4:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      break; 
    case 5:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      break; 
    case 6:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      break; 
  default: 
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
    ;
    }
  }
}

int Keyboard_Raw::scan(int matrix_pressed[KEY_NB]){
  int nb =0 ;
  int index = 0 ;  
  for (int i = 0;i<COL_NB; i++) { // balayage des colonnes 
    digitalWrite(col_Pins[i], LOW); 
    delayMicroseconds(5);
    for (int k = 0;k<ROW_NB; k++) { 
      index = i*ROW_NB+k ;
      if ( !digitalRead(row_Pins[k]) ) {  
        matrix_pressed[nb] = keymap[index] ;
        nb += 1;
        debug("col : ",i,DEBUG_RAW);
        debug("  colpin : ",col_Pins[i],DEBUG_RAW);
        debug("  row : ",k,DEBUG_RAW);
        debug("  rowpin : ",row_Pins[k],DEBUG_RAW);
        debug("  index : ",index,DEBUG_RAW);
        debugln("  key : ",keymap[index],DEBUG_RAW);       
      } 
    }
    digitalWrite(col_Pins[i], HIGH); 
  }
  return nb ; 
}

