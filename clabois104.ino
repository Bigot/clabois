#include "debug.h"
#include <WProgram.h>
#include "config.h"
#include "key_codes.h"
#include "key_emit.h"
// #include "key_analysis.h"
#include "key_raw.h"

//=====================================================================
// pin definition for a teensy 2 ++
//=====================================================================
//startup led
//const int led_Pin = 19; 

//=====================================================================
// variables
//=====================================================================

//unsigned long time_matrix[KEY_NB];
//unsigned long time_matrix_pressed[KEY_NB];
//keypressed matrix_pressed[KEY_NB];

int key_pressed[KEY_NB];
int nb_pressed =0 ;
int index = 0 ;

// loopdelay
int loopDelay = 1 ;
unsigned long datetime ;

//=====================================================================
// objects
//=====================================================================

Keyboard_emitter kbdemit ; 
Keyboard_Raw kbdraw ; 

//=====================================================================
// Setup function
//=====================================================================

void setup() {
  Serial.begin(57600);
  kbdraw.init();
  kbdemit.init();
  debugln("init clabois",DEBUG_STD);
}

//=====================================================================
// main loop
//=====================================================================

void loop() {
  debugln("loop",DEBUG_RAW);

  /*
  enregistrement de la date
  balayage de la matrice
    si touche enfoncée, enregistrement de la date dans la tableau des touches active
  */
  datetime = millis();
  debugln("scan",DEBUG_RAW);

  nb_pressed = kbdraw.scan(key_pressed);
  debugln("update",DEBUG_RAW);
  kbdemit.update_key_state(key_pressed,nb_pressed,datetime);
  debugln("emit",DEBUG_RAW);
  kbdemit.emit();
  kbdraw.set_led(kbdemit.get_led());
}



