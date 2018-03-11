# LL Data version of Keyboardio Model 01 Firmware

Modified firmware for the Keyboardio Model 01
https://github.com/keyboardio/Model01-Firmware

## Goal
Make a layout that is great for programming, for someone who is used to using a standard keyboard, with arrow keys.
Retain the basic US layout, but add support for typing danish characters.

## Features
- [x] remap arrows to inverted T (IJKL)
- [x] map U/O to ctrl + left/right arrow for easier text selection
- [x] remap mouse to inverted T (ESDF)
- [x] right fn locks to fn layer (ninja text editing mode!)
- [x] enable one shot modifiers (not sticky) (https://github.com/keyboardio/Kaleidoscope-OneShot)
- [x] programming brackets keys:
  - led =       =+
  - any =       '"
  - esc =       {|
  - butterfly = ]}
  
- [x] Danish characters to fn layer:
  - fn + p = å
  - fn + ; = æ
  - fn + ' = ø
  
- [x] Map fn + ZXCVA to ctrl + undo, cut, copy, paste, select all
- [x] fn + lower upper right thumb keys is left/right click
- [x] Thumb keys moved around (cmd, bksp, shift, ctrl) (ctrl, shift, space, alt)
- [x] PgDn doubles as a windows key, when held as a modifier (https://github.com/keyboardio/Kaleidoscope-DualUse)
- [x] prog key is mapped to esc
- [x] heatmap leds on by default

## Requirements
- [x] Assumes a US english keyboard layout
- [x] Requires WinCompose installed on windows
- [x] Requires compose key to be mapped to Right Alt (AltGr)

## Limitations
- Hardcodes Windows as OS (trouble with autodetection)
- Not tested on Linux (but should work, provided you configure the compose key)
- Does not work well on MacOS

## TODO
- [ ] MacOS support:
  - [ ] Use OS autodetection, when it gets stable: https://github.com/keyboardio/FingerprintUSBHost/issues/5
  - [ ] Figure out a way to change cmd/alt/ctrl around when using MacOS
  - [ ] Test compose key on MacOS
- [ ] Improved programming support
  - [ ] Use TOPSY plugin to swap [/{ and '/", since the latter are used way more
    https://github.com/keyboardio/Kaleidoscope-TopsyTurvy/issues/6
  - [ ] Move ()/<> to easier to reach positions
  - [ ] Insert key is squeezed in at fn + backtick
  - [ ] RightAlt doesn't work as a modifier key, while being mapped to Compose on windows.
- [ ] Improved LED
  - [ ] Change keyboard arrows color when in FUNCTION layer
- [ ] Mouse keys
  - [ ] I don't use the mouse keys ... could they be put to better use?
- [ ] Documentation
  - [ ] Make an image of the keyboard map

# Download and install

See the full guide on how to install at the Keyboardio site.
This is how I do it:

## Download hardware platform, including library source code 

```sh
mkdir -p hardware/keyboardio

## then clone the hardware definitions to make them available to the arduino environment
git clone --recursive https://github.com/keyboardio/Arduino-Boards.git hardware/keyboardio/avr
````

## Download the LL Data Model 01 Firmware

```sh
git clone https://github.com/lldata/Model01-Firmware.git
```

# Build and flash the firmware

Before you begin, make sure your Model 01 is connected to your computer.

```sh
cd Model01-Firmware
make flash
```

When the builder tells you to hit Enter to continue, hold down "Prog" in the top left corner of your keyboard and hit Enter.
