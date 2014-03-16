#ifndef KEY_CODES_H
#define KEY_CODES_H

//#include <WProgram.h>
#include "config.h"


//
// Keyword définition
// TODO was not able to use member pointer directly included in a struct in PROGMEM
// type :
//   1 : send a caracter 
//   2 : send string
//   3 : send ALT code 
//   4 : sequence call
//   5 : send a raw key
//   6 : function call 
//   7 : function with short repeat
//  99 : null

#define KT_CAR 1
#define KT_STR 2
#define KT_ALT 3
#define KT_SEQ 4
#define KT_RAW 5
#define KT_FCT 6
#define KT_MOD 7
#define KT_MOU 8
#define KT_NUL 999


typedef struct KeyWord KeyWord;

typedef struct KeyWord  {
  int type ;
  int key ;
  char* altval ;
  char* string ;
  int fctptr ;
  const struct KeyWord* seq[KEY_SEQ_LENGTH] ;
  //   MPV_V fctptr ;

} ;

typedef struct ChordWord  {
  int value ;
  const struct KeyWord* key ;
  char* string ;
  //   MPV_V fctptr ;

} ;

//const struct KeyWord* Nullseq; 


//=====================================================================
// keyboard codes
//=====================================================================


const PROGMEM  KeyWord K_O_ENT = {   5,40,"","ENTER",0,NULL};
const PROGMEM  KeyWord K_O_ESC = {   5,41,"","ESC",0,NULL};
const PROGMEM  KeyWord K_O_INS = {   5,73,"","INSERT",0,NULL};
const PROGMEM  KeyWord K_O_BCK = {   5,42,"","BACKSPACE",0,NULL};
const PROGMEM  KeyWord K_O_TAB = {   5,43,"","TAB",0,NULL};
const PROGMEM  KeyWord K_O_SPA = {  5,44,"","space",0,NULL};
const PROGMEM  KeyWord K_O_F1_ = {   5,58,"","F1",0,NULL};
const PROGMEM  KeyWord K_O_F2_ = {   5,59,"","F2" ,0,NULL};
const PROGMEM  KeyWord K_O_F3_ = {   5,60,"","F3" ,0,NULL};
const PROGMEM  KeyWord K_O_F4_ = {   5,61,"","F4" ,0,NULL};
const PROGMEM  KeyWord K_O_F5_ = {   5,62,"","F5" ,0,NULL};
const PROGMEM  KeyWord K_O_F6_ = {   5,63,"","F6" ,0,NULL};
const PROGMEM  KeyWord K_O_F7_ = {   5,64,"","F7" ,0,NULL};
const PROGMEM  KeyWord K_O_F8_ = {   5,65,"","F8" ,0,NULL};
const PROGMEM  KeyWord K_O_F9_ = {   5,66,"","F9" ,0,NULL};
const PROGMEM  KeyWord K_O_F10 = {  5,67,"","F10" ,0,NULL};
const PROGMEM  KeyWord K_O_F11 = {  5,68,"","F11" ,0,NULL};
const PROGMEM  KeyWord K_O_F12 = {  5,69,"","F12" ,0,NULL};
const PROGMEM  KeyWord K_O_RGT = {   5,79,"","RIGHT" ,0,NULL};
const PROGMEM  KeyWord K_O_LFT = {   5,80,"","LEFT" ,0,NULL};
const PROGMEM  KeyWord K_O_DWN = {   5,81,"","DOWN" ,0,NULL};
const PROGMEM  KeyWord K_O_UP_ = {   5,82,"","UP" ,0,NULL};
const PROGMEM  KeyWord K_O_DEL = {   5,76,"","DELETE" ,0,NULL};
const PROGMEM  KeyWord K_O_END = {   5,77,"","END" ,0,NULL};
const PROGMEM  KeyWord K_O_HOM = {  5,74,"","HOME" ,0,NULL};
const PROGMEM  KeyWord K_O_PUP = {   5,75,"","PAGEUP" ,0,NULL};
const PROGMEM  KeyWord K_O_PDN = {   5,78,"","PAGEDOWN" ,0,NULL};
const PROGMEM  KeyWord K_O_NLC = {   5,83,"","NUMLOCK" ,0,NULL};

//modifiers

//#define SHIFT_MASK		0x0040
//#define ALTGR_MASK		0x0080
//#define DEADKEYS_MASK		0x0700
//#define CEDILLA_BITS		0x0400
//#define RING_ABOVE_BITS	 	0x0700
//#define RCTRL_MASK		0x0800
//#define MODIFIERKEY_CTRL        ( 0x01 | 0x8000 )
//#define MODIFIERKEY_SHIFT       ( 0x02 | 0x8000 )
//#define MODIFIERKEY_ALT         ( 0x04 | 0x8000 )
//#define MODIFIERKEY_GUI         ( 0x08 | 0x8000 )
//#define MODIFIERKEY_LEFT_CTRL   ( 0x01 | 0x8000 )
//#define MODIFIERKEY_LEFT_SHIFT  ( 0x02 | 0x8000 )
//#define MODIFIERKEY_LEFT_ALT    ( 0x04 | 0x8000 )
//#define MODIFIERKEY_LEFT_GUI    ( 0x08 | 0x8000 )
//#define MODIFIERKEY_RIGHT_CTRL  ( 0x10 | 0x8000 )
//#define MODIFIERKEY_RIGHT_SHIFT ( 0x20 | 0x8000 )
//#define MODIFIERKEY_RIGHT_ALT   ( 0x40 | 0x8000 )
//#define MODIFIERKEY_RIGHT_GUI   ( 0x80 | 0x8000 )

const PROGMEM  KeyWord K_O_01 = { 7,MODIFIERKEY_SHIFT  ,"SHIFT","",0,NULL};
const PROGMEM  KeyWord K_0_02 = { 7,MODIFIERKEY_CTRL  ,"CTRL","",0,NULL};
const PROGMEM  KeyWord K_0_03 = { 7,MODIFIERKEY_ALT  ,"ALT","",0,NULL};
const PROGMEM  KeyWord K_0_04 = { 7,MODIFIERKEY_GUI  ,"GUI","",0,NULL};
const PROGMEM  KeyWord K_0_05 = { 7,MODIFIERKEY_RIGHT_ALT  ,"RALT","",0,NULL};

const PROGMEM  KeyWord K_0_06 = { 7,GRAVE_ACCENT_BITS  ,"GRAVE_ACCENT_BITS","",0,NULL};
const PROGMEM  KeyWord K_0_07 = { 7,TILDE_BITS  ,"TILDE_BITS","",0,NULL};
const PROGMEM  KeyWord K_0_08 = { 7,DIAERESIS_BITS  ,"DIAERESIS_BITS","",0,NULL};
const PROGMEM  KeyWord K_0_09 = { 7,CIRCUMFLEX_BITS  ,"CIRCUMFLEX_BITS","",0,NULL};
//const PROGMEM  KeyWord K_0_09 = { 7,ACUTE_ACCENT_BITS ,"ACUTE_ACCENT_BITS","",0,NULL};


