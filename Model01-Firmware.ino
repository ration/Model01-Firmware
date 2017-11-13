// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

// GOAL - make a great layout for windows - since that is what I have to use a work ..
//
// DONE
// remap arrows to inverted T
// remap mouse to inverted T
// enable one shot modifiers
// map dedicated brackets key
// Get danish characters to work in the fn layer
// Turn off stick one shots
// 
// TODO
// Map fn + ZXCV to consumer undo, cut, copy, paste
// Find somewhere else to warp keys .. dump middle mouse
// Map mousekey to some of the thumb keys to enable drag and drop, which sucks with the T binding
// Map keys to dead keys to enter é and a few other accented characters (no wincompose)
// put <> on the brackets key
// maybe map esc to prog (if it doesn't brick the keyboard)
// find some cool light effect when keyboard is turned on
// find some subtle light effect for dayly use -- heatmap?

//#define KALEIDOSCOPE_HOSTOS_GUESSER 1
/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for "Numlock" mode, which is mostly just the Numlock specific LED mode
#include "Kaleidoscope-Numlock.h"

// Support for an "LED off mode"
#include "LED-Off.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for an LED mode that makes all the LEDs 'breathe'
#include "Kaleidoscope-LEDEffect-Breathe.h"

// Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
#include "Kaleidoscope-LEDEffect-Chase.h"

// Support for LED modes that pulse the keyboard's LED in a rainbow pattern
#include "Kaleidoscope-LEDEffect-Rainbow.h"

// Support for an LED mode that lights up the keys as you press them
#include "Kaleidoscope-LED-Stalker.h"

// Support for an LED mode that prints the keys you press in letters 4px high
#include "Kaleidoscope-LED-AlphaSquare.h"

// highlight active modifiers
#include <Kaleidoscope-LED-ActiveModColor.h>
// keep modifiers active for a moment
#include <Kaleidoscope-OneShot.h>
#include <kaleidoscope/hid.h>

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-Model01-TestMode.h"

// Support for swapping shifts effects on a key
#include "Kaleidoscope-TopsyTurvy.h"

// Change symbols for keys
#include "Kaleidoscope-ShapeShifter.h"

#include "Kaleidoscope-HostOS.h"
#include "Kaleidoscope/HostOS-select.h"
#include "Kaleidoscope-Unicode.h"

/** This 'enum' is a list of all the macros used by the Model 01's firmware
  * The names aren't particularly important. What is important is that each
  * is unique.
  *
  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

enum { 
      L_AE,
      L_OE,
      L_AA,
      M_WIN,
      M_MAC,
      M_LNX
};



/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   the special nature of the PROG key
  *   keeping NUM and FN consistent and accessible on all layers
  *
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  */

enum { QWERTY, FUNCTION, NUMPAD }; // layers

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

