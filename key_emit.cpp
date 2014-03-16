#include "key_emit.h"
#include <WProgram.h>
#include "key_codes.h"
#include "debug.h"
#include "config.h"
#include "kbd_keys.h"

// page startup variables

typedef struct KeyWord KeyWord;

Keyboard_emitter::Keyboard_emitter() { } 

// =============================================================================
// INI WORDS
// =============================================================================
void Keyboard_emitter::reset_mouse(){
  mouse_left           = false ;
  mouse_middle         = false ;
  mouse_right          = false ;
  mouse_new_left       = false ;
  mouse_new_middle     = false ;
  mouse_new_right      = false ;
  mouse_X              = 0 ;
  mouse_Y              = 0 ;
  mouse_S              = 0 ;
//  mouse_change         = 0 ;
}

void Keyboard_emitter::init(){
//  cdnscreen = & scr ; 
//  cdnsound  = & snd ; 
//  active_layout = 0;
//  active_modifier = 0;
  modselected          = 0 ;
  PageSelected         = PAGE_KOS ;
  PreviousPageSelected = PAGE_KOS ;
  PageLock             = 1 ;
  keyboard_modifier    = 0 ;
  modifierLock         = 0 ;
  lastkey              = 0 ;
  accentiterator       = 0 ;
  reset_mouse();

  
  for (int k = 0;k<KEY_NB; k++) { 
    last_keys_pressed[k]= NULL_KEY;
    new_keys_pressed[k]= NULL_KEY;
    keys_state[k].key = 0 ;
    keys_state[k].type = 0 ;
    keys_state[k].last_time = 0 ;
    keys_state[k].first_time = 0 ;
    keys_state[k].send_time = 0 ;
  }
  nb_new_keys_pressed = 0;
  nb_last_keys_pressed = 0;

  debugln("init kbd USB serial",DEBUG_STD);
  #ifdef USB_EMIT
  debugln(" and USB too",DEBUG_STD);

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.set_key2(0);
  Keyboard.set_key3(0);
  Keyboard.set_key4(0);
  Keyboard.set_key5(0);
  Keyboard.set_key6(0);
  Keyboard.send_now();
  #endif
  //  cdnscreen->refresh(pagesnames[PageSelected],pagesnames[PreviousPageSelected],1,0);
  //  cdnscreen->refresh(pagesnames[PageSelected],pagesnames[PreviousPageSelected],PageLock,keyboard_modifier,modifierLock);
}


// =============================================================================
// LOW LEVEL WORDS
// =============================================================================

// réinitialise l'état des touches enfoncées
// utilisé pour mettre à jour l'état interne quand toutes les touches sont relachées
void Keyboard_emitter::reset_key_state() {
  nb_last_keys_pressed = 0;   
  int iterator = 0;  
  int index = 0 ;
  while (last_keys_pressed[iterator] != NULL_KEY) { 
    index = last_keys_pressed[iterator] ;    
    keys_state[index].first_time = 0  ;
    keys_state[index].last_time = 0 ;  
    keys_state[index].send_time = 0 ;
    last_keys_pressed[iterator] = NULL_KEY ;
    iterator++ ; 
  }
  reset_mouse();
}

//  
// balayage de raw_keys_pressed pour rechercher si la touche est déjà utilisée dans le tableau keys_state
// et mise à jour de new_keys_pressed
//

void Keyboard_emitter::update_new_keys_pressed(const int raw_keys_pressed[KEY_NB], const int nb_raw_keys, const unsigned long datetime){
  nb_new_keys_pressed  = nb_raw_keys   ;
  int index = 0 ;
  for ( int i = 0; i<nb_raw_keys;i++){
    index = raw_keys_pressed[i] ;
    if (keys_state[index].first_time != 0 ) { 
      keys_state[index].last_time = datetime ;     // si déjà utilisé, met à jour les indicateurs
    } else {
      keys_state[index].first_time = datetime ;    // sinon ajoute la touche dans keys_state 
      keys_state[index].last_time = datetime ;      
      keys_state[index].send_time = 0 ;      // mise à 0 car la touche n'est pas transmise tout de suite
    }
    new_keys_pressed[i] = index ; // et met à jour  le tableau new_keys_pressed
//    nb_new_keys_pressed++; 
  }
  debug(" new key pressed # ", nb_new_keys_pressed, DEBUG_LOW); 
}