// Numeric // utilisation de 2 à la place de 5
const PROGMEM  KeyWord K_N___1 = {   2,89,"","1" ,0,NULL};
const PROGMEM  KeyWord K_N___2 = {   2,90,"","2" ,0,NULL};
const PROGMEM  KeyWord K_N___3 = {   2,91,"","3" ,0,NULL};
const PROGMEM  KeyWord K_N___4 = {   2,92,"","4" ,0,NULL};
const PROGMEM  KeyWord K_N___5 = {   2,93,"","5" ,0,NULL};
const PROGMEM  KeyWord K_N___6 = {   2,94,"","6" ,0,NULL};
const PROGMEM  KeyWord K_N___7 = {   2,95,"","7" ,0,NULL};
const PROGMEM  KeyWord K_N___8 = {   2,96,"","8" ,0,NULL};
const PROGMEM  KeyWord K_N___9 = {   2,97,"","9" ,0,NULL};
const PROGMEM  KeyWord K_N___0 = {   2,98,"","0" ,0,NULL};
const PROGMEM  KeyWord K_N__00 = {  2,0,"","00" ,0,NULL};

// Null Key

const PROGMEM  KeyWord K_A____ = {  2,0    ,"","",0,NULL};

// Ascii : A

const PROGMEM  KeyWord K_A___1 = {  3,0    ,"1","☺",0,NULL};
const PROGMEM  KeyWord K_A___2 = {  3,0    ,"2","☻",0,NULL};
const PROGMEM  KeyWord K_A___3 = {  3,0    ,"3","♥",0,NULL};
const PROGMEM  KeyWord K_A___4 = {  3,0    ,"4","♦",0,NULL};
const PROGMEM  KeyWord K_A___5 = {  3,0    ,"5","♣",0,NULL};
const PROGMEM  KeyWord K_A___6 = {  3,0    ,"6","♠",0,NULL};
const PROGMEM  KeyWord K_A___7 = {  3,0    ,"7","•",0,NULL};
const PROGMEM  KeyWord K_A___8 = {  3,0    ,"8","◘",0,NULL};
const PROGMEM  KeyWord K_A___9 = {  3,0    ,"9","○",0,NULL};
const PROGMEM  KeyWord K_A___A = {  3,0    ,"10","◙",0,NULL};
const PROGMEM  KeyWord K_A___B = {  3,0    ,"11","♂",0,NULL};
const PROGMEM  KeyWord K_A___C = {  3,0    ,"12","♀",0,NULL};
const PROGMEM  KeyWord K_A___D = {  3,0    ,"13","♪",0,NULL};
const PROGMEM  KeyWord K_A___E = {  3,0    ,"14","♫",0,NULL};
const PROGMEM  KeyWord K_A___F = {  3,0    ,"15","☼",0,NULL};
const PROGMEM  KeyWord K_A__10 = {  3,0    ,"16","►",0,NULL};
const PROGMEM  KeyWord K_A__11 = {  3,0    ,"17","◄",0,NULL};
const PROGMEM  KeyWord K_A__12 = {  3,0    ,"18","↕",0,NULL};
const PROGMEM  KeyWord K_A__13 = {  3,0    ,"19","‼",0,NULL};
const PROGMEM  KeyWord K_A__14 = {  3,0    ,"20","¶",0,NULL};
const PROGMEM  KeyWord K_A__15 = {  3,0    ,"21","§",0,NULL};
const PROGMEM  KeyWord K_A__16 = {  3,0    ,"22","▬",0,NULL};
const PROGMEM  KeyWord K_A__17 = {  3,0    ,"23","↨",0,NULL};
const PROGMEM  KeyWord K_A__18 = {  3,0    ,"24","↑",0,NULL};
const PROGMEM  KeyWord K_A__19 = {  3,0    ,"25","↓",0,NULL};
const PROGMEM  KeyWord K_A__1A = {  3,0    ,"26","→",0,NULL};
const PROGMEM  KeyWord K_A__1B = {  3,0    ,"27","←",0,NULL};
const PROGMEM  KeyWord K_A__1C = {  3,0    ,"28","∟",0,NULL};
const PROGMEM  KeyWord K_A__1D = {  3,0    ,"29","↔",0,NULL};
const PROGMEM  KeyWord K_A__1E = {  3,0    ,"30","▲",0,NULL};
const PROGMEM  KeyWord K_A__1F = {  3,0    ,"31","▼",0,NULL};
const PROGMEM  KeyWord K_A__20 = {  1,KEY_SPACE    ,"","",0,NULL};
const PROGMEM  KeyWord K_A__21 = {  1,KEY_SLASH    ,"","!",0,NULL};
const PROGMEM  KeyWord K_A__22 = {  1,KEY_3     ,"","\"",0,NULL};
// debut util
const PROGMEM  KeyWord K_A__23 = {  1,KEY_3 + ALTGR_MASK   ,"","#",0,NULL};
const PROGMEM  KeyWord K_A__24 = {  1,KEY_RIGHT_BRACE    ,"","$",0,NULL};
const PROGMEM  KeyWord K_A__25 = {  1,KEY_QUOTE + SHIFT_MASK   ,"","%",0,NULL};
const PROGMEM  KeyWord K_A__26 = {  1,KEY_1     ,"","&",0,NULL};
const PROGMEM  KeyWord K_A__27 = {  1,KEY_4     ,"","'",0,NULL};
const PROGMEM  KeyWord K_A__28 = {  1,KEY_5     ,"","(",0,NULL};
const PROGMEM  KeyWord K_A__29 = {  1,KEY_MINUS    ,"",")",0,NULL};
const PROGMEM  KeyWord K_A__2A = {  1,KEY_BACKSLASH    ,"","*",0,NULL};
const PROGMEM  KeyWord K_A__2B = {  1,KEY_EQUAL + SHIFT_MASK   ,"","+",0,NULL};
const PROGMEM  KeyWord K_A__2C = {  1,KEY_M     ,"",",",0,NULL};
const PROGMEM  KeyWord K_A__2D = {  1,KEY_6     ,"","-",0,NULL};
const PROGMEM  KeyWord K_A__2E = {  1,KEY_COMMA + SHIFT_MASK   ,"",".",0,NULL};
const PROGMEM  KeyWord K_A__2F = {  1,KEY_PERIOD + SHIFT_MASK   ,"","/",0,NULL};
const PROGMEM  KeyWord K_A__30 = {  1,KEY_0 + SHIFT_MASK   ,"","0",0,NULL};
const PROGMEM  KeyWord K_A__31 = {  1,KEY_1 + SHIFT_MASK   ,"","1",0,NULL};
const PROGMEM  KeyWord K_A__32 = {  1,KEY_2 + SHIFT_MASK   ,"","2",0,NULL};
const PROGMEM  KeyWord K_A__33 = {  1,KEY_3 + SHIFT_MASK   ,"","3",0,NULL};
const PROGMEM  KeyWord K_A__34 = {  1,KEY_4 + SHIFT_MASK   ,"","4",0,NULL};
const PROGMEM  KeyWord K_A__35 = {  1,KEY_5 + SHIFT_MASK   ,"","5",0,NULL};
const PROGMEM  KeyWord K_A__36 = {  1,KEY_6 + SHIFT_MASK   ,"","6",0,NULL};
const PROGMEM  KeyWord K_A__37 = {  1,KEY_7 + SHIFT_MASK   ,"","7",0,NULL};
const PROGMEM  KeyWord K_A__38 = {  1,KEY_8 + SHIFT_MASK   ,"","8",0,NULL};
const PROGMEM  KeyWord K_A__39 = {  1,KEY_9 + SHIFT_MASK   ,"","9",0,NULL};
const PROGMEM  KeyWord K_A__3A = {  1,KEY_PERIOD    ,"",":",0,NULL};
const PROGMEM  KeyWord K_A__3B = {  1,KEY_COMMA    ,"",";",0,NULL};
const PROGMEM  KeyWord K_A__3C = {  1,KEY_NON_US_100    ,"","<",0,NULL};
const PROGMEM  KeyWord K_A__3D = {  1,KEY_EQUAL    ,"","=",0,NULL};
const PROGMEM  KeyWord K_A__3E = {  1,KEY_NON_US_100 + SHIFT_MASK  ,"",">",0,NULL};
const PROGMEM  KeyWord K_A__3F = {  1,KEY_M + SHIFT_MASK   ,"","?",0,NULL};
const PROGMEM  KeyWord K_A__40 = {  1,KEY_0 + ALTGR_MASK   ,"","@",0,NULL};
const PROGMEM  KeyWord K_A__41 = {  1,KEY_Q + SHIFT_MASK   ,"","A",0,NULL};
const PROGMEM  KeyWord K_A__42 = {  1,KEY_B + SHIFT_MASK   ,"","B",0,NULL};
const PROGMEM  KeyWord K_A__43 = {  1,KEY_C + SHIFT_MASK   ,"","C",0,NULL};
const PROGMEM  KeyWord K_A__44 = {  1,KEY_D + SHIFT_MASK   ,"","D",0,NULL};
const PROGMEM  KeyWord K_A__45 = {  1,KEY_E + SHIFT_MASK   ,"","E",0,NULL};
const PROGMEM  KeyWord K_A__46 = {  1,KEY_F + SHIFT_MASK   ,"","F",0,NULL};
const PROGMEM  KeyWord K_A__47 = {  1,KEY_G + SHIFT_MASK   ,"","G",0,NULL};
const PROGMEM  KeyWord K_A__48 = {  1,KEY_H + SHIFT_MASK   ,"","H",0,NULL};
const PROGMEM  KeyWord K_A__49 = {  1,KEY_I + SHIFT_MASK   ,"","I",0,NULL};
const PROGMEM  KeyWord K_A__4A = {  1,KEY_J + SHIFT_MASK   ,"","J",0,NULL};
const PROGMEM  KeyWord K_A__4B = {  1,KEY_K + SHIFT_MASK   ,"","K",0,NULL};
const PROGMEM  KeyWord K_A__4C = {  1,KEY_L + SHIFT_MASK   ,"","L",0,NULL};
const PROGMEM  KeyWord K_A__4D = {  1,KEY_SEMICOLON + SHIFT_MASK  ,"","M",0,NULL};
const PROGMEM  KeyWord K_A__4E = {  1,KEY_N + SHIFT_MASK   ,"","N",0,NULL};
const PROGMEM  KeyWord K_A__4F = {  1,KEY_O + SHIFT_MASK   ,"","O",0,NULL};
const PROGMEM  KeyWord K_A__50 = {  1,KEY_P + SHIFT_MASK   ,"","P",0,NULL};
const PROGMEM  KeyWord K_A__51 = {  1,KEY_A + SHIFT_MASK   ,"","Q",0,NULL};
const PROGMEM  KeyWord K_A__52 = {  1,KEY_R + SHIFT_MASK   ,"","R",0,NULL};
const PROGMEM  KeyWord K_A__53 = {  1,KEY_S + SHIFT_MASK   ,"","S",0,NULL};
const PROGMEM  KeyWord K_A__54 = {  1,KEY_T + SHIFT_MASK   ,"","T",0,NULL};
const PROGMEM  KeyWord K_A__55 = {  1,KEY_U + SHIFT_MASK   ,"","U",0,NULL};
const PROGMEM  KeyWord K_A__56 = {  1,KEY_V + SHIFT_MASK   ,"","V",0,NULL};
const PROGMEM  KeyWord K_A__57 = {  1,KEY_Z + SHIFT_MASK   ,"","W",0,NULL};
const PROGMEM  KeyWord K_A__58 = {  1,KEY_X + SHIFT_MASK   ,"","X",0,NULL};
const PROGMEM  KeyWord K_A__59 = {  1,KEY_Y + SHIFT_MASK   ,"","Y",0,NULL};
const PROGMEM  KeyWord K_A__5A = {  1,KEY_W + SHIFT_MASK   ,"","Z",0,NULL};
const PROGMEM  KeyWord K_A__5B = {  1,KEY_5 + ALTGR_MASK   ,"","[",0,NULL};
const PROGMEM  KeyWord K_A__5C = {  1,KEY_8 + ALTGR_MASK   ,"","\\",0,NULL};
const PROGMEM  KeyWord K_A__5D = {  1,KEY_MINUS + ALTGR_MASK   ,"","]",0,NULL};
const PROGMEM  KeyWord K_A__5E = {  1,KEY_9 + ALTGR_MASK   ,"","^",0,NULL};
const PROGMEM  KeyWord K_A__5F = {  1,KEY_8     ,"","_",0,NULL};
const PROGMEM  KeyWord K_A__60 = {  1,GRAVE_ACCENT_BITS + KEY_SPACE  ,"","`",0,NULL};
const PROGMEM  KeyWord K_A__61 = {  1,KEY_Q     ,"","a",0,NULL};
const PROGMEM  KeyWord K_A__62 = {  1,KEY_B     ,"","b",0,NULL};
const PROGMEM  KeyWord K_A__63 = {  1,KEY_C     ,"","c",0,NULL};
const PROGMEM  KeyWord K_A__64 = {  1,KEY_D     ,""," d",0,NULL};
const PROGMEM  KeyWord K_A__65 = {  1,KEY_E     ,""," e",0,NULL};
const PROGMEM  KeyWord K_A__66 = {  1,KEY_F     ,""," f",0,NULL};
const PROGMEM  KeyWord K_A__67 = {  1,KEY_G     ,""," g",0,NULL};
const PROGMEM  KeyWord K_A__68 = {  1,KEY_H     ,""," h",0,NULL};
const PROGMEM  KeyWord K_A__69 = {  1,KEY_I     ,""," i",0,NULL};
const PROGMEM  KeyWord K_A__6A = {  1,KEY_J     ,""," j",0,NULL};
const PROGMEM  KeyWord K_A__6B = {  1,KEY_K     ,""," k",0,NULL};
const PROGMEM  KeyWord K_A__6C = {  1,KEY_L     ,""," l",0,NULL};
const PROGMEM  KeyWord K_A__6D = {  1,KEY_SEMICOLON    ,""," m",0,NULL};
const PROGMEM  KeyWord K_A__6E = {  1,KEY_N     ,""," n",0,NULL};
const PROGMEM  KeyWord K_A__6F = {  1,KEY_O     ,""," o",0,NULL};
const PROGMEM  KeyWord K_A__70 = {  1,KEY_P     ,""," p",0,NULL};
const PROGMEM  KeyWord K_A__71 = {  1,KEY_A     ,""," q",0,NULL};
const PROGMEM  KeyWord K_A__72 = {  1,KEY_R     ,""," r",0,NULL};
const PROGMEM  KeyWord K_A__73 = {  1,KEY_S     ,""," s",0,NULL};
const PROGMEM  KeyWord K_A__74 = {  1,KEY_T     ,""," t",0,NULL};
const PROGMEM  KeyWord K_A__75 = {  1,KEY_U     ,""," u",0,NULL};
const PROGMEM  KeyWord K_A__76 = { 1,KEY_V     ,""," v",0,NULL};
const PROGMEM  KeyWord K_A__77 = {  1,KEY_Z     ,""," w",0,NULL};
const PROGMEM  KeyWord K_A__78 = {  1,KEY_X     ,""," x",0,NULL};
const PROGMEM  KeyWord K_A__79 = {  1,KEY_Y     ,""," y",0,NULL};
const PROGMEM  KeyWord K_A__7A = {  1,KEY_W     ,""," z",0,NULL};
const PROGMEM  KeyWord K_A__7B = {  1,KEY_4 + ALTGR_MASK   ,""," {",0,NULL};
const PROGMEM  KeyWord K_A__7C = {  1,KEY_6 + ALTGR_MASK   ,""," |",0,NULL};
const PROGMEM  KeyWord K_A__7D = {  1,KEY_EQUAL + ALTGR_MASK   ,"","}",0,NULL};
const PROGMEM  KeyWord K_A__7E = {  1,TILDE_BITS + KEY_SPACE   ,"","~",0,NULL};
//TODO remove
const PROGMEM  KeyWord K_A__7F = {  1,KEY_BACKSPACE    ,"","",0,NULL};
//TODO remove
const PROGMEM  KeyWord K_A__A0 = {  1,KEY_SPACE    ,"","",0,NULL};
const PROGMEM  KeyWord K_A__A1 = {  3,0,"0161","¡",0,NULL};
const PROGMEM  KeyWord K_A__A2 = {  3,0,"0162","¢",0,NULL};
const PROGMEM  KeyWord K_A__A3 = {  1,KEY_RIGHT_BRACE + SHIFT_MASK  ,"","£",0,NULL};
const PROGMEM  KeyWord K_A__A4 = {  1,KEY_RIGHT_BRACE + ALTGR_MASK  ,"","¤",0,NULL};
const PROGMEM  KeyWord K_A__A5 = {  3,0,"0165","¥",0,NULL};
const PROGMEM  KeyWord K_A__A6 = {  3,0,"0166","¦",0,NULL};
const PROGMEM  KeyWord K_A__A7 = {  1,KEY_SLASH + SHIFT_MASK   ,"","§",0,NULL};
const PROGMEM  KeyWord K_A__A8 = {  1,DIAERESIS_BITS + KEY_SPACE  ,"","¨",0,NULL};
const PROGMEM  KeyWord K_A__A9 = {  3,0,"0169","©",0,NULL};
const PROGMEM  KeyWord K_A__AA = {  3,0,"0170","ª",0,NULL};
const PROGMEM  KeyWord K_A__AB = {  3,0,"0171","«",0,NULL};
const PROGMEM  KeyWord K_A__AC = {  3,0,"0172","¬",0,NULL};
const PROGMEM  KeyWord K_A__AD = {  3,0,"0173","­",0,NULL};
const PROGMEM  KeyWord K_A__AE = {  3,0,"0174","®",0,NULL};
const PROGMEM  KeyWord K_A__AF = {  3,0,"0175","¯",0,NULL};
const PROGMEM  KeyWord K_A__B0 = {  1,KEY_MINUS + SHIFT_MASK   ,"","°",0,NULL};
const PROGMEM  KeyWord K_A__B1 = {  3,0,"0177","±",0,NULL};
const PROGMEM  KeyWord K_A__B2 = {  1,KEY_TILDE    ,"","²",0,NULL};
const PROGMEM  KeyWord K_A__B3 = {  3,0,"0179","³",0,NULL};
const PROGMEM  KeyWord K_A__B4 = {  3,0,"0180","´",0,NULL};
const PROGMEM  KeyWord K_A__B5 = {  1,KEY_BACKSLASH + SHIFT_MASK  ,"","µ",0,NULL};
const PROGMEM  KeyWord K_A__B6 = {  3,0,"0182","¶",0,NULL};
const PROGMEM  KeyWord K_A__B7 = {  3,0,"0183","·",0,NULL};
const PROGMEM  KeyWord K_A__B8 = {  3,0,"0184","¸",0,NULL};
const PROGMEM  KeyWord K_A__B9 = {  3,0,"0185","¹",0,NULL};
const PROGMEM  KeyWord K_A__BA = {  3,0,"0186","º",0,NULL};
const PROGMEM  KeyWord K_A__BB = {  3,0,"0187","»",0,NULL};
const PROGMEM  KeyWord K_A__BC = {  3,0,"0188","¼",0,NULL};
const PROGMEM  KeyWord K_A__BD = {  3,0,"0189","½",0,NULL};
const PROGMEM  KeyWord K_A__BE = {  3,0,"0190","¾",0,NULL};
const PROGMEM  KeyWord K_A__BF = {  3,0,"0191","¿",0,NULL};
const PROGMEM  KeyWord K_A__C0 = {  1,GRAVE_ACCENT_BITS + KEY_Q + SHIFT_MASK ,"","À",0,NULL};
const PROGMEM  KeyWord K_A__C1 = {  3,0,"0193","Á",0,NULL};
const PROGMEM  KeyWord K_A__C2 = {  1,CIRCUMFLEX_BITS + KEY_Q + SHIFT_MASK ,"","Â",0,NULL};
const PROGMEM  KeyWord K_A__C3 = {  1,TILDE_BITS + KEY_Q + SHIFT_MASK  ,"","Ã",0,NULL};
const PROGMEM  KeyWord K_A__C4 = {  1,DIAERESIS_BITS + KEY_Q + SHIFT_MASK ,"","Ä",0,NULL};
const PROGMEM  KeyWord K_A__C5 = {  3,0,"0197","Å",0,NULL};
const PROGMEM  KeyWord K_A__C6 = {  3,0,"0198","Æ",0,NULL};
const PROGMEM  KeyWord K_A__C7 = {  3,0,"0199","Ç",0,NULL};
const PROGMEM  KeyWord K_A__C8 = {  1,GRAVE_ACCENT_BITS + KEY_E + SHIFT_MASK ,"","È",0,NULL};
const PROGMEM  KeyWord K_A__C9 = {  3,0,"0201","É",0,NULL};
const PROGMEM  KeyWord K_A__CA = {  1,CIRCUMFLEX_BITS + KEY_E + SHIFT_MASK ,"","Ê",0,NULL};
const PROGMEM  KeyWord K_A__CB = {  1,DIAERESIS_BITS + KEY_E + SHIFT_MASK ,"","Ë",0,NULL};
const PROGMEM  KeyWord K_A__CC = {  1,GRAVE_ACCENT_BITS + KEY_I + SHIFT_MASK ,"","Ì",0,NULL};
const PROGMEM  KeyWord K_A__CD = {  3,0,"0205","Í",0,NULL};
const PROGMEM  KeyWord K_A__CE = {  1,CIRCUMFLEX_BITS + KEY_I + SHIFT_MASK ,"","Î",0,NULL};
const PROGMEM  KeyWord K_A__CF = {  1,DIAERESIS_BITS + KEY_I + SHIFT_MASK ,"","Ï",0,NULL};
const PROGMEM  KeyWord K_A__D0 = {  3,0,"0208","Ð",0,NULL};
const PROGMEM  KeyWord K_A__D1 = {  1,TILDE_BITS + KEY_N + SHIFT_MASK  ,"","Ñ",0,NULL};
const PROGMEM  KeyWord K_A__D2 = {  1,GRAVE_ACCENT_BITS + KEY_O + SHIFT_MASK ,"","Ò",0,NULL};
const PROGMEM  KeyWord K_A__D3 = {  3,0,"0211","Ó",0,NULL};
const PROGMEM  KeyWord K_A__D4 = {  1,CIRCUMFLEX_BITS + KEY_O + SHIFT_MASK ,"","Ô",0,NULL};
const PROGMEM  KeyWord K_A__D5 = {  1,TILDE_BITS + KEY_O + SHIFT_MASK  ,"","Õ",0,NULL};
const PROGMEM  KeyWord K_A__D6 = {  1,DIAERESIS_BITS + KEY_O + SHIFT_MASK ,"","Ö",0,NULL};
const PROGMEM  KeyWord K_A__D7 = {  3,0,"0215","×",0,NULL};
const PROGMEM  KeyWord K_A__D8 = {  3,0,"0216","Ø",0,NULL};
const PROGMEM  KeyWord K_A__D9 = {  1,GRAVE_ACCENT_BITS + KEY_U + SHIFT_MASK ,"","Ù",0,NULL};
const PROGMEM  KeyWord K_A__DA = {  3,0,"0218","Ú",0,NULL};
const PROGMEM  KeyWord K_A__DB = {  1,CIRCUMFLEX_BITS + KEY_U + SHIFT_MASK ,"","Û",0,NULL};
const PROGMEM  KeyWord K_A__DC = {  1,DIAERESIS_BITS + KEY_U   ,"","ü",0,NULL};
const PROGMEM  KeyWord K_A__DD = {  3,0,"0221","Ý",0,NULL};
const PROGMEM  KeyWord K_A__DE = {  3,0,"0222","Þ",0,NULL};
const PROGMEM  KeyWord K_A__DF = {  3,0,"0223","ß",0,NULL};
const PROGMEM  KeyWord K_A__E0 = {  1,KEY_0     ,"","à",0,NULL};
const PROGMEM  KeyWord K_A__E1 = {  3,0,"0225","á",0,NULL};
const PROGMEM  KeyWord K_A__E2 = {  1,CIRCUMFLEX_BITS + KEY_Q   ,"","â",0,NULL};
const PROGMEM  KeyWord K_A__E3 = {  1,TILDE_BITS + KEY_Q   ,"","ã",0,NULL};
const PROGMEM  KeyWord K_A__E4 = {  1,DIAERESIS_BITS + KEY_Q   ,"","ä",0,NULL};
const PROGMEM  KeyWord K_A__E5 = {  3,0,"0229","å",0,NULL};
const PROGMEM  KeyWord K_A__E6 = {  3,0,"0230","æ",0,NULL};
const PROGMEM  KeyWord K_A__E7 = {  1,KEY_9     ,"","ç",0,NULL};
const PROGMEM  KeyWord K_A__E8 = {  1,KEY_7     ,"","è",0,NULL};
const PROGMEM  KeyWord K_A__E9 = {  1,KEY_2     ,"","é",0,NULL};
//const PROGMEM  KeyWord K_A__EA = {1,CIRCUMFLEX_BITS + KEY_E   ,"","ª",0,NULL};
const PROGMEM  KeyWord K_A__EA = {  2,0  ,"","ê",0,NULL};
const PROGMEM  KeyWord K_A__EB = {  1,DIAERESIS_BITS + KEY_E   ,"","ë",0,NULL};
const PROGMEM  KeyWord K_A__EC = {  1,GRAVE_ACCENT_BITS + KEY_I  ,"","ì",0,NULL};
const PROGMEM  KeyWord K_A__ED = {  3,0,"0237","í",0,NULL};
const PROGMEM  KeyWord K_A__EE = {  1,CIRCUMFLEX_BITS + KEY_I   ,"","î",0,NULL};
const PROGMEM  KeyWord K_A__EF = {  1,DIAERESIS_BITS + KEY_I   ,"","ï",0,NULL};
const PROGMEM  KeyWord K_A__F0 = {  3,0,"0240","ð",0,NULL};
const PROGMEM  KeyWord K_A__F1 = {  1,TILDE_BITS + KEY_N   ,"","ñ",0,NULL};
const PROGMEM  KeyWord K_A__F2 = {  1,GRAVE_ACCENT_BITS + KEY_O  ,"","ò",0,NULL};
const PROGMEM  KeyWord K_A__F3 = {  3,0,"0243","ó",0,NULL};
const PROGMEM  KeyWord K_A__F4 = {  1,CIRCUMFLEX_BITS + KEY_O   ,"","ô",0,NULL};
const PROGMEM  KeyWord K_A__F5 = {  1,TILDE_BITS + KEY_O   ,"","õ",0,NULL};
const PROGMEM  KeyWord K_A__F6 = {  1,DIAERESIS_BITS + KEY_O   ,"","ö",0,NULL};
const PROGMEM  KeyWord K_A__F7 = {  3,0,"0247","÷",0,NULL};
const PROGMEM  KeyWord K_A__F8 = {  3,0,"0248","ø",0,NULL};
const PROGMEM  KeyWord K_A__F9 = {  1,KEY_COMMA    ,"",";",0,NULL};
const PROGMEM  KeyWord K_A__FA = {  3,0,"0250","ú",0,NULL};
const PROGMEM  KeyWord K_A__FB = {  1,CIRCUMFLEX_BITS + KEY_U   ,"","û",0,NULL};
const PROGMEM  KeyWord K_A__FC = {  1,DIAERESIS_BITS + KEY_U   ,"","ü",0,NULL};
const PROGMEM  KeyWord K_A__FD = {  3,0,"0253","ý",0,NULL};
const PROGMEM  KeyWord K_A__FE = {  3,0,"0254","þ",0,NULL};
const PROGMEM  KeyWord K_A__FF = {  1,DIAERESIS_BITS + KEY_Y   ,"","ÿ",0,NULL};
const PROGMEM  KeyWord K_A20AC = {  1,KEY_E + ALTGR_MASK   ,"","€",0,NULL};

