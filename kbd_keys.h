#ifndef KBD_KEYS_H
#define KBD_KEYS_H

//#include <WProgram.h>
#include "config.h"
#include "key_codes.h"
#include "key_emit.h"

#define PAGE_MIN 1
#define PAGE_MAJ 2
#define PAGE_NUM 3
#define PAGE_SPE 4
#define PAGE_DES 5
#define PAGE_MOS 6
#define PAGE_KOS 0
#define NB_PAGES 7
#define NB_CHORD 24


//===================================================
// Main Key pages
//===================================================

static const PROGMEM KeyWord* KBD_MIN_Keys[] = {
  &K_A__A7,&K_L___1,&K_L___4,&K_L___5,&K_L___3 ,
  &K_L___6,&K_L___2,&K_A__7C,&K_A__23,&K_A__40,
  &K_A__3F,&K_A__21,&K_A__24,&K_A__5F,&K_A__26,
  
  &K_P_ALT,&K_A__62,&K_A__E9,&K_A__70,&K_A__6F,
  &K_A__7A,&K_O_HOM,&K_O_UP_,&K_O_PUP,&K_A__2D,
  &K_A__76,&K_A__64,&K_A__6C,&K_A__6A,&K_A__77,  

  &K_O_ESC,&K_A__61,&K_A__75,&K_A__69,&K_A__65,
  &K_A__2C,&K_O_LFT,&K_O_DWN,&K_O_RGT,&K_A__63,
  &K_A__74,&K_A__73,&K_A__72,&K_A__6E,&K_A__6D,
  
  &K_P_AGR,&K_A__E0,&K_A__79,&K_A__78,&K_A__2E,
  &K_A__6B,&K_O_END,&K_P_MOS,&K_O_PDN,&K_A__27,
  &K_A__71,&K_A__67,&K_A__68,&K_A__66,&K_A__E7,
  
  &K_P_NUM,&K_A____,&K_P_GUI,&K_P_ACC,&K_O_BCK,
  &K_O_DEL,&K_P_MAJ,&K_P_CTR,&K_P_KOS,&K_O_SPA,
  &K_O_ENT,&K_P_KOS,&K_O_TAB,&K_A____,&K_P_SPE
};
// 

//===================================================
static const PROGMEM KeyWord* KBD_MAJ_Keys[] = { 
  &K_A__A7,&K_L___1,&K_L___4,&K_L___5,&K_L___3,
  &K_L___6,&K_L___2,&K_A__7C,&K_A__23,&K_A__40,
  &K_A__3F,&K_A__21,&K_A__24,&K_A__5F,&K_A__26,
  
  &K_P_ALT,&K_A__42,&K_A__C9,&K_A__50,&K_A__4F,
  &K_A__57,&K_O_HOM,&K_O_UP_,&K_O_PUP,&K_A__2D,
  &K_A__56,&K_A__44,&K_A__4C,&K_A__4A,&K_A__5A,  

  &K_O_ESC,&K_A__41,&K_A__55,&K_A__49,&K_A__45,
  &K_A__3B,&K_O_LFT,&K_O_DWN,&K_O_RGT,&K_A__43,
  &K_A__54,&K_A__53,&K_A__52,&K_A__4E,&K_A__4D,
  
  &K_P_AGR,&K_A__C0,&K_A__59,&K_A__58,&K_A__3A,
  &K_A__4B,&K_O_END,&K_P_MOS,&K_O_PDN,&K_A__27,
  &K_A__51,&K_A__47,&K_A__48,&K_A__46,&K_A__C7,
  
  &K_P_NUM,&K_A____,&K_P_GUI,&K_P_ACC,&K_O_BCK,
  &K_O_DEL,&K_P_KOS,&K_P_CTR,&K_P_MIN,&K_O_SPA,
  &K_O_ENT,&K_P_KOS,&K_O_TAB,&K_A____,&K_P_SPE
};