//
// balaye le tableau last_keys_pressed pour effacer dans keys_state les touches relachées
// on sait qu'une touche a été relachée parce que last_time n'est pas égal à la date du scannage
//
void Keyboard_emitter::remove_released_keys(const unsigned long datetime) {
  int iterator = 0 ;    
  while (last_keys_pressed[iterator] != NULL_KEY && iterator <= KEY_NB ) {     
    int index = last_keys_pressed[iterator] ;    
    // si lasttime n'est pas à jour c'est que cette touche n'appartient pas à new_keys_pressed     
    if (keys_state[index].last_time != datetime ) { 
      // lance les actions de relachement de touche
      keys_state[index].first_time = 0  ;
      keys_state[index].last_time = 0 ;
      keys_state[index].send_time = 0 ;      
    } else {
      // rien a faire
    }  
    last_keys_pressed[iterator] = NULL_KEY ; 
    iterator++;
    debug(" inspection # ", iterator, DEBUG_LOW); 
  }
}

//  
// recopie de new_keys vers last_keys et réinitialisation de new_keys_pressed
//
void Keyboard_emitter::update_last_keys_pressed(){
  int iterator = 0 ;    
  while (new_keys_pressed[iterator] != NULL_KEY && iterator < KEY_NB) {     // balaye le tableau last_keys_pressed pour effacer les touches relachées
    last_keys_pressed[iterator] = new_keys_pressed[iterator] ;  
    new_keys_pressed[iterator] = NULL_KEY ; 
    iterator++;
  }
  last_keys_pressed[iterator] = NULL_KEY ;
  nb_last_keys_pressed  = iterator ; 
  debugln("  recopie de n valeurs : ", iterator, DEBUG_LOW) ;
}

void Keyboard_emitter::update_key_state(const int raw_keys_pressed[KEY_NB], const int nb_raw_keys, const unsigned long datetime){
  //reset_mouse_buttons();
  // si pas de touche pressée, on attend un peu et on reinittialise tout
  if (nb_raw_keys == 0 ) { 
    delay( 50); 
    reset_key_state();
    // la mise à jour des modifiers est faite avec emit pour ne pas mélanger bas et haut niveau
  } else { 
    update_new_keys_pressed(raw_keys_pressed, nb_raw_keys, datetime) ;
    remove_released_keys(datetime);
    update_last_keys_pressed();
  }
}

// =============================================================================
// HIGH LEVEL EMIT WORDS
// =============================================================================


void Keyboard_emitter::key_to_index_emit(int key, bool progonly = false){ 
  // si progonly est à oui, seuls les type 6 et 7 et 8 seront transmis
    int repeat_delay = DELAYREPEAT ;
    int index = last_keys_pressed[key] ;
    KeyWord * tmpkey = (KeyWord *)pgm_read_word(&KBD_Pages[PageSelected][index]);    
    
    int type = (int)pgm_read_word(&tmpkey->type) ; 
    if ( progonly && !(type == 8 || type == 7 || type == 6 )) { return; }      
    if ( type == 7 ) { repeat_delay = DELAYREPEATPROG ; }   
    if ( type == 8 ) { repeat_delay = DELAYREPEATMOUSE ; }       
    if ( key_emit_slot(index,DELAYCHORD,repeat_delay) )  {
      debug("first time : ", keys_state[index].first_time, DEBUG_MED);
      debug("last  time : ", keys_state[index].last_time, DEBUG_MED);
      debug("Diff chord = ", keys_state[index].last_time - keys_state[index].first_time, DEBUG_MED);        
      debug("send time : ", keys_state[index].send_time, DEBUG_MED);        
      debugln("Diff repeat = ", keys_state[index].last_time - keys_state[index].send_time, DEBUG_MED);                
      debug(" key : ", index, DEBUG_STD);    
      debug(" : ", DEBUG_STD);
      debug((char *)pgm_read_word(&tmpkey->string), DEBUG_STD);
      debugln (" / ", DEBUG_STD);

      if ( type == 1 ) { 
        lastkey = (int)pgm_read_word(&tmpkey->key) ;
        debugln("lastkey ", lastkey,DEBUG_MED);
        accentiterator = 0 ;
      }
      send_keyword(tmpkey,keyboard_modifier); 
      keys_state[index].send_time = keys_state[index].last_time ;              
    }
}