// Media Keys : M

const PROGMEM  KeyWord K_M_PRV = {  1,KEY_MEDIA_PREV_TRACK,"","Prev",0,NULL};
const PROGMEM  KeyWord K_M_PLA = {  1,KEY_MEDIA_PLAY_PAUSE,"","Play",0,NULL};
const PROGMEM  KeyWord K_M_NXT = {  1,KEY_MEDIA_NEXT_TRACK,"","Next",0,NULL};
const PROGMEM  KeyWord K_M_INC = {  1,KEY_MEDIA_VOLUME_DEC,"","Dec",0,NULL};
const PROGMEM  KeyWord K_M_DEC = {  1,KEY_MEDIA_VOLUME_INC,"","Inc",0,NULL};
const PROGMEM  KeyWord K_M_JCT = {  1,KEY_MEDIA_EJECT,"","Eject",0,NULL};

const PROGMEM  KeyWord K_M_MUT = {  1,KEY_MEDIA_EJECT,"","Mute",0,NULL};



// Ascii drawing : D

const PROGMEM  KeyWord K_D__01 = {  0,0  ,"","",0,NULL};
const PROGMEM  KeyWord K_D__02 = {  3,0  ,"176","░",0,NULL};
const PROGMEM  KeyWord K_D__03 = {  3,0  ,"177","▒",0,NULL};
const PROGMEM  KeyWord K_D__04 = {  3,0  ,"178","▓",0,NULL};
const PROGMEM  KeyWord K_D__05 = {  3,0  ,"179","│",0,NULL};
const PROGMEM  KeyWord K_D__06 = {  3,0  ,"180","┤",0,NULL};
const PROGMEM  KeyWord K_D__07 = {  3,0  ,"181","╡",0,NULL};
const PROGMEM  KeyWord K_D__08 = {  3,0  ,"182","╢",0,NULL};
const PROGMEM  KeyWord K_D__09 = {  3,0  ,"183","╖",0,NULL};
const PROGMEM  KeyWord K_D__10 = {  3,0  ,"184","╕",0,NULL};
const PROGMEM  KeyWord K_D__11 = {  3,0  ,"185","╣",0,NULL};
const PROGMEM  KeyWord K_D__12 = {  3,0  ,"186","║",0,NULL};
const PROGMEM  KeyWord K_D__13 = {  3,0  ,"187","╗",0,NULL};
const PROGMEM  KeyWord K_D__14 = {  3,0  ,"188","╝",0,NULL};
const PROGMEM  KeyWord K_D__15 = {  3,0  ,"189","╜",0,NULL};
const PROGMEM  KeyWord K_D__16 = {  3,0  ,"190","╛",0,NULL};
const PROGMEM  KeyWord K_D__17 = {  3,0  ,"191","┐",0,NULL};
const PROGMEM  KeyWord K_D__18 = {  3,0  ,"192","└",0,NULL};
const PROGMEM  KeyWord K_D__19 = {  3,0  ,"193","┴",0,NULL};
const PROGMEM  KeyWord K_D__20 = {  3,0  ,"194","┬",0,NULL};
const PROGMEM  KeyWord K_D__21 = {  3,0  ,"195","├",0,NULL};
const PROGMEM  KeyWord K_D__22 = {  3,0  ,"196","─",0,NULL};
const PROGMEM  KeyWord K_D__23 = {  3,0  ,"197","┼",0,NULL};
const PROGMEM  KeyWord K_D__24 = {  3,0  ,"198","╞",0,NULL};
const PROGMEM  KeyWord K_D__25 = {  3,0  ,"199","╟",0,NULL};
const PROGMEM  KeyWord K_D__26 = {  3,0  ,"200","╚",0,NULL};
const PROGMEM  KeyWord K_D__27 = {  3,0  ,"201","╔",0,NULL};
const PROGMEM  KeyWord K_D__28 = {  3,0  ,"202","╩",0,NULL};
const PROGMEM  KeyWord K_D__29 = {  3,0  ,"203","╦",0,NULL};
const PROGMEM  KeyWord K_D__30 = {  3,0  ,"204","╠",0,NULL};
const PROGMEM  KeyWord K_D__31 = {  3,0  ,"205","═",0,NULL};
const PROGMEM  KeyWord K_D__32 = {  3,0  ,"206","╬",0,NULL};
const PROGMEM  KeyWord K_D__33 = {  3,0  ,"207","╧",0,NULL};
const PROGMEM  KeyWord K_D__34 = {  3,0  ,"208","╨",0,NULL};
const PROGMEM  KeyWord K_D__35 = {  3,0  ,"209","╤",0,NULL};
const PROGMEM  KeyWord K_D__36 = {  3,0  ,"210","╥",0,NULL};
const PROGMEM  KeyWord K_D__37 = {  3,0  ,"211","╙",0,NULL};
const PROGMEM  KeyWord K_D__38 = {  3,0  ,"212","╘",0,NULL};
const PROGMEM  KeyWord K_D__39 = {  3,0  ,"213","╒",0,NULL};
const PROGMEM  KeyWord K_D__40 = {  3,0  ,"214","╓",0,NULL};
const PROGMEM  KeyWord K_D__41 = {  3,0  ,"215","╫",0,NULL};
const PROGMEM  KeyWord K_D__42 = {  3,0  ,"216","╪",0,NULL};
const PROGMEM  KeyWord K_D__43 = {  3,0  ,"217","┘",0,NULL};
const PROGMEM  KeyWord K_D__44 = {  3,0  ,"218","┌",0,NULL};
const PROGMEM  KeyWord K_D__45 = {  3,0  ,"219","█",0,NULL};
const PROGMEM  KeyWord K_D__46 = {  3,0  ,"220","▄",0,NULL};
const PROGMEM  KeyWord K_D__47 = {  3,0  ,"221","▌",0,NULL};
const PROGMEM  KeyWord K_D__48 = {  3,0  ,"222","▐",0,NULL};
const PROGMEM  KeyWord K_D__49 = {  3,0  ,"223","▀",0,NULL};

