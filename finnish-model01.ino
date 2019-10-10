// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for storing the keymap in EEPROM
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"

// Support for communicating with the host via a simple Serial protocol
#include "Kaleidoscope-FocusSerial.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
//#include "Kaleidoscope-NumPad.h"

// // Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// // when the keyboard is connected to a computer (or that computer is powered on)
// #include "Kaleidoscope-LEDEffect-BootGreeting.h"

// // Support for an LED mode that makes all the LEDs 'breathe'
// #include "Kaleidoscope-LEDEffect-Breathe.h"

// // Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
// #include "Kaleidoscope-LEDEffect-Chase.h"

// // Support for LED modes that pulse the keyboard's LED in a rainbow pattern
// #include "Kaleidoscope-LEDEffect-Rainbow.h"

// // Support for an LED mode that lights up the keys as you press them
// #include "Kaleidoscope-LED-Stalker.h"

// // Support for an LED mode that prints the keys you press in letters 4px high
// #include "Kaleidoscope-LED-AlphaSquare.h"

// Support for shared palettes for other plugins, like Colormap below
#include "Kaleidoscope-LED-Palette-Theme.h"

// Support for an LED mode that lets one configure per-layer color maps
#include "Kaleidoscope-Colormap.h"

#include <Kaleidoscope-LEDEffect-FunctionalColor.h>

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-HardwareTestMode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

// Support for magic combos (key chords that trigger an action)
#include "Kaleidoscope-MagicCombo.h"

// Support for USB quirks, like changing the key state report protocol
#include "Kaleidoscope-USB-Quirks.h"

// Multiple Keycodes with single key
#include <Kaleidoscope-Qukeys.h>

// Oneshot modifiers (press Ctrl, a results in Ctrl+a)
#include <Kaleidoscope-OneShot.h>


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

enum { MACRO_VERSION_INFO, MACRO_ANY, L_AE, L_OE,
MACRO_FCUP, MACRO_FCDOWN};



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
  *   keeping NUM and FN consistent and accessible on all layers
  *
  * The PROG key is special, since it is how you indicate to the board that you
  * want to flash the firmware. However, it can be remapped to a regular key.
  * When the keyboard boots, it first looks to see whether the PROG key is held
  * down; if it is, it simply awaits further flashing instructions. If it is
  * not, it continues loading the rest of the firmware and the keyboard
  * functions normally, with whatever binding you have set to PROG. More detail
  * here: https://community.keyboard.io/t/how-the-prog-key-gets-you-into-the-bootloader/506/8
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
  *
  */

enum { PRIMARY, NUMPAD, FUNCTION }; // layers


/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAPS(

  [PRIMARY] = KEYMAP_STACKED
  (Key_Escape,          Key_1, Key_2, Key_3, Key_4, Key_5, LSHIFT(Key_9),
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_LeftShift,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_LeftGui, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_LeftBracket,
   
   Key_LeftControl, Key_Backspace,  Key_LeftShift, Key_LeftAlt,
   ShiftToLayer(FUNCTION),

   LSHIFT(Key_0),  Key_6, Key_7, Key_8,     Key_9,         Key_0,         Key_Quote,
   Key_Enter,     Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                  Key_H, Key_J, Key_K,     Key_L,         M(L_OE),       M(L_AE),
   Key_RightBracket,  Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   
   Key_LeftAlt, Key_RightShift, Key_Spacebar, Key_LeftControl,
   ShiftToLayer(FUNCTION)),


  [NUMPAD] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   ___,  ___, Key_7, Key_8,      Key_9,              Key_KeypadSubtract, ___,
   ___,                    ___, Key_4, Key_5,      Key_6,              Key_KeypadAdd,      ___,
                           ___, Key_1, Key_2,      Key_3,              Key_Equals,         ___,
   ___,                    ___, Key_0, Key_Period, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___),

  [FUNCTION] =  KEYMAP_STACKED
  (Key_LEDEffectNext,      Key_F1,           Key_F2,      Key_F3,     Key_F4,        Key_F5,           Key_CapsLock,
   Key_Tab,  ___,          ___,              Key_mouseUp, Key_mouseScrollUp, Key_mouseBtnR,___,  
   Key_Home, ___, Key_mouseL,       Key_mouseDn, Key_mouseR,  Key_mouseBtnL,
   Key_End,  Key_PrintScreen,  Key_Insert,  ___,        Key_mouseScrollDn, Key_mouseBtnM,___,   

   ___, Key_Delete, ___, ___,
   ___,

   Consumer_PlaySlashPause, Key_F6,                 Key_F7,          Key_F8,                   Key_F9,          Key_F10,          Key_F11,
   ___,    Key_PageUp,            ___,              Key_UpArrow,              ___,             ___,              Key_F12,
           Key_PageDown,          Key_LeftArrow,    Key_DownArrow,            Key_RightArrow,  ___,              ___,
   Key_Semicolon,          Consumer_Mute,         Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,    Key_Pipe,

   ___, ___, Key_Enter, ___,
   ___)
)


  // KEYMAP(

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