bool Keyboard_emitter::key_emit_slot(int index,int debouncedelay, int repeatdelay) {
  bool val = (keys_state[index].last_time - keys_state[index].first_time) > debouncedelay && 
    ( keys_state[index].send_time == 0 || (keys_state[index].last_time - keys_state[index].send_time) > repeatdelay )    ;
  debugln(" time slot ? : ", val ,DEBUG_LOW);
  return val ;  
}


bool Keyboard_emitter::bigram_to_index_emit(int j, int k){ 
  // pour l'instant les bigrammes ne tiennent pas compte de la page active.
  bool result = false ;
  int val = 0 ;
  
  int index_j = last_keys_pressed[j] ;
  int index_k = last_keys_pressed[k] ;

  if ((key_emit_slot(index_j,DELAYCHORD,DELAYREPEAT) && key_emit_slot(index_k,DELAYCHORD,DELAYREPEAT))) {
  if ( index_j < index_k ) {
    val = index_j*100+index_k ; 
  } else {
    val =  index_k*100+index_j ; 
  }
  debugln("test bigramme : ", val , DEBUG_RAW); 
  for ( int l = 0 ; l < KBD_chord_nb[PageSelected]; l++){ 
//    ChordWord *
    debugln("test bigramme : ", ((ChordWord *)(KBD_chord_Keys[PageSelected][l]))->value , DEBUG_STD); 
    if ( ((ChordWord *)(KBD_chord_Keys_MIN[l]))->value == val ) { 
      debugln("bingo bigramme : ", l , DEBUG_MED); 
      const KeyWord * tmpkey = ((ChordWord *)(KBD_chord_Keys[PageSelected][l]))->key;
      debug(" chord key : ", l , DEBUG_STD);    
      debug(" : ", DEBUG_STD);
      debug((char *)pgm_read_word(&tmpkey->string), DEBUG_STD);
      debugln (" / ", DEBUG_STD);

      send_keyword(tmpkey,keyboard_modifier); 
   
      keys_state[index_k].send_time = keys_state[index_k].last_time ;
      keys_state[index_j].send_time = keys_state[index_j].last_time ;
      result = true ;
      break ;
    }          
  }
  }
  return result ;
}


void Keyboard_emitter::emit_mouse(){
  Mouse.set_buttons(mouse_new_left, mouse_new_middle, mouse_new_right);
  //mouse_left = mouse_new_left;
  //mouse_middle = mouse_new_middle;
  //mouse_right = mouse_new_right;
  mouse_new_left       = false ;
  mouse_new_middle     = false ;
  mouse_new_right      = false ;

  Mouse.move(mouse_X,mouse_Y,mouse_S);  
//  Mouse.scroll(); 
  mouse_X              = 0 ;
  mouse_Y              = 0 ;
  mouse_S              = 0 ;
}