const PROGMEM  KeyWord K_B_32 = {  3,0  ,"32","",0,NULL};
const PROGMEM  KeyWord K_B_33 = {  3,0  ,"33","",0,NULL};
const PROGMEM  KeyWord K_B_34 = {  3,0  ,"34","",0,NULL};
const PROGMEM  KeyWord K_B_35 = {  3,0  ,"35","",0,NULL};

const PROGMEM  KeyWord K_B_254 = {  3,0  ,"254","",0,NULL};
const PROGMEM  KeyWord K_B_0129 = {  3,0  ,"0129","",0,NULL};
const PROGMEM  KeyWord K_B_127 = {  3,0  ,"127","",0,NULL};
const PROGMEM  KeyWord K_B_0153 = {  3,0  ,"0153","",0,NULL};

// Strings

const PROGMEM  KeyWord K_S_001 = {  2,0  ,"","SELECT ",0,NULL};
const PROGMEM  KeyWord K_S_002 = {  2,0  ,"","* ",0,NULL};
const PROGMEM  KeyWord K_S_003 = {  2,0  ,"","FROM ",0,NULL};
const PROGMEM  KeyWord K_S_004 = {  2,0  ,"","WHERE ",0,NULL};
const PROGMEM  KeyWord K_S_005 = {  2,0  ,"","GROUP BY ",0,NULL};
const PROGMEM  KeyWord K_S_006 = {  2,0  ,"","ORDER BY DESC ",0,NULL};
const PROGMEM  KeyWord K_S_007 = {  2,0  ,"","LEFT JOIN ON ",0,NULL};
const PROGMEM  KeyWord K_S_008 = {  2,0  ,"","UPDATE ",0,NULL};
const PROGMEM  KeyWord K_S_009 = {  2,0  ,"","SET = , ",0,NULL};
const PROGMEM  KeyWord K_S_010 = {  2,0  ,"","INSERT ",0,NULL};
const PROGMEM  KeyWord K_S_011 = {  2,0  ,"","Alexandre ",0,NULL};
const PROGMEM  KeyWord K_S_012 = {  2,0  ,"","Aurélien ",0,NULL};
const PROGMEM  KeyWord K_S_013 = {  2,0  ,"","Arsinoé ",0,NULL};
const PROGMEM  KeyWord K_S_014 = {  2,0  ,"","Aymeric ",0,NULL};
const PROGMEM  KeyWord K_S_015 = {  2,0  ,"","Arthur ",0,NULL};