static void anyKeyMacro(uint8_t keyState) {
  static Key lastKey;
  bool toggledOn = false;
  if (keyToggledOn(keyState)) {
    lastKey.keyCode = Key_A.keyCode + (uint8_t)(millis() % 36);
    toggledOn = true;
  }

  if (keyIsPressed(keyState))
    kaleidoscope::hid::pressKey(lastKey, toggledOn);
}


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
    compose2(Key_Quote, true, Key_A, true, keyState);
    break;
  case L_OE:
    compose2(Key_Quote, true, Key_O, true, keyState);
    break;
  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;
  case MACRO_ANY:
    anyKeyMacro(keyState);
    break;
  case MACRO_FCUP:
    FunctionalColor::brightnessUp(keyState);
    break;
  
  case MACRO_FCDOWN:
    FunctionalColor::brightnessDown(keyState);
    break;
  }
  return MACRO_NONE;
}

/** Print Finnish ä and ö with compose */
static void compose2(Key key1, bool shift1, Key key2, bool shift2, uint8_t keyState) {
  if (!keyToggledOn(keyState)) {
    return;
 }
    bool shifted = kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift)
  || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift);

  tap(Key_RightAlt);
  if (shift1) press(Key_LeftShift);
  tap(key1);
  if (shift1) release(Key_LeftShift);
  if (shifted && shift2) press(Key_LeftShift);
  tap(key2);
  if (shifted && shift2) release(Key_LeftShift);
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

// BEGIN FunctionalColor

using namespace kaleidoscope::plugin::LEDFunctionalColor;


// Note: FunctionalColor allows you to use CSS color names (in lowercase)
// You can also control the brightness from 0-255 by using a dim() function on the color.

// Use color override Macros to set the color of specific keys--even those not customizable in a ColorMap struct
FC_START_COLOR_LIST(customColors)
 // Use any number of FCGROUPKEYs above a FC_KEYCOLOR to set several keys to the same color
 FC_GROUPKEY(Key_A)
 FC_KEYCOLOR(Key_Semicolon, orange)
 FC_GROUPKEY(Key_S)
 FC_KEYCOLOR(Key_L, yellow)
 FC_GROUPKEY(Key_D)
 FC_KEYCOLOR(Key_K, lime)
 FC_GROUPKEY(Key_F)
 FC_KEYCOLOR(Key_J, aqua)
 //FC_NOCOLOR makes a key not change color, as if "transparent".
 // In this example The uparrow key will not change the key color, even when on the active layer.
 FC_NOCOLOR(Key_UpArrow)

 // This shows how you can set the color of custom macros
 FC_GROUPKEY(M(MACRO_FCUP))
 FC_KEYCOLOR(M(MACRO_FCDOWN), cyan)
FC_END_COLOR_LIST


// An example showing how to make a simple configuration with no theme and a default color of pink.
// This is used in funColorSimpleColors
FC_START_COLOR_LIST(simpleColors)
 // Make homing keys yellow
 FC_GROUPKEY(Key_A)
 FC_GROUPKEY(Key_F)
 FC_GROUPKEY(Key_J)
 FC_KEYCOLOR(Key_Semicolon, yellow)
 // Brightness macros
 FC_GROUPKEY(M(MACRO_FCUP))
 FC_KEYCOLOR(M(MACRO_FCDOWN), cyan)
// If you want to specify a default color and you are not using a theme,
// use FC_END_COLOR_LIST_DEFAULT and specify the default color for all keys not specified above.
FC_END_COLOR_LIST_DEFAULT(pink)

// There are several ways you can make FunctionalColor instances.
// Some are commented out to save a few bytes of memory in the default jam-packed configuration.

// No arguments are needed to use the default theme and brightness.
FunctionalColor funColorDefault;