void Keyboard_emitter::emit(){ 
  if(nb_last_keys_pressed <= 0) {
    // ???   si pas de touche active et que avant il y avait une touche active non envoyée, 
    // ???   envoi de la touche
   debugln("No key pressed : ", 0 , DEBUG_LOW); 
   // suppression des modifiers et retours aux pages standard selon les règles 
   resetModifier();

  } else if(nb_last_keys_pressed == 1) {
    // ??  si une seule touche active et que délai de répétition atteint
    // ??   envoi de la touche
    // ??  si une seule touche active et que délai de tempochord atteint, 
    // ??  envoi de la touche

    // int datetime = millis() ;
    debugln("Only one key pressed : ", 1 , DEBUG_LOW); 
    key_to_index_emit(0);
  } else if(nb_last_keys_pressed >= 2) {
    
    // balayage des touches pour lancer d'abord les modificatrices
    for (int j=0; j < nb_last_keys_pressed; j++ ){
      key_to_index_emit(j,true);         
    }
    //  si deux touches actives, envoi de la combinaison

    // int datetime = millis() ;
    debugln("nb of key pressed : ", nb_last_keys_pressed , DEBUG_RAW); 
    // recherche des bigrammes
    bool test_bigram = false ;
    for (int j=0; j < nb_last_keys_pressed; j++ ){
      for (int k=j+1; k < nb_last_keys_pressed; k++ ){
        test_bigram = bigram_to_index_emit(j,k);
        // !!!! ajouter un break en fonction du résultat de la fonction
      }
    }
    // traitement des touches non chordées
    // rebalyage de last_keys_pressed sachant que les informations send_time ont été mises à jour et sont  donc filtrées
    for (int j=0; j < nb_last_keys_pressed; j++ ){
      key_to_index_emit(j);         
    }

  }
  emit_mouse();  
  
  //  switchBackPage();
  //resetModifier();
} 


// =============================================================================
// LOW LEVEL EMIT WORDS
// =============================================================================



void Keyboard_emitter::send_rawkey( int keyval){ 
#ifdef USB_EMIT
  Keyboard.set_key1(keyval);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
#endif
}

void Keyboard_emitter::send_composkey(int modif,int key) {
#ifdef USB_EMIT
  Keyboard.set_modifier(modif);
  Keyboard.set_key1(key);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
#endif
}


void Keyboard_emitter::send_string(const char* c){ 
#ifdef USB_EMIT
  Keyboard.print(c);
#endif 
}

void Keyboard_emitter::write_key(int keyval, int kbd_modif){
  int modifier=kbd_modif;
  if (keyval & SHIFT_MASK) modifier |= MODIFIERKEY_SHIFT;
  if (keyval & ALTGR_MASK) modifier |= MODIFIERKEY_RIGHT_ALT;
  keyval &= 0x3F;
  if (keyval == KEY_NON_US_100) keyval = 100;
  send_composkey(modifier,keyval);
}

void Keyboard_emitter::send_alphakey( int keyval, int kbd_modif){ 
  int deadkey = keyval & DEADKEYS_MASK;
  if (deadkey == CIRCUMFLEX_BITS) write_key(DEADKEY_CIRCUMFLEX,0);	
  if (deadkey == DIAERESIS_BITS) write_key(DEADKEY_DIAERESIS,0);
  if (deadkey == GRAVE_ACCENT_BITS) write_key(DEADKEY_GRAVE_ACCENT,0);
  if (deadkey == TILDE_BITS) write_key(DEADKEY_TILDE,0);
  write_key(keyval,kbd_modif);
}

// compose a key with an alt code. not portable though
void Keyboard_emitter::send_altkey(const char* c){
#ifdef USB_EMIT
  // press ALT
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.send_now();
  for (int i=0; i < 4; i++) {
    char code = int(c[i]+40);
    if (code > 87 && code < 98 ) {
      if (code == 88) code = 98;// for 0
      send_rawkey(code);
    }
  }
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
#endif
}


//when key is a composition of keys
void Keyboard_emitter::send_seq(const struct KeyWord* key, int kbd_modif){ 
  for(int i=0;i<KEY_SEQ_LENGTH;i++){ 
    KeyWord * tmpkey = (KeyWord *) pgm_read_word(&key->seq[i] ); 
    send_keyword(tmpkey, kbd_modif );
  }   
}