const PROGMEM  KeyWord K_S_016 = {  2,0  ,"","ment",0,NULL};
const PROGMEM  KeyWord K_S_017 = {  2,0  ,"","tion",0,NULL};
const PROGMEM  KeyWord K_S_018 = {  2,0  ,"","ement",0,NULL};
const PROGMEM  KeyWord K_S_019 = {  2,0  ,"","ation",0,NULL};
const PROGMEM  KeyWord K_S_020 = {  2,0  ,"","elle",0,NULL};
const PROGMEM  KeyWord K_S_021 = {  2,0  ,"","ique",0,NULL};
const PROGMEM  KeyWord K_S_022 = {  2,0  ,"","aire",0,NULL};
const PROGMEM  KeyWord K_S_023 = {  2,0  ,"","omme",0,NULL};
const PROGMEM  KeyWord K_S_024 = {  2,0  ,"","pour",0,NULL};
const PROGMEM  KeyWord K_S_025 = {  2,0  ,"","leur",0,NULL};
const PROGMEM  KeyWord K_S_026 = {  2,0  ,"","euse",0,NULL};
const PROGMEM  KeyWord K_S_027 = {  2,0  ,"","ille",0,NULL};
// limiters

const PROGMEM  KeyWord K_L___1 = {  4,0,"","[]",0,{     &K_A__5B,&K_A__5D,&K_O_LFT  }};
const PROGMEM  KeyWord K_L___2 = {  4,0,"","<>",0,{     &K_A__3C,&K_A__3E,&K_O_LFT  }};
const PROGMEM  KeyWord K_L___3 = {  4,0,"","()",0,{     &K_A__28,&K_A__29,&K_O_LFT  }};
const PROGMEM  KeyWord K_L___4 = {  4,0,"","{}",0,{     &K_A__7B,&K_A__7D,&K_O_LFT  }};
const PROGMEM  KeyWord K_L___5 = {  4,0,"","«»",0,{     &K_A__AB,&K_A__BB,&K_O_LFT  }};
const PROGMEM  KeyWord K_L___6 = {  4,0,"","\"\"",0,{   &K_A__22,&K_A__22,&K_O_LFT  }};