//=================================================== 
static const PROGMEM KeyWord* KBD_NUM_Keys[] = { 
  &K_P_021,&K_A____,&K_A____,&K_A____,&K_A____,
  &K_A____,&K_A____,&K_A____,&K_A____,&K_A__2F,  
  &K_A__25,&K_A__5E,&K_A__F7,&K_A__B1,&K_A____,

  &K_P_ALT,&K_A__BC,&K_A__BD,&K_A__BE,&K_A__D8,
  &K_A____,&K_O_HOM,&K_O_UP_,&K_O_PUP,&K_A__2A,
  &K_N___7,&K_N___8,&K_N___9,&K_A__3D,&K_A__3E,

  &K_O_ESC,&K_A__24,&K_A__A3,&K_A__A2,&K_A20AC,
  &K_A__A5,&K_O_LFT,&K_O_DWN,&K_O_RGT,&K_A__2D,  
  &K_N___4,&K_N___5,&K_N___6,&K_N___0,&K_N__00,

  &K_P_AGR,&K_A__B9,&K_A__B2,&K_A__B3,&K_A__B0,
  &K_A__AA,&K_O_END,&K_P_MOS,&K_O_PDN,&K_A__2B,
  &K_N___1,&K_N___2,&K_N___3,&K_A__2E,&K_A__3C,

  &K_P_NUM,&K_A____,&K_P_GUI,&K_P_DES,&K_O_BCK,
  &K_O_DEL,&K_P_MAJ,&K_P_CTR,&K_P_MIN,&K_O_SPA,
  &K_O_ENT,&K_P_KOS,&K_O_TAB,&K_A__2C,&K_P_SPE  

};

//===================================================
static const PROGMEM KeyWord* KBD_SPE_Keys[] = {
  &K_P_021,&K_A____,&K_A____,&K_A__16,&K_A__AF,
  &K_A__14,&K_A__A6,&K_A__7C,&K_A__23,&K_A__5B,  
  &K_A__3F,&K_A__21,&K_A__24,&K_A__5F,&K_A__5D,

  &K_P_ALT,&K_A____,&K_A____,&K_A____,&K_A____,
  &K_A____,&K_O_HOM,&K_O_UP_,&K_O_PUP,&K_A__7B,
  &K_A__11,&K_A__1E,&K_A__1F,&K_A__10,&K_A__7D,

  &K_O_ESC,&K_A____,&K_A____,&K_A____,&K_A____,
  &K_A____,&K_O_LFT,&K_O_DWN,&K_O_RGT,&K_A__28,  
  &K_A__1B,&K_A__18,&K_A__19,&K_A__1A,&K_A__29,

  &K_P_AGR,&K_A____,&K_A____,&K_A____,&K_A____,
  &K_A__7E,&K_O_END,&K_P_MOS,&K_O_PDN,&K_A__AB,
  &K_A__5C,&K_A___B,&K_A___C,&K_A__2F,&K_A__BB,

  &K_P_NUM,&K_A____,&K_P_GUI,&K_P_DES,&K_O_BCK,
  &K_O_DEL,&K_P_MAJ,&K_P_CTR,&K_P_MIN,&K_O_SPA,
  &K_O_ENT,&K_P_KOS,&K_O_TAB,&K_A____,&K_P_SPE  
};

//===================================================
static const PROGMEM KeyWord* KBD_DES_Keys[] = {
  &K_A___F,&K_D__47,&K_D__46,&K_D__49,&K_D__48,
  &K_D__45,&K_D__04,&K_D__03,&K_D__02,&K_A___C,  
  &K_D__22,&K_D__12,&K_D__31,&K_D__05,&K_A___B,

  &K_D__40,&K_D__36,&K_D__09,&K_D__44,&K_D__20,
  &K_D__17,&K_O_HOM,&K_O_UP_,&K_O_PUP,&K_D__27,
  &K_D__29,&K_D__13,&K_D__39,&K_D__35,&K_D__10,

  &K_D__25,&K_D__41,&K_D__08,&K_D__21,&K_D__23,
  &K_D__06,&K_O_LFT,&K_O_DWN,&K_O_RGT,&K_D__30,  
  &K_D__32,&K_D__11,&K_D__24,&K_D__42,&K_D__07,

  &K_D__37,&K_D__34,&K_D__15,&K_D__18,&K_D__19,
  &K_D__43,&K_O_END,&K_P_MOS,&K_O_PDN,&K_D__26,
  &K_D__28,&K_D__14,&K_D__38,&K_D__33,&K_D__16,

  &K_P_NUM,&K_A__AD,&K_P_GUI,&K_A____,&K_O_BCK,
  &K_O_DEL,&K_P_MAJ,&K_P_CTR,&K_P_MIN,&K_O_SPA,
  &K_O_ENT,&K_P_KOS,&K_O_TAB,&K_A____,&K_P_SPE  
};
//===================================================
static const PROGMEM KeyWord* KBD_MOS_Keys[] = {
  &K_P_MNG,&K_A____,&K_A____,&K_A____,&K_P_EXP,
  &K_A____,&K_A____,&K_A____,&K_A____,&K_A____,  
  &K_A____,&K_P_UUM,&K_A____,&K_A____,&K_A____,

  &K_P_ALT,&K_A____,&K_A____,&K_A____,&K_A____,
  &K_A____,&K_O_HOM,&K_O_UP_,&K_O_PUP,&K_P_SUP,
  &K_P_LUM,&K_P_UM_,&K_P_RUM,&K_P_MCM,&K_M_INC,

  &K_O_ESC,&K_A____,&K_A____,&K_A____,&K_A____,
  &K_A____,&K_O_LFT,&K_O_DWN,&K_O_RGT,&K_P_LLM,  
  &K_P_LM_,&K_P_DM_,&K_P_RM_,&K_P_RRM,&K_M_MUT,

  &K_P_AGR,&K_A____,&K_A____,&K_A____,&K_A____,
  &K_A____,&K_O_END,&K_P_MOS,&K_O_PDN,&K_P_SDO,
  &K_P_LDM,&K_P_DDM,&K_P_RDM,&K_P_RCM,&K_M_DEC,

  &K_P_NUM,&K_A____,&K_P_GUI,&K_P_ATA,&K_O_BCK,
  &K_O_DEL,&K_P_MAJ,&K_P_CTR,&K_P_MIN,&K_P_LCM,
  &K_O_ENT,&K_P_KOS,&K_O_TAB,&K_P_DES,&K_P_SPE
};