void Keyboard_emitter::send_keyword(const struct KeyWord* key, int kbd_modif){ 
 debugln("key ",pgm_read_word(&key->type ),DEBUG_MED);
  if (key ==NULL) return; 
  switch (pgm_read_word(&key->type )) {
  case 1: // send a caracter
    send_alphakey(pgm_read_word(&key->key),kbd_modif);    
    break;
  case 2: // send a string
    send_string((char *)pgm_read_word(&key->string));
    break;
  case 3: // send an alt key
    send_altkey((char *)pgm_read_word(&key->altval));
    break;
  case 4: // send a sequence
    send_seq(key,kbd_modif);
    break;
  case 5: // send a raw key
    send_rawkey(pgm_read_word(&key->key));
    break;    
  case 6: // call function
    {
      Keyboard_emitter instance ;
      int prog = pgm_read_word(&key->fctptr) ;
      debugln("prg ",prog,DEBUG_MED);
      (this->*cladeonFunctions[prog])();
      break;
    }
  case 7: // quick function
    {
      Keyboard_emitter instance ;
      int prog = pgm_read_word(&key->fctptr) ;
      debugln("quick prg ",prog,DEBUG_MED);
      (this->*cladeonFunctions[prog])();
      break;
    } 
  case 8: // quick function
    {
      Keyboard_emitter instance ;
      int prog = pgm_read_word(&key->fctptr) ;
      debugln("mouse fct ",prog,DEBUG_MED);
      (this->*cladeonFunctions[prog])();
      break;
    }   
  default: 
    ;
  } 
}  

// =============================================================================
// MOUSE WORDS
// =============================================================================

void Keyboard_emitter::mouseMove(int x, int y) {
  Mouse.move(x,y);  
}

void  Keyboard_emitter::mousescroll(int x){
  Mouse.scroll(x); 
}

  // ici on met juste à jour les valeur left middle et right
  // la mise à jour de l'état de la souris se fait à l'extérieur
  //    Mouse.set_buttons(left, middle, right);

void Keyboard_emitter::leftmousebutton() {
  mouse_new_left = true ; }

void Keyboard_emitter::middlemousebutton() {
  mouse_new_middle = true; }

void Keyboard_emitter::rightmousebutton() {
  mouse_new_right = true; }



// =============================================================================
// KEY ACTION WORDS
// =============================================================================

void Keyboard_emitter::nullaction() {} ;

// maj, num, ctrl,ctrlaltsuppr
//spe, norm, alt,lock,
//fn, mode,win,altgr

void Keyboard_emitter::switchToPageMaj()  {  
  Keyboard_emitter::switchToPage(PAGE_MAJ) ;  
}
void Keyboard_emitter::switchToPageNum()  {  
  Keyboard_emitter::switchToPage(PAGE_NUM) ;  
}       
void Keyboard_emitter::switchToPageSpe()  {  
  Keyboard_emitter::switchToPage(PAGE_SPE) ;   
}          
void Keyboard_emitter::switchToPageNorm() {  
  Keyboard_emitter::switchToPage(PAGE_MIN) ;   
}      
void Keyboard_emitter::switchToPageDes() {  
  Keyboard_emitter::switchToPage(PAGE_DES) ;   
}      
void Keyboard_emitter::switchToPageKos()   {  
  Keyboard_emitter::switchToPage(PAGE_KOS) ;      
}       

void Keyboard_emitter::switchToPageMos()  {  
  Keyboard_emitter::switchToPage(PAGE_MOS) ;      
}        

void Keyboard_emitter::switchToPageMod()  {  
//  Keyboard_emitter::switchToPage(PAGE_MOD0) ;     
}        

void Keyboard_emitter::switchModCtrl()    {  
  Keyboard_emitter::switchModifier(MODIFIERKEY_CTRL ); 
}     
void Keyboard_emitter::switchModAlt()     {  
  Keyboard_emitter::switchModifier(MODIFIERKEY_ALT);    
}  
void Keyboard_emitter::switchModSht()     {  
  Keyboard_emitter::switchModifier(MODIFIERKEY_SHIFT); 
}
void Keyboard_emitter::switchModGui()     {  
  Keyboard_emitter::switchModifier(MODIFIERKEY_GUI);    
}  
void Keyboard_emitter::switchModRalt()    {  
  Keyboard_emitter::switchModifier(MODIFIERKEY_RIGHT_ALT); 
}

void Keyboard_emitter::lmouse()    {  
  mouse_X += -XMOUSE ;
}
void Keyboard_emitter::rmouse()    { 
  mouse_X += XMOUSE ; 
}
void Keyboard_emitter::umouse()    {  
  mouse_Y += -YMOUSE ;
}
void Keyboard_emitter::dmouse()    {  
  mouse_Y += YMOUSE ;
}

