#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16
#define _GAME 17

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  GAME_ON,
  GAME_OFF,
  DYNAMIC_MACRO_RANGE,
  };

#include "dynamic_macro.h"

#define KC_ KC_TRNS
#define ____ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST  RESET
#define KC_DBG  DEBUG
#define KC_BL_S BL_STEP
#define KC_GAME GAME_ON
#define KC_GOFF GAME_OFF

// mod tap
#define KC_RSTT MT(MOD_RSFT, KC_RGHT)
#define KC_LSTT MT(MOD_LSFT, KC_LEFT)
#define KC_ASCN MT(MOD_LALT, KC_SCLN)
#define KC_CSLS MT(MOD_LCTL, KC_SLSH)
#define KC_ENTS MT(MOD_LSFT, KC_ENT)
#define KC_MCTL MT(MOD_LCTL, KC_MINS)

// workspaces
#define KC_LWSP LALT(LCTL(KC_LEFT))
#define KC_RWSP LALT(LCTL(KC_RGHT))
#define KC_LMOV LSFT(LALT(LCTL(KC_LEFT)))
#define KC_RMOV LSFT(LALT(LCTL(KC_RGHT)))

// windows
#define KC_WLFT LGUI(KC_LEFT)
#define KC_WRGT LGUI(KC_RGHT)
#define KC_WMAX LGUI(KC_UP)

// enter mods
#define KC_CENT LCTL(KC_ENT)
#define KC_CSNT LCTL(LSFT(KC_ENT)) 

// zoom
#define KC_ZIN  LCTL(KC_PLUS)
#define KC_ZRST LCTL(KC_0)
#define KC_ZOUT LCTL(KC_MINS)

// vscode
#define KC_IDNT LCTL(KC_RBRC)
#define KC_ODNT LCTL(KC_LBRC)

// dynamic macros
#define KC_STOP DYN_REC_STOP
#define KC_PLY1 DYN_MACRO_PLAY1
#define KC_PLY2 DYN_MACRO_PLAY2
#define KC_REC1 DYN_REC_START1
#define KC_REC2 DYN_REC_START2


// tap dance
enum {
  TD_GRV_ESC = 0,
  TD_GUI_CAPS
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_GRV_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_ESC),
  [TD_GUI_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_CAPS)
};

#define KC_GRES TD(TD_GRV_ESC)
#define KC_GCAP TD(TD_GUI_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GESC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     GCAP, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,ASCN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,MCTL,     UNDS, N  , M  ,COMM,DOT ,CSLS,HYPR,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       PLY1,RASE,ENTS,         SPC,LOWR,PLY2
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,PGUP,HOME, UP ,END ,ZIN ,                   , 7  , 8  , 9  ,PLUS,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,PGDN,LEFT,DOWN,RGHT,ZRST,                0  , 4  , 5  , 6  ,EQL ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,IDNT,ODNT,ZOUT,CSNT,         ,    , 1  , 2  , 3  ,MINS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,CENT,           ,    , 
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,MPRV,MPLY,MNXT,VOLU,                   ,LCBR,PLUS,RCBR,PIPE,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,WLFT,WMAX,WRGT,VOLD,                   ,LPRN,EQL ,RPRN,COLN,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,LMOV,RMOV,LWSP,RWSP,MUTE,    ,         ,    ,LBRC,MINS,RBRC,BSLS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,    
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,GAME,    ,                   ,REC1,REC2,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,STOP,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,DBG ,RST ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,            ,    ,    
  //                  `----+----+----'        `----+----+----'
  ),

   [_GAME] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,GOFF,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     CAPS, Z  , X  , C  , V  , B  ,ENT ,     MINS, N  , M  ,COMM,DOT ,SLSH,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                         V ,LSFT, SPC,         ENT,RASE,LALT
  //                  `----+----+----'        `----+----+----'
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case GAME_ON:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_plover, false, 0);
            #endif        
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_ADJUST);
            layer_on(_GAME);
        }
        return false;
        break;
    case GAME_OFF:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
            #endif
            layer_off(_GAME);
        }
        return false;
        break;
  }
  return true;
}
