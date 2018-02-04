
// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

// GOAL - make a great layout for windows - since that is what I have to use a work ..
//
// Features:
// remap arrows to inverted T (IJKL)
// map U/O to ctrl + left/right arrow for easier text selection
// remap mouse to inverted T (ESDF)
// esc locks to fn layer (ninja text editing mode!)
// enable one shot modifiers (non sticky)
// map dedicated brackets key
// Danish characters to fn layer (;'p)
// Map fn + ZXCVA to ctrl + undo, cut, copy, paste, select all
// fn + lower upper right thumb keys is left/right click
// Thumb keys moved around (cmd, bksp, shift, ctrl) (ctrl, shift, space, alt)
// prog key is mapped to esc
// heatmap leds on by default
// assumes WinCompose is installed with US language and RightAlt modifier selected in windows

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

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
#include "Kaleidoscope-NumPad.h"

// Support for an "LED off mode"
#include "LED-Off.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for an LED mode that makes all the LEDs 'breathe'
#include "Kaleidoscope-LEDEffect-Breathe.h"

// Support for an LED mode creates a heat map of the most used keys
#include "Kaleidoscope-Heatmap.h"

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
#include <Kaleidoscope-Escape-OneShot.h>
#include <kaleidoscope/hid.h>
#include <Kaleidoscope-DualUse.h>

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-Model01-TestMode.h"

#include "Kaleidoscope-HostOS.h"
#include "Kaleidoscope/HostOS-select.h"
//#include "Kaleidoscope-Unicode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

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
      L_E_,
      L_EURO,
      L_POUND,
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

enum { QWERTY, NUMPAD, FUNCTION }; // layers

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

const Key keymaps[][ROWS][COLS] PROGMEM = {

  [QWERTY] = KEYMAP_STACKED
  (Key_Escape,   Key_1, Key_2, Key_3, Key_4, Key_5, Key_LeftBracket,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   MT(LeftGui, PageDown), Key_Z, Key_X, Key_C, Key_V, Key_B, Key_LeftBracket,
   OSM(LeftAlt), Key_Backspace, OSM(LeftShift), OSM(LeftControl),
   ShiftToLayer(FUNCTION),

   Key_RightBracket,  Key_6, Key_7, Key_8,     Key_9,         Key_0,         LockLayer(NUMPAD),
   Key_Enter,         Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                      Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   Key_RightBracket,  Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   OSM(RightControl), OSM(LeftShift),  Key_Spacebar, Key_RightAlt, // Key_RightAlt is not oneshot, since wincompose assumes you tap and release the wincompose key
   LockLayer(FUNCTION)),

  [NUMPAD] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, Key_LEDEffectNext,
   M(M_LNX), ___, ___, ___, ___, ___, ___,
   M(M_WIN), ___, ___, ___, ___, ___,
   M(M_MAC), ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   ___, ___,       Key_Keypad7, Key_Keypad8,   Key_Keypad9,        Key_KeypadSubtract, ___,
   Key_Enter, ___, Key_Keypad4, Key_Keypad5,   Key_Keypad6,        Key_KeypadAdd,      Key_PrintScreen,
              ___, Key_Keypad1, Key_Keypad2,   Key_Keypad3,        Key_Equals,         Key_Quote,
   ___, Key_KeypadMultiply, Key_Keypad0, Key_Comma, Key_Period,    Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___),
    
  [FUNCTION] =  KEYMAP_STACKED
  (Key_Escape,          Key_F1,           Key_F2,          Key_F3,        Key_F4,          Key_F5,           LSHIFT(Key_9),
   Key_Insert,          Key_mouseWarpSW,  Key_mouseWarpNW, Key_mouseUp,   Key_mouseWarpNE, Key_mouseWarpSE,  Key_Tab,
   Key_mouseScrollUp,   LCTRL(Key_A),     Key_mouseL,      Key_mouseDn,   Key_mouseR,      Key_mouseBtnL,
   Key_mouseScrollDn,   LCTRL(Key_Z),     LCTRL(Key_X),    LCTRL(Key_C),  LCTRL(Key_V),    Key_Backspace,    ___,
   ___, Key_Delete, ___, ___,
   ___,

   LSHIFT(Key_0),              Key_F6,          Key_F7,           Key_F8,                   Key_F9,                   Key_F10,         Key_F11,
   Key_Enter,                  Key_Home,  LCTRL(Key_LeftArrow),   Key_UpArrow,        LCTRL(Key_RightArrow),          M(L_AA),         Key_F12,
                               Key_End,         Key_LeftArrow,    Key_DownArrow,            Key_RightArrow,           M(L_AE),         M(L_OE),
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack,Key_Mute,   Consumer_VolumeDecrement, Consumer_VolumeIncrement, Key_Backslash,   Key_Pipe,
   ___, ___, Key_mouseBtnL, Key_mouseBtnR,
   ___)
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
      compose2(Key_A, true, Key_E, true, keyState);
      break;
    case L_OE:
      compose2(Key_Slash, false, Key_O, true, keyState);
      break;
    case L_AA:
      compose2(Key_O, false, Key_A, true, keyState);
      break;
    case L_E_:
      compose2(Key_Quote, false, Key_E, true, keyState);
      break;
    case L_EURO:
      compose2(Key_E, false, Key_Equals, false, keyState);
      break;
    case L_POUND:
      compose2(Key_Minus, false, Key_L, false, keyState);
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