//===================================================  
static const PROGMEM KeyWord* KBD_KOS_Keys[] = { 
  &K_P_MNG,&K_A____,&K_A____,&K_A____,&K_P_EXP,
  &K_A____,&K_A____,&K_A____,&K_A____,&K_A____,  
  &K_A____,&K_O_INS,&K_A____,&K_A____,&K_A____,

  &K_P_ALT,&K_O_F1_,&K_O_F2_,&K_O_F3_,&K_O_F4_,
  &K_M_NXT,&K_M_JCT,&K_P_UM_,&K_P_MCM,&K_P_SUP,
  &K_O_HOM,&K_O_PUP,&K_O_PDN,&K_O_END,&K_M_INC,

  &K_O_ESC,&K_O_F5_,&K_O_F6_,&K_O_F7_,&K_O_F8_,
  &K_M_PLA,&K_P_LM_,&K_P_DM_,&K_P_RM_,&K_P_LCM,  
  &K_O_LFT,&K_O_UP_,&K_O_DWN,&K_O_RGT,&K_M_MUT,

  &K_P_AGR,&K_O_F9_,&K_O_F10,&K_O_F11,&K_O_F12,
  &K_M_PRV,&K_P_DSK,&K_P_MOS,&K_P_RCM,&K_P_SDO,
  &K_P_C_C,&K_P_C_V,&K_P_C_A,&K_P_C_Z,&K_M_DEC,

  &K_P_NUM,&K_A____,&K_P_GUI,&K_P_ATA,&K_O_BCK,
  &K_O_DEL,&K_P_MAJ,&K_P_CTR,&K_P_MIN,&K_O_SPA,
  &K_O_ENT,&K_P_MIN,&K_O_TAB,&K_P_DES,&K_P_SPE
};


//static const PROGMEM KeyWord** KBD_chord_Keys[PAGE_KOS][NB_CHORD] = { };

const ChordWord C_4_001 = { 4043,&K_A__1D,"↔"};
const ChordWord C_4_002 = { 4142,&K_A__12,"↕"};
const ChordWord C_4_003 = { 4041,&K_A__17 ,"↨"};


const ChordWord C_1_001 = {  910,&K_S_011,"C_1_001"};
const ChordWord C_1_002 = {  911,&K_S_012,"C_1_002"};
const ChordWord C_1_003 = {  912,&K_S_013,"C_1_003"};
const ChordWord C_1_004 = {  913,&K_S_014,"C_1_004"};
const ChordWord C_1_005 = {  914,&K_S_015,"C_1_005"};
const ChordWord C_1_006 = { 4044,&K_S_016,"ment mt"};
const ChordWord C_1_007 = { 4043,&K_S_017,"tion tn"};
const ChordWord C_1_008 = { 3440,&K_S_018,"ement et"};
const ChordWord C_1_009 = { 3143,&K_S_019,"ation an"};
const ChordWord C_1_010 = { 2734,&K_S_020,"elle el"};
const ChordWord C_1_011 = { 3355,&K_S_021,"ique iq"};
const ChordWord C_1_012 = { 3342,&K_S_022,"aire ir"};
const ChordWord C_1_013 = { 1944,&K_S_023,"omme om"};
const ChordWord C_1_014 = { 1819,&K_S_024,"pour po"};
const ChordWord C_1_015 = { 3442,&K_S_025,"leur lr"};
const ChordWord C_1_016 = { 3241,&K_S_026,"euse us"};
const ChordWord C_1_017 = { 2733,&K_S_027,"ille il"};
const ChordWord C_1_018 = { 3134,&K_A__E6,"AE"};
const ChordWord C_1_019 = { 4042,&K_S_019,"OE"};
const ChordWord C_1_020 = { 4042,&K_S_020,"C_1_010"};
const ChordWord C_1_021 = { 4042,&K_S_021,"C_1_011"};
const ChordWord C_1_022 = { 4042,&K_S_022,"C_1_012"};
const ChordWord C_1_023 = { 4042,&K_S_023,"C_1_013"};