// Program

const PROGMEM  KeyWord K_P_000 = {  6,0  ,"","" ,0,NULL} ;  
const PROGMEM  KeyWord K_P_MAJ = {  6,0  ,"","" ,1,NULL} ;  
const PROGMEM  KeyWord K_P_NUM = {  6,0  ,"","" ,2,NULL} ;  
const PROGMEM  KeyWord K_P_SPE = {  6,0  ,"","" ,3,NULL} ;  
const PROGMEM  KeyWord K_P_MIN = {  6,0  ,"","" ,4,NULL} ;  
const PROGMEM  KeyWord K_P_KOS = {  6,0  ,"","" ,5,NULL} ;  
const PROGMEM  KeyWord K_P_MOS = {  6,0  ,"","" ,6,NULL} ;  
const PROGMEM  KeyWord K_P_CTR = {  6,0  ,"","" ,7,NULL} ;  
const PROGMEM  KeyWord K_P_ALT = {  6,0  ,"","" ,8,NULL} ;  
const PROGMEM  KeyWord K_P_SHT = {  6,0  ,"","" ,9,NULL} ;  
const PROGMEM  KeyWord K_P_GUI = {  6,0  ,"","" ,10,NULL} ;  
const PROGMEM  KeyWord K_P_AGR = {  6,0  ,"","" ,11,NULL} ;  
const PROGMEM  KeyWord K_P_ACC = {  6,0  ,"","" ,12,NULL} ;  
const PROGMEM  KeyWord K_P_ATA = {  6,0  ,"","" ,13,NULL} ;  
const PROGMEM  KeyWord K_P_014 = {  6,0  ,"","" ,14,NULL} ;  
const PROGMEM  KeyWord K_P_015 = {  6,0  ,"","" ,15,NULL} ;  
const PROGMEM  KeyWord K_P_C_C = {  6,0  ,"","" ,16,NULL} ;    
const PROGMEM  KeyWord K_P_C_V = {  6,0  ,"","" ,17,NULL} ;  
const PROGMEM  KeyWord K_P_C_Z = {  6,0  ,"","" ,18,NULL} ;  
const PROGMEM  KeyWord K_P_C_X = {  6,0  ,"","" ,19,NULL} ;  
const PROGMEM  KeyWord K_P_CAD = {  6,0  ,"","" ,20,NULL} ;  
const PROGMEM  KeyWord K_P_021 = {  6,0  ,"","" ,21,NULL} ;  
const PROGMEM  KeyWord K_P_022 = {  6,0  ,"","" ,22,NULL} ;  
const PROGMEM  KeyWord K_P_LM_ = {  8,0  ,"","" ,23,NULL} ;  
const PROGMEM  KeyWord K_P_RM_ = {  8,0  ,"","" ,24,NULL} ;  
const PROGMEM  KeyWord K_P_UM_ = {  8,0  ,"","" ,25,NULL} ;  
const PROGMEM  KeyWord K_P_DM_ = {  8,0  ,"","" ,26,NULL} ;  
const PROGMEM  KeyWord K_P_LLM = {  8,0  ,"","" ,27,NULL} ;  
const PROGMEM  KeyWord K_P_RRM = {  8,0  ,"","" ,28,NULL} ;  
const PROGMEM  KeyWord K_P_UUM = {  8,0  ,"","" ,29,NULL} ;  
const PROGMEM  KeyWord K_P_DDM = {  8,0  ,"","" ,30,NULL} ;  
const PROGMEM  KeyWord K_P_LUM = {  8,0  ,"","" ,31,NULL} ;  
const PROGMEM  KeyWord K_P_RUM = {  8,0  ,"","" ,32,NULL} ;  
const PROGMEM  KeyWord K_P_LDM = {  8,0  ,"","" ,33,NULL} ;  
const PROGMEM  KeyWord K_P_RDM = {  8,0  ,"","" ,34,NULL} ;  
const PROGMEM  KeyWord K_P_SUP = {  7,0  ,"","" ,35,NULL} ;  
const PROGMEM  KeyWord K_P_SDO = {  7,0  ,"","" ,36,NULL} ;    
const PROGMEM  KeyWord K_P_LCM = {  8,0  ,"","" ,37,NULL} ;  
const PROGMEM  KeyWord K_P_MCM = {  8,0  ,"","" ,38,NULL} ;  
const PROGMEM  KeyWord K_P_RCM = {  8,0  ,"","" ,39,NULL} ;  
const PROGMEM  KeyWord K_P_DES = {  7,0  ,"","" ,40,NULL} ;  
const PROGMEM  KeyWord K_P_C_A = {  7,0  ,"","" ,41,NULL} ;  
const PROGMEM  KeyWord K_P_DSK = {  7,0  ,"","" ,42,NULL} ;  