void Keyboard_emitter::llmouse()    {  
  mouse_X += -XXMOUSE ;
}
void Keyboard_emitter::rrmouse()    {
  mouse_X += XXMOUSE ;  
}
void Keyboard_emitter::uumouse()    {  
  mouse_Y += -YYMOUSE ;
}
void Keyboard_emitter::ddmouse()    {  
  mouse_Y += YYMOUSE ;
}
void Keyboard_emitter::lumouse()    {  
  mouse_X += -XMOUSE ;
  mouse_Y += -YMOUSE ;
}
void Keyboard_emitter::rumouse()    { 
  mouse_X += XMOUSE ;
  mouse_Y += -YMOUSE ; 
}
void Keyboard_emitter::ldmouse()    {  
  mouse_X += -XMOUSE ;
  mouse_Y += YMOUSE ;
}
void Keyboard_emitter::rdmouse()    {
  mouse_X += XMOUSE ;
  mouse_Y += YMOUSE ;  
}

void Keyboard_emitter::uscrollmouse()    {  
  mouse_S += MOUSESCROLL ;
}
void Keyboard_emitter::dscrollmouse()    {
  mouse_S += -MOUSESCROLL ;  
}

void Keyboard_emitter::switchToPage(int page){

  debugln("previous : ", PreviousPageSelected,DEBUG_MED); 
  debugln("present  : ", PageSelected,DEBUG_MED); 
  debugln("new      : ", page,DEBUG_MED); 
  PreviousPageSelected = PageSelected ;
  debugln("apres affectation  : ", PageSelected,DEBUG_MED); 
  debugln("previous : ", PreviousPageSelected,DEBUG_MED); 
  debugln("present  : ", PageSelected,DEBUG_MED); 
  debugln("new      : ", page,DEBUG_MED); 
  
  
//  if (PageSelected == page ) { 
//    PageLock = 1; 
//    debugln("Page locked : ", page,DEBUG_MED);     
//  } else { 
//    PageLock = 0;
    PageSelected = page ;
    
//    debugln("Page selected : ", page,DEBUG_MED);      
//  } 
}

int Keyboard_emitter::get_led(){
  return PageSelected ;
}

void Keyboard_emitter::testkeys(){
  #ifdef USB_EMIT
  for (int i = 1; i < 318; i++) {
    Keyboard.print("Key ");
    Keyboard.print(i);
    Keyboard.print(" : ");
    //  send_string((char *)pgm_read_word(&key->string));
    send_string((char *)pgm_read_word(&ALL_keys[i]->string));   
    Keyboard.print(" : ");

    send_keyword( ALL_keys[i],0);
    Keyboard.println(";");
  }
  #endif
}

void Keyboard_emitter::switchModifierLock(){
  // faire un xor ?  
  if (modifierLock == 0) modifierLock = 1 ;
  else modifierLock = 0 ;
}

void Keyboard_emitter::switchModifier(int modif){
  keyboard_modifier = keyboard_modifier ^ modif ;
  debugln("modifier : ",  keyboard_modifier,DEBUG_MED);

  //    cdnscreen->welcome("modifier :", itoa(modif,tmpchar,10) );
 // cdnsound->switchmodifier();
#ifdef USB_EMIT
  Keyboard.set_modifier(keyboard_modifier);
  //  Keyboard.set_key1(keyboard_modifier);
  Keyboard.send_now();
#endif

}

void Keyboard_emitter::switchBackPage(){
  if (PageLock == 0) { 
    PageSelected =  PreviousPageSelected  ;
    PageLock = 1;
  }
}

void Keyboard_emitter::resetModifier(){
  
    Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.set_key2(0);
  Keyboard.set_key3(0);
  Keyboard.set_key4(0);
  Keyboard.set_key5(0);
  Keyboard.set_key6(0);
  Keyboard.send_now();

  
//  if (modifierLock == 0 && keyboard_modifier !=0) { 
//    keyboard_modifier = 0 ;
//    #ifdef USB_EMIT
//    Keyboard.set_modifier(keyboard_modifier);
//    Keyboard.send_now();
//    #endif
//  }
//  debugln("reset modifier : ",  keyboard_modifier,DEBUG_MED);

}


