#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG_NOR 5
#define DEBUG_STD 4
#define DEBUG_MED 3
#define DEBUG_LOW 2
#define DEBUG_RAW 1

// #define DEBUG_LEVEL DEBUG_STD 

// debug function
void debug(const char* str, const int val,const int niv) ;
void debugln(const char* str, const int val, const int niv) ;
void debug(const char* str,const int niv) ;
void debugln(const char* str,const int niv) ;

#endif