//You can specify an optional brightness 0-255, and an optional colorList can follow.
FunctionalColor funColorMono(200);

//You can specify only a color override list as shown above beginning with FC_START_COLOR_LIST(customColors)
FunctionalColor funColorCustomColors(FC_COLOR_LIST(customColors));

//You can also specify a colorList with the brightness after.
FunctionalColor funCustomColorsBright(FC_COLOR_LIST(customColors), 255);

// The last two examples will use custom themes - these are applied later in the setup() part of this .ino
// Look near the bottom of this file to see how this is done.
FunctionalColor funColorMyTheme;
// Note that you can combine custom color overrides with a custom theme, demonstrated in funColorGreen.
// adding ", 220, false" after the FC_COLOR_LIST saves about 32 bytes here but it's not necessary.
FunctionalColor funColorGreen(FC_COLOR_LIST(customColors));

// This is how you explicitly specify NOT to use a theme - add "false" after the brightness
// to save memory and make a simple configuration.
FunctionalColor funColorSimpleColors(FC_COLOR_LIST(simpleColors), 220, false);

// If you're making a custom theme to be applied later, you can also avoid specifying a theme
// (to save memory) without specifying a colorList with the following:
FunctionalColor funColorNoTheme(220, false);


//To create a theme, make a subclass of one of the themes in FunctionalColor.
//They are colorMap, colorMapDefault, colorMapMono, colorMapDuo, colorMapFruit, etc.
//This example makes a few tweaks to colorMapMono that customize specific modifier keys
struct myTheme: public colorMapMono {
  FC_MAP_COLOR(shift, darkseagreen)
  FC_MAP_COLOR(control, skyblue)
  FC_MAP_COLOR(alt, forestgreen)
  FC_MAP_COLOR(gui, pink)
  //You can also set something to "nocolor" which will avoid coloring a set of keys
  // if they already are part of another larger group - ie set shift to nocolor and
  // shiftkeys will inherit the color assigned to modifier
  // FC_MAP_COLOR(shift, nocolor);
};


// For reference, this example theme struct shows the full list of properties you can set
// in case you want to define a completely custom theme. In practice you can
// just subclass one you like and change only the elements you want to modify
// with the FC_MAP_COLOR() function.
struct colorMapGreen: public colorMap {
  // baseColor is used with just changes in brightness for a largely monochromatic theme.
  // You can change baseColor from green to change all these colors at once.
  FC_MAP_COLOR(baseColor, green)

  // defaultColor is used when there is no color defined for a key.
  // This is the only way to color "prog" if you don't assign a function to it.
  // When referring to a previously defined color that was defined with FC_MAP_COLOR
  // (including in base color map classes), you must use the FC_REF_MAP_COLOR() function.
  FC_MAP_COLOR(defaultColor, dim(FC_REF_MAP_COLOR(baseColor), 100))

  // shift, control, gui, and alt can all be colored by "modifier" if nocolor is set here.
  FC_MAP_COLOR(shift, nocolor)
  FC_MAP_COLOR(control, nocolor)
  // Windows Logo or, on macOS, command keys 
  FC_MAP_COLOR(gui, nocolor)
  FC_MAP_COLOR(alt, nocolor)
  
  FC_MAP_COLOR(modifier, dim(FC_REF_MAP_COLOR(baseColor), 130))
  FC_MAP_COLOR(alpha, dim(FC_REF_MAP_COLOR(baseColor), 80))
  FC_MAP_COLOR(number, dim(FC_REF_MAP_COLOR(baseColor), 100))
  FC_MAP_COLOR(punctuation, dim(FC_REF_MAP_COLOR(baseColor), 120))

  // F1-F12 and F13-F24
  FC_MAP_COLOR(function, dim(FC_REF_MAP_COLOR(baseColor), 150))
  
  // Page Up, Page Down, Home, End, Insert, and Delete (if del has nocolor)
  FC_MAP_COLOR(navigation, dim(FC_REF_MAP_COLOR(baseColor), 180))
  
  // Print Screen, Pause/Break, and Scroll Lock keys (brightness on Macs)
  FC_MAP_COLOR(system, dim(FC_REF_MAP_COLOR(baseColor), 50))
  
  FC_MAP_COLOR(arrow, dim(FC_REF_MAP_COLOR(baseColor), 250))
  FC_MAP_COLOR(keypad, dim(FC_REF_MAP_COLOR(baseColor), 230))