const PROGMEM  KeyWord K_P_MNG = {  1, KEY_E + SHIFT_MASK ,"","MANAGER",0,NULL};
const PROGMEM  KeyWord K_P_EXP = {  1, KEY_E + SHIFT_MASK ,"","EXPLORER",0,NULL};

const int KEY_QS = KEY_Q + SHIFT_MASK ;
const int KEY_ES = KEY_E + SHIFT_MASK ;
const int KEY_IS = KEY_I + SHIFT_MASK ;
const int KEY_OS = KEY_O + SHIFT_MASK ;
const int KEY_US = KEY_U + SHIFT_MASK ;
const int KEY_CS = KEY_C + SHIFT_MASK ;

// accents tables

static const int nb_accent_a=5;
static const PROGMEM KeyWord* Keys_A[nb_accent_a] = {   &K_A__C2,&K_A__C4,&K_A__C0,&K_A__C3,&K_A__41};
static const PROGMEM KeyWord* Keys_a[nb_accent_a] = {   &K_A__E2,&K_A__E4,&K_A__E0,&K_A__E3,&K_A__61};
static const int nb_accent_e=5;
static const PROGMEM KeyWord* Keys_e[nb_accent_e] = {   &K_A__EB,&K_A__EA,&K_A__E9,&K_A__E8,&K_A__65};
static const PROGMEM KeyWord* Keys_E[nb_accent_e] = {   &K_A__CB,&K_A__CA,&K_A__C9,&K_A__C8,&K_A__45};
static const int nb_accent_i=5;
static const PROGMEM KeyWord* Keys_i[nb_accent_i] = {   &K_A__EE,&K_A__EF,&K_A__EC,&K_A__ED,&K_A__69};
static const PROGMEM KeyWord* Keys_I[nb_accent_i] = {   &K_A__CE,&K_A__CF,&K_A__CC,&K_A__CD,&K_A__49};
static const int nb_accent_o=5;
static const PROGMEM KeyWord* Keys_o[nb_accent_o] = {   &K_A__F4,&K_A__F6,&K_A__F2,&K_A__F5,&K_A__6F};
static const PROGMEM KeyWord* Keys_O[nb_accent_o] = {   &K_A__D4,&K_A__D6,&K_A__D2,&K_A__D5,&K_A__4F};
static const int nb_accent_u=5;
static const PROGMEM KeyWord* Keys_u[nb_accent_u] = {   &K_A__FB,&K_A__FC,&K_A__F9,&K_A__FA,&K_A__75};
static const PROGMEM KeyWord* Keys_U[nb_accent_u] = {   &K_A__DB,&K_A__DC,&K_A__D9,&K_A__DA,&K_A__55};
static const int nb_accent_c=2;
static const PROGMEM KeyWord* Keys_c[nb_accent_c] = {   &K_A__E7,&K_A__63};
static const PROGMEM KeyWord* Keys_C[nb_accent_c] = {   &K_A__C7,&K_A__43};




static const KeyWord* ALL_keys[] = { 
  };


#endif