const ChordWord C_2_001 = { 3134,&K_A__E6,"AE"};
const ChordWord C_2_002 = { 4042,&K_S_019,"OE"};

#define NB_CHORD_KOS 0
#define NB_CHORD_MIN 24
#define NB_CHORD_MAJ 5
#define NB_CHORD_SPE 3
#define NB_CHORD_NUM 0
#define NB_CHORD_DES 0
#define NB_CHORD_MOS 0


static const int KBD_chord_nb[NB_PAGES] = { NB_CHORD_KOS, NB_CHORD_MIN, NB_CHORD_MAJ, NB_CHORD_NUM, NB_CHORD_SPE, NB_CHORD_DES, NB_CHORD_MOS};

static const ChordWord* KBD_chord_Keys_MIN[NB_CHORD_MIN] = { 
  &C_1_001, &C_1_002,&C_1_003,&C_1_004,&C_1_005,&C_1_006,&C_1_007,&C_1_008,&C_1_009,&C_1_010,
  &C_1_011,&C_1_012,&C_1_013,&C_1_014,&C_1_015,&C_1_016,&C_1_017,&C_1_018,&C_1_019,&C_1_020,
  &C_1_021,&C_1_022,&C_1_023
};


//  &K_S_011,&K_S_012,&K_S_013,&K_S_014,&K_S_015,
//  &K_S_016,&K_S_017,&K_S_018,&K_S_019,&K_S_020,
//  &K_S_021,&K_S_022,&K_S_023,&K_S_024,&K_S_025,
//  &K_S_026,&K_S_027
//};
static const ChordWord* KBD_chord_Keys_MAJ[NB_CHORD_MAJ] = {   &C_1_001, &C_1_002,&C_1_003,&C_1_004,&C_1_005 };
static const ChordWord* KBD_chord_Keys_MOS[NB_CHORD_MOS] = { };
static const ChordWord* KBD_chord_Keys_KOS[NB_CHORD_KOS] = { };
static const ChordWord* KBD_chord_Keys_DES[NB_CHORD_DES] = { };
static const ChordWord* KBD_chord_Keys_NUM[NB_CHORD_NUM] = { };
static const ChordWord* KBD_chord_Keys_SPE[NB_CHORD_SPE] = {&C_4_001, &C_4_002,&C_4_003 };

static const ChordWord** KBD_chord_Keys[NB_PAGES] = { 
  KBD_chord_Keys_KOS,KBD_chord_Keys_MIN,KBD_chord_Keys_MAJ,KBD_chord_Keys_NUM,KBD_chord_Keys_SPE,KBD_chord_Keys_DES,KBD_chord_Keys_MOS
};
//static const int KBD_chord_value[PAGE_KOS][NB_CHORD] = { } ;
//static const int KBD_chord_value[PAGE_MIN][NB_CHORD] = { 3738, 3637, 3954, 3940, 3942 } ;
//static const int KBD_chord_value[PAGE_MAJ][NB_CHORD] = { } ;
//static const int KBD_chord_value[PAGE_NUM][NB_CHORD] = { } ;
//static const int KBD_chord_value[PAGE_SPE][NB_CHORD] = { } ;
//static const int KBD_chord_value[PAGE_DES][NB_CHORD] = { } ;
//static const int KBD_chord_value[PAGE_MOS][NB_CHORD] = { } ;



static const KeyWord** KBD_Pages[NB_PAGES] = { KBD_KOS_Keys, KBD_MIN_Keys, KBD_MAJ_Keys, KBD_NUM_Keys, KBD_SPE_Keys, KBD_DES_Keys, KBD_MOS_Keys } ;

static const char pagesnames[][NB_PAGES] = { "KOS", "NOR" ,"MAJ", "NUM","SPE","DES","MOS"} ;

// void (Keyboard_emitter::*pointeurfct)(int) = &Keyboard_emitter::switchToPage ;

#endif
