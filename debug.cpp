#include "debug.h"
#include "WProgram.h"
#include "config.h"

void level(int niv) {
  switch (niv) { 
    case DEBUG_STD:
      Serial.print("STD# ");
      break; 
    case DEBUG_LOW:
      Serial.print("LOW# ");
      break; 
    case DEBUG_MED:
      Serial.print("MED# ");
      break; 
    case DEBUG_RAW:
      Serial.print("RAW# ");
      break;
    default:
      Serial.print("UNK# ");
  }
}

// debug function
void debug(const char* str, const int val, const int niv ) {
  if ( niv >= DEBUG_LEVEL ) {
    level(niv);
    Serial.print(str);
    Serial.print(val); 
    Serial.print(" ");    
  }
}

void debugln(const char* str, const int val, const int niv ) {
  if ( niv >= DEBUG_LEVEL ) {
    level(niv);
    Serial.print(str);
    Serial.println(val);
    Serial.print(" ");        
  }
}

void debug(const char* str, const int niv) {
  if ( niv >= DEBUG_LEVEL ) {
    level(niv);
    Serial.print(str);
    Serial.print(" ");        
  }
}

void debugln(const char* str, const int niv) {
  if ( niv >= DEBUG_LEVEL ) {
    level(niv);
    Serial.println(str);
    Serial.print(" ");        
  }
}