  // Includes play/pause, next/prev, volume control, mute, etc.
  FC_MAP_COLOR(media, dim(FC_REF_MAP_COLOR(baseColor), 250))
  
  FC_MAP_COLOR(mouseWheel, nocolor)
  FC_MAP_COLOR(mouseButton,nocolor)
  FC_MAP_COLOR(mouseWarp, nocolor)
  FC_MAP_COLOR(mouseMove, nocolor)
  // mouse includes the four above groups if nocolor is set for those
  FC_MAP_COLOR(mouse, dim(FC_REF_MAP_COLOR(baseColor), 220))
  FC_MAP_COLOR(space, dim(FC_REF_MAP_COLOR(baseColor), 100))
  FC_MAP_COLOR(tab, dim(FC_REF_MAP_COLOR(baseColor), 100))
  FC_MAP_COLOR(enter, dim(FC_REF_MAP_COLOR(baseColor), 255))
  FC_MAP_COLOR(backspace, dim(FC_REF_MAP_COLOR(baseColor), 100))
  FC_MAP_COLOR(escape, dim(FC_REF_MAP_COLOR(baseColor), 100))
  FC_MAP_COLOR(del, dim(FC_REF_MAP_COLOR(baseColor), 255))

  //fn will work properly if your FUNCTION layer is between layers 1-3
  FC_MAP_COLOR(fn, dim(FC_REF_MAP_COLOR(baseColor), 255))
  
  //NumLock and other layer locks
  FC_MAP_COLOR(lock, dim(FC_REF_MAP_COLOR(baseColor), 255))
  FC_MAP_COLOR(LEDEffectNext, dim(FC_REF_MAP_COLOR(baseColor), 255))
};

// END FunctionalColor

 /** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
  * and turns them back on when it wakes up.
  */
void toggleLedsOnSuspendResume(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    LEDControl.paused = true;
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
}
}

  
/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

/** This 'enum' is a list of all the magic combos used by the Model 01's
 * firmware The names aren't particularly important. What is important is that
 * each is unique.
 *
 * These are the names of your magic combos. They will be used by the
 * `USE_MAGIC_COMBOS` call below.
 */
enum {
  // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
  // mode.
  COMBO_TOGGLE_NKRO_MODE,
  // Enter test mode
  COMBO_ENTER_TEST_MODE,
  COMBO_LOCK_FUNCTION
};

/** Wrappers, to be used by MagicCombo. **/

/**
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

/**
 *  This enters the hardware test mode
 */
static void enterHardwareTestMode(uint8_t combo_index) {
  HardwareTestMode.runTests();
}


static void lockFunction(uint8_t combo_index) {
  if (!Layer.isActive(FUNCTION)) {
    Layer.activate(FUNCTION);
  } else {
    Layer.deactivate(FUNCTION);
  }
}

/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
USE_MAGIC_COMBOS(
		 [COMBO_TOGGLE_NKRO_MODE] = {.action = toggleKeyboardProtocol,
					     // Left Fn + Esc + Shift
					     .keys = { R3C6, R2C6, R3C7 }
		 }, [COMBO_ENTER_TEST_MODE] = {
					       .action = enterHardwareTestMode,
					       // Left Fn + Prog + LED
					       .keys = { R3C6, R0C0, R0C6 }
		 }, [COMBO_LOCK_FUNCTION] = {
					     .action = lockFunction,
					     // Left Fn + Right Fn
					     .keys = {R0C7, R0C8}
  });

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
  // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
  // editable keymap in EEPROM.
  EEPROMSettings,
  EEPROMKeymap,

  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  Focus,

  // FocusSettingsCommand adds a few Focus commands, intended to aid in
  // changing some settings of the keyboard, such as the default layer (via the
  // `settings.defaultLayer` command)
  FocusSettingsCommand,

  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  FocusEEPROMCommand,

  // The boot greeting effect pulses the LED button for 10 seconds after the
  // keyboard is first connected
  //  BootGreetingEffect,

  // The hardware test mode, which can be invoked by tapping Prog, LED and the
  // left Fn button at the same time.
  HardwareTestMode,

  // LEDControl provides support for other LED modes
  LEDControl,

  // We start with the LED effect that turns off all the LEDs.
  //  LEDOff,