void Keyboard_emitter::apply_accent(){ 
  debugln("Accent : ",  lastkey,DEBUG_MED);
  switch ( lastkey ) {
  case 0:  
    break; 
  case KEY_Q:
    Supp_1_car();
    send_keyword((KeyWord *)pgm_read_word(&Keys_a[accentiterator%nb_accent_a]),keyboard_modifier);
    break;
  case KEY_QS : 
    Supp_1_car();
    send_keyword((KeyWord *)pgm_read_word(&Keys_A[accentiterator%nb_accent_a]),keyboard_modifier);
    break; 
  case KEY_E:
    Supp_1_car();
    send_keyword((KeyWord *)pgm_read_word(&Keys_e[accentiterator%nb_accent_e]),keyboard_modifier);
    break;    
  case KEY_ES  :
    Supp_1_car();
    send_keyword((KeyWord *)pgm_read_word(&Keys_E[accentiterator%nb_accent_e]),keyboard_modifier);
    break;
  case KEY_I:
    Supp_1_car();
    send_keyword((KeyWord *)pgm_read_word(&Keys_i[accentiterator%nb_accent_i]),keyboard_modifier);
    break;    
  case KEY_IS:
    Supp_1_car();
    send_keyword((KeyWord *)pgm_read_word(&Keys_I[accentiterator%nb_accent_i]),keyboard_modifier);
    break;
  case KEY_O:
    Supp_1_car();
    send_keyword((KeyWord *)pgm_read_word(&Keys_o[accentiterator%nb_accent_o]),keyboard_modifier);
    break;   
  case KEY_OS:
    Supp_1_car();
    send_keyword((KeyWord *)pgm_read_word(&Keys_O[accentiterator%nb_accent_o]),keyboard_modifier);
    break; 
  case KEY_U:
    Supp_1_car();
    send_keyword((KeyWord *)pgm_read_word(&Keys_u[accentiterator%nb_accent_u]),keyboard_modifier);
    break;
  case KEY_US:
    Supp_1_car();
    send_keyword((KeyWord *)pgm_read_word(&Keys_U[accentiterator%nb_accent_u]),keyboard_modifier);
    break;
  case KEY_C:
    Supp_1_car();
    send_keyword((KeyWord *)pgm_read_word(&Keys_c[accentiterator%nb_accent_c]),keyboard_modifier);
    break;
  case KEY_CS:
    Supp_1_car();
    send_keyword((KeyWord *)pgm_read_word(&Keys_C[accentiterator%nb_accent_c]),keyboard_modifier);
    break;
  } 
  accentiterator += 1 ;
}

void Keyboard_emitter::send_copy() { 
  send_composkey(MODIFIERKEY_CTRL,KEY_C) ; 
}

void Keyboard_emitter::send_paste() { 
  send_composkey(MODIFIERKEY_CTRL,KEY_V) ; 
}

void Keyboard_emitter::send_undo() { 
  send_composkey(MODIFIERKEY_CTRL,KEY_Z) ; 
}

void Keyboard_emitter::send_cut() { 
  send_composkey(MODIFIERKEY_CTRL,KEY_X) ; 
}

void Keyboard_emitter::select_all() { 
  send_composkey(MODIFIERKEY_CTRL,KEY_Q) ; 
}

void Keyboard_emitter::minimize_all() {
  send_composkey(MODIFIERKEY_GUI,KEY_D) ; 
}

void Keyboard_emitter::send_ctrlaltdel() { 
  send_composkey(MODIFIERKEY_CTRL| MODIFIERKEY_ALT,KEY_DELETE) ; 
}

void  Keyboard_emitter::Supp_1_car(){ 
  send_rawkey(KEY_BACKSPACE); 
}

void Keyboard_emitter::send_numlock() { 
  send_keyword(&K_O_NLC,0); 
}

void Keyboard_emitter::send_alttab() { 
  send_composkey(MODIFIERKEY_ALT,KEY_TAB) ; 
}