static void compose2(Key key1, bool shift1, Key key2, bool shift2, uint8_t keyState) {
  if (!keyToggledOn(keyState)) {
    return;
  }
    bool shifted = kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift)
  || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift);

  tap(Key_RightAlt);
  if (shifted && shift1) press(Key_LeftShift);
  tap(key1);
  if (shifted && shift1) release(Key_LeftShift);
  if (shifted && shift2) press(Key_LeftShift);
  tap(key2);
  if (shifted && shift2) release(Key_LeftShift);
  //release(Key_RightAlt);
}

static void press(Key key) {
  kaleidoscope::hid::pressKey(key);
  kaleidoscope::hid::sendKeyboardReport();
}

static void release(Key key) {
  kaleidoscope::hid::releaseKey(key);
  kaleidoscope::hid::sendKeyboardReport();
}

static void tap(Key key) {
  press(key);
  release(key);
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

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::HostPowerManagement::Suspend:
    LEDControl.paused = true;
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    break;
  case kaleidoscope::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

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

    &HeatmapEffect,

    // These static effects turn your keyboard's LEDs a variety of colors
    &solidRed, &solidOrange, &solidYellow, &solidGreen, &solidBlue, &solidIndigo, &solidViolet,

    // The breathe effect slowly pulses all of the LEDs on your keyboard
    &LEDBreatheEffect,

    // The AlphaSquare effect prints each character you type, using your
    // keyboard's LEDs as a display
    &AlphaSquareEffect,

    // The stalker effect lights up the keys you've pressed recently
    &StalkerEffect,

    // The numpad plugin is responsible for lighting up the 'numpad' mode
    // with a custom LED effect
    &NumPad,

    // The macros plugin adds support for macros
    &Macros,

    // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
    &MouseKeys,

    // Unicode input
    //&Unicode,

    &ActiveModColorEffect,
    &OneShot,
    &EscapeOneShot,
    &DualUse,

    // The HostPowerManagement plugin enables waking up the host from suspend,
    // and allows us to turn LEDs off when it goes to sleep.
    &HostPowerManagement
  );

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  NumPad.numPadLayer = NUMPAD;

  // We configure the AlphaSquare effect to use RED letters
  AlphaSquare.color = { 125, 0, 125 };

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  LEDRainbowEffect.brightness(150);
  LEDRainbowWaveEffect.brightness(150);

  // The LED Stalker mode has a few effects. The one we like is
  // called 'BlazingTrail'. For details on other options,
  // see https://github.com/keyboardio/Kaleidoscope-LED-Stalker
  StalkerEffect.variant = STALKER(BlazingTrail);

  // We want the keyboard to be able to wake the host up from suspend.
  HostPowerManagement.enableWakeup();

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  //LEDOff.activate();
  //StalkerEffect.activate();
  HeatmapEffect.activate();
  
  ActiveModColorEffect.highlight_color = CRGB(0x00, 0x00, 0x99);  

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