// All FunctionalColor instances go here in the order you want them in
  funColorDefault,
  funColorMono,
  funColorCustomColors,
  funCustomColorsBright,
  funColorMyTheme,
  funColorGreen,
  funColorSimpleColors,
  funColorNoTheme,
  
  // The rainbow effect changes the color of all of the keyboard's keys at the same time
  // running through all the colors of the rainbow.
  //  LEDRainbowEffect,

  // The rainbow wave effect lights up your keyboard with all the colors of a rainbow
  // and slowly moves the rainbow across your keyboard
  //  LEDRainbowWaveEffect,

  // The chase effect follows the adventure of a blue pixel which chases a red pixel across
  // your keyboard. Spoiler: the blue pixel never catches the red pixel
  //  LEDChaseEffect,

  // These static effects turn your keyboard's LEDs a variety of colors
  //  solidRed, solidOrange, solidYellow, solidGreen, solidBlue, solidIndigo, solidViolet,

  // The breathe effect slowly pulses all of the LEDs on your keyboard
  //  LEDBreatheEffect,

  // The AlphaSquare effect prints each character you type, using your
  // keyboard's LEDs as a display
  //  AlphaSquareEffect,

  // The stalker effect lights up the keys you've pressed recently
  //  StalkerEffect,

  // The LED Palette Theme plugin provides a shared palette for other plugins,
  // like Colormap below
  //  LEDPaletteTheme,

  // The Colormap effect makes it possible to set up per-layer colormaps
  //  ColormapEffect,

  // The numpad plugin is responsible for lighting up the 'numpad' mode
  // with a custom LED effect
  //  NumPad,

  // The macros plugin adds support for macros
  Macros,

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  MouseKeys,

  // The HostPowerManagement plugin allows us to turn LEDs off when then host
  // goes to sleep, and resume them when it wakes up.
  HostPowerManagement,

  // The MagicCombo plugin lets you use key combinations to trigger custom
  // actions - a bit like Macros, but triggered by pressing multiple keys at the
  // same time.
  MagicCombo,
  
  // The USBQuirks plugin lets you do some things with USB that we aren't
  // comfortable - or able - to do automatically, but can be useful
  // nevertheless. Such as toggling the key report protocol between Boot (used
  // by BIOSes) and Report (NKRO).
  USBQuirks, 

  OneShot, 
  
  Qukeys

);

/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  //NumPad.numPadLayer = NUMPAD;

  // We configure the AlphaSquare effect to use RED letters
  //AlphaSquare.color = CRGB(255, 0, 0);

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  //LEDRainbowEffect.brightness(150);
  //LEDRainbowWaveEffect.brightness(150);

  // Set the action key the test mode should listen for to Left Fn
  HardwareTestMode.setActionKey(R3C6);

  // The LED Stalker mode has a few effects. The one we like is called
  // 'BlazingTrail'. For details on other options, see
  // https://github.com/keyboardio/Kaleidoscope/blob/master/doc/plugin/LED-Stalker.md
  //StalkerEffect.variant = STALKER(BlazingTrail);

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  //  LEDOff.activate();

  // To make the keymap editable without flashing new firmware, we store
  // additional layers in EEPROM. For now, we reserve space for five layers. If
  // one wants to use these layers, just set the default layer to one in EEPROM,
  // by using the `settings.defaultLayer` Focus command, or by using the
  // `keymap.onlyCustom` command to use EEPROM layers only.
  EEPROMKeymap.setup(5);

  FC_SET_THEME(funColorMono, kaleidoscope::plugin::LEDFunctionalColor::colorMapMono);
  // The themes are: colorMap, colorMapDefault, colorMapFruit, colorMapMono, colorMapDuo,
  // colorMapPrincess, colorMapSea, colorMapFlower, colorMapKids, colorMapRedWhiteBlue.

  // This applies our custom themes to funColorMyTheme, funColorGreen, and funcolorNoTheme
  FC_SET_THEME(funColorMyTheme, myTheme);
  FC_SET_THEME(funColorGreen, colorMapGreen);
  // When a FunctionalColors instance is instantiated with no theme, one can be added later
  FC_SET_THEME(funColorNoTheme, colorMapGreen);
  
  // We need to tell the Colormap plugin how many layers we want to have custom
  // maps for. To make things simple, we set it to five layers, which is how
  // many editable layers we have (see above).
  //ColormapEffect.max_layers(5);
  //ColormapEffect.activate();

  MouseKeys.speed = 10;
  MouseKeys.speedDelay = 1;
  MouseKeys.accelDelay = 30;
  MouseKeys.accelSpeed = 1; 

}

/** Loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