const Key keymaps[][ROWS][COLS] PROGMEM = {

  [QWERTY] = KEYMAP_STACKED
  (Key_Escape,   Key_1, Key_2, Key_3, Key_4, Key_5, Key_LeftBracket,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_LeftGui,
   OSM(LeftAlt), Key_Backspace, OSM(LeftShift), OSM(LeftControl),
   ShiftToLayer(FUNCTION),

   Key_RightBracket,  Key_6, Key_7, Key_8,     Key_9,         Key_0,         Key_KeypadNumLock,
   Key_Enter,         Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                      Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   Key_RightGui,      Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   OSM(RightControl), OSM(LeftShift),  Key_Spacebar, OSM(RightAlt),
   ShiftToLayer(FUNCTION)),

  [FUNCTION] =  KEYMAP_STACKED
  (___,      Key_F1,           Key_F2,          Key_F3,           Key_F4,          Key_F5,           LSHIFT(Key_9),
   Key_Tab,  Key_mouseWarpEnd, Key_mouseWarpNW, Key_mouseUp,      Key_mouseWarpNE, Key_mouseBtnL,    Key_mouseScrollUp,
   Key_Home, Key_Insert,       Key_mouseL,      Key_mouseDn,      Key_mouseR,      Key_mouseBtnR,
   Key_End,  Key_PrintScreen,  Key_mouseWarpSW, Key_mouseWarpEnd, Key_mouseWarpSE, Key_mouseBtnM,    Key_mouseScrollDn,
   ___, Key_Delete, ___, ___,
   ___,

   LSHIFT(Key_0),              Key_F6,          Key_F7,           Key_F8,                   Key_F9,                   Key_F10,         Key_F11,
   ___,                        Key_PageUp,      Key_Home,         Key_UpArrow,              Key_End,                  M(L_AA),         Key_F12,
                               Key_PageDown,    Key_LeftArrow,    Key_DownArrow,            Key_RightArrow,           M(L_AE),         M(L_OE),
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack,Key_Mute,   Consumer_VolumeDecrement, Consumer_VolumeIncrement, Key_Backslash,   Key_Pipe,
   ___, ___, Key_Enter, ___,
   ___),

  [NUMPAD] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, Key_LEDEffectNext,
   M(M_LNX), M(M_WIN), M(M_MAC), ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   ___,  ___, Key_Keypad7, Key_Keypad8,   Key_Keypad9,        Key_KeypadSubtract, ___,
   ___,                    ___, Key_Keypad4, Key_Keypad5,   Key_Keypad6,        Key_KeypadAdd,      ___,
                           ___, Key_Keypad1, Key_Keypad2,   Key_Keypad3,        Key_Equals,         Key_Quote,
   ___,                    ___, Key_Keypad0, Key_KeypadDot, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___)
};

// https://community.keyboard.io/t/dedicated-brackets-key/534/6
static const kaleidoscope::ShapeShifter::dictionary_t shape_shift_dictionary[] PROGMEM = {
  // {LSHIFT(Key_9), Key_Comma},
  // {LSHIFT(Key_0), Key_Period},
  {Key_NoKey, Key_NoKey},
 };
 
/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */
 const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
    case L_AE:
      win_latin1_shift(230, 198, keyState);
      break;
    case L_OE:
      win_latin1_shift(248, 216, keyState);
      break;
    case L_AA:
      win_latin1_shift(229, 197, keyState);
      break;
    case M_LNX:
      HostOS.os(kaleidoscope::hostos::LINUX);
      break;
    case M_MAC:
      HostOS.os(kaleidoscope::hostos::OSX);
      break;
    case M_WIN:
      HostOS.os(kaleidoscope::hostos::WINDOWS);
      break;
  }
  return MACRO_NONE;
}

// static void unicode(uint32_t lower, uint32_t upper, uint8_t keyState) {
//   if (!keyToggledOn(keyState)) {
//     return;
//   }
//   bool shifted = kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift)
//   || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift);

//   Unicode.type(shifted ? lower : upper);
// }

static void win_latin1_shift(int lower, int upper, uint8_t keyState) {
  bool shifted = kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift)
  || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift);

  win_latin1(shifted ? upper : lower, keyState);
}

static void win_latin1(int keycode, uint8_t keyState) {
  if (!keyToggledOn(keyState)) {
    return;
  }
  int digits[4];
  digits[0] = 0; // (keycode > 999) ? keycode / 1000 % 10 : 0;
  digits[1] = (keycode > 99) ? keycode / 100 % 10 : 0;
  digits[2] = (keycode > 9) ? keycode / 10 % 10 : 0;
  digits[3] = keycode % 10;
  kaleidoscope::hid::pressRawKey(Key_LeftAlt);
  kaleidoscope::hid::sendKeyboardReport();
  for (int i=0; i < 4; i++) {
    Key key = keypad(digits[i]);
    kaleidoscope::hid::pressRawKey(key);
    kaleidoscope::hid::sendKeyboardReport();
    kaleidoscope::hid::releaseRawKey(key);
    kaleidoscope::hid::sendKeyboardReport();    
    delay(1);    
  }
  kaleidoscope::hid::releaseRawKey(Key_LeftAlt);
  kaleidoscope::hid::sendKeyboardReport();  
}

