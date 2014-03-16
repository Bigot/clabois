#ifndef KEY_EMIT_H
#define KEY_EMIT_H

#include <WProgram.h>
#include "config.h"
#include "key_codes.h"

//
//page numbers
//

#define NULL_KEY 999

/* key event */
typedef struct {
    int key ;
    int type ;
    unsigned long first_time;
    unsigned long last_time;
    unsigned long send_time;    
} keylist;

typedef struct KeyWord KeyWord;
class Keyboard_emitter ;

//
// pointer to Keyboard_emitter member function used in keywords
//

typedef void (Keyboard_emitter::*MPV_V)() ;

//
//
//
class Keyboard_emitter {
  public:
    Keyboard_emitter() ; 
    // init
    void init();
    // low level words
    void reset_key_state();
    void remove_released_keys(const unsigned long datetime);
    void update_new_keys_pressed(const int raw_keys_pressed[KEY_NB], 
        const int nb_raw_keys, const unsigned long datetime);
    void update_last_keys_pressed() ;
    void update_key_state(const int raw_keys_pressed[KEY_NB], 
        const int nb_raw_keys, const unsigned long datetime);
    // high level emit keys
    void key_to_index_emit(int key, bool progonly);
    bool bigram_to_index_emit(int j, int k) ;
    void emit();
 //   void serial_single_emit(int c);
    void serial_emit_macro(int c); // TMP
    // low level emit keys
    void apply_accent() ;
    void send_rawkey( int keyval);
    void send_composkey(int modif,int key); 
    void send_string(const char* c);
    void write_key(int keyval, int kbd_modif);
    void send_alphakey( int keyval, int kbd_modif);
    void send_altkey(const char* c);
    void send_seq(const struct KeyWord* key, int kbd_modif);
    void send_keyword(const struct KeyWord* key, int kbd_modif);
  //  void RTP_handle(int c);
  //  void LTP_handle(int c);
  //  void IR_handle(int c);
    
    // function called by keywords


    void switchToPage(int page);
    void switchModifier(int modif);
    void switchBackPage();
    void resetModifier();
    
    int get_led();
    
    void nullaction();
    void send_copy();
    void send_paste();
    void send_undo();
    void send_cut();
    void select_all();
    void send_ctrlaltdel();
    void send_alttab();  
    void Supp_1_car();
    void send_numlock(); 
    void testkeys(); 
    void switchToPageMaj();  
    void switchToPageNum();        
    void switchToPageSpe() ;             
    void switchToPageNorm();         
    void switchToPageKos() ;             
    void switchToPageDes() ;             
    void switchToPageMod() ;
    void switchToPageMos();    
    void switchModCtrl() ;     
    void switchModAlt()  ;      
    void switchModSht()  ; 
    void switchModGui()  ;      
    void switchModRalt() ;
    void switchModifierLock();
 //   char* statusLine1();
 //   char* statusLine2();    
// mouse
    void mouseMove(int x, int y);
    void mousescroll(int x);
    void lmouse()  ; 
    void rmouse()  ;
    void umouse()  ;
    void dmouse()  ; 
    void llmouse() ;
    void rrmouse() ;
    void uumouse() ;
    void ddmouse() ;
    void lumouse() ;
    void rumouse() ;
    void ldmouse() ;
    void rdmouse() ;
    
    void uscrollmouse() ;
    void dscrollmouse()  ;

    void reset_mouse();
    void emit_mouse();
    
    void leftmousebutton() ;
    void middlemousebutton() ;
    void rightmousebutton() ;
    void minimize_all();

 
  private:
  bool key_emit_slot(int index,int debouncedelay, int repeatdelay) ;
    //int active_layout ;
    //int active_modifier ;
    int nb_new_keys_pressed ;
    int nb_last_keys_pressed ;
    int new_keys_pressed[KEY_NB] ; 
    int last_keys_pressed[KEY_NB] ; 
    keylist keys_state[KEY_NB] ;


    int  modselected          ;    
    // numéro de la page sélextionnée
    int  PageSelected         ;
    // numéro de la page précédente
    int  PreviousPageSelected ;
    // est-ce que la page est vérouillée
    int  PageLock             ;
    int  keyboard_modifier    ;
    int  modifierLock         ;
    int  lastkey              ;
    int  accentiterator       ;
    bool mouse_left ;
    bool mouse_middle ;
    bool mouse_right ;
    bool mouse_new_left ;
    bool mouse_new_middle ;
    bool mouse_new_right ;
    int  mouse_X ;
    int  mouse_Y ;
    int  mouse_S ;
    int  mouse_change ;


} ;

//
// tableau des fonction
//

static MPV_V cladeonFunctions[43] = { 
    &Keyboard_emitter::nullaction,          // 00
    &Keyboard_emitter::switchToPageMaj,     // 01
    &Keyboard_emitter::switchToPageNum,     // 02   
    &Keyboard_emitter::switchToPageSpe,     // 03   
    &Keyboard_emitter::switchToPageNorm,    // 04        
    &Keyboard_emitter::switchToPageKos,     // 05          
    &Keyboard_emitter::switchToPageMos,     // 06          
    &Keyboard_emitter::switchModCtrl,       // 07 
    &Keyboard_emitter::switchModAlt,        // 08 
    &Keyboard_emitter::switchModSht,        // 09
    &Keyboard_emitter::switchModGui,        // 10
    &Keyboard_emitter::switchModRalt,       // 11
    &Keyboard_emitter::apply_accent,        // 12
    &Keyboard_emitter::send_alttab,         // 13
    &Keyboard_emitter::send_numlock,        // 14
    &Keyboard_emitter::Supp_1_car,          // 15
    &Keyboard_emitter::send_copy,           // 16
    &Keyboard_emitter::send_paste,          // 17
    &Keyboard_emitter::send_undo,           // 18
    &Keyboard_emitter::send_cut,            // 19
    &Keyboard_emitter::send_ctrlaltdel,     // 20
    &Keyboard_emitter::switchModifierLock,  // 21
    &Keyboard_emitter::testkeys,            // 22
    &Keyboard_emitter::lmouse ,             // 23              
    &Keyboard_emitter::rmouse ,             // 24
    &Keyboard_emitter::umouse ,             // 25
    &Keyboard_emitter::dmouse ,             // 26
    &Keyboard_emitter::llmouse,             // 27
    &Keyboard_emitter::rrmouse,             // 28
    &Keyboard_emitter::uumouse,             // 29
    &Keyboard_emitter::ddmouse,             // 30
    &Keyboard_emitter::lumouse,             // 31
    &Keyboard_emitter::rumouse,             // 32
    &Keyboard_emitter::ldmouse,             // 33
    &Keyboard_emitter::rdmouse,             // 34
    &Keyboard_emitter::uscrollmouse,        // 35
    &Keyboard_emitter::dscrollmouse,        // 36
    &Keyboard_emitter::leftmousebutton,     // 37
    &Keyboard_emitter::middlemousebutton,   // 38
    &Keyboard_emitter::rightmousebutton,    // 39
    &Keyboard_emitter::switchToPageDes,     // 40         
    &Keyboard_emitter::select_all,          // 41       
    &Keyboard_emitter::minimize_all         // 42      
  } ;

#endif