static Key keypad(int digit) {
  switch (digit) {
    case 0: return Key_Keypad0;
    case 1: return Key_Keypad1;
    case 2: return Key_Keypad2;
    case 3: return Key_Keypad3;
    case 4: return Key_Keypad4;
    case 5: return Key_Keypad5;
    case 6: return Key_Keypad6;
    case 7: return Key_Keypad7;
    case 8: return Key_Keypad8;
    case 9: return Key_Keypad9;
  }
  return Key_Keypad0;
}


// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.


static kaleidoscope::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);


/** The 'setup' function is one of the two standard Arduino sketch functions.
  * It's called when your keyboard first powers up. This is where you set up
  * Kaleidoscope and any plugins.
  */

void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();
  HostOS.os(kaleidoscope::hostos::WINDOWS);
//  HostOS.os(kaleidoscope::hostos::OSX);
  // Next, tell Kaleidoscope which plugins you want to use.
  // The order can be important. For example, LED effects are
  // added in the order they're listed here.
  Kaleidoscope.use(
    // The boot greeting effect pulses the LED button for 10 seconds after the keyboard is first connected
    &BootGreetingEffect,

    // The hardware test mode, which can be invoked by tapping Prog, LED and the left Fn button at the same time.
    &TestMode,

    // LEDControl provides support for other LED modes
    &LEDControl,

    // We start with the LED effect that turns off all the LEDs.
    &LEDOff,

    // The rainbow effect changes the color of all of the keyboard's keys at the same time
    // running through all the colors of the rainbow.
    &LEDRainbowEffect,

    // The rainbow wave effect lights up your keyboard with all the colors of a rainbow
    // and slowly moves the rainbow across your keyboard
    &LEDRainbowWaveEffect,

    // The chase effect follows the adventure of a blue pixel which chases a red pixel across
    // your keyboard. Spoiler: the blue pixel never catches the red pixel
    &LEDChaseEffect,

    // These static effects turn your keyboard's LEDs a variety of colors
    &solidRed, &solidOrange, &solidYellow, &solidGreen, &solidBlue, &solidIndigo, &solidViolet,

    // The breathe effect slowly pulses all of the LEDs on your keyboard
    &LEDBreatheEffect,

    // The AlphaSquare effect prints each character you type, using your
    // keyboard's LEDs as a display
    &AlphaSquareEffect,

    // The stalker effect lights up the keys you've pressed recently
    &StalkerEffect,

    // The numlock plugin is responsible for lighting up the 'numpad' mode
    // with a custom LED effect
    &NumLock,

    // The macros plugin adds support for macros
    &Macros,

    // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
    &MouseKeys,

    // Swap the effect of the shift key
    &TopsyTurvy,

    // Change key codes for key
    &ShapeShifter,

    // Unicode input
    &Unicode,

    &ActiveModColorEffect,
    &OneShot
  );

  // While we hope to improve this in the future, the NumLock plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  NumLock.numPadLayer = NUMPAD;

  // We configure the AlphaSquare effect to use RED letters
  AlphaSquare.color = { 255, 0, 0 };

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  LEDRainbowEffect.brightness(150);
  LEDRainbowWaveEffect.brightness(150);

  // The LED Stalker mode has a few effects. The one we like is
  // called 'BlazingTrail'. For details on other options,
  // see https://github.com/keyboardio/Kaleidoscope-LED-Stalker
  StalkerEffect.variant = STALKER(BlazingTrail);

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  LEDOff.activate();

  // activeate shapeshifter
  ShapeShifter.dictionary = shape_shift_dictionary;

  ActiveModColorEffect.highlight_color = CRGB(0x66, 0x00, 0x00);  

  // configure one-shot:
  // disable sticky feature
  OneShot.double_tap_sticky = false;
  // shorter timer
  OneShot.time_out = 1500;
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
