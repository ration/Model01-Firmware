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

# Link
[Layout editor](http://www.keyboard-layout-editor.com/##@_backcolor=%23ffffff&name=keyboard.io%20Model%2001&author=Layout%2F:%20Lasse%20Lindg%C3%A5rd.%20Template%2F:%20Gergely%20Nagy%20%3Ckbd%2F@gergo.csillger.hu%3E&switchMount=alps&switchBrand=matias&switchType=PG155B01&pcb:true%3B&@_x:3&c=%23d9dae0&fa@:0&:0&:0&:1%3B%3B&=%23%0A%0A%0AF3%0A%0A%0A3&_x:10%3B&=*%0A%0A%0AF8%0A%0A%0A8%3B&@_y:-0.875&x:2&t=%230d0d0b%3B&=%2F@%0A%0A%0AF2%0A%0A%0A2&_x:1&t=%23000000%3B&=$%0A%0A%0AF4%0A%0A%0A4&_x:8%3B&=%2F&%0A%0A%0AF7%0A%0A%0A7&_x:1&t=%230d0d0b%3B&=(%0A%0A%0AF9%0A%0A%0A9%3B&@_y:-0.875&x:5&t=%23000000%3B&=%25%0A%0A%0AF5%0A%0A%0A5&_a:5&f:6&fa@:4&:0&:0&:1&:0&:0&:4%3B&h:1.5%3B&=+%0A%0A%0A%0A%0A%0A%2F=&_x:4&f:6&h:1.5%3B&=%22%0A%0A%0A%0A%0A%0A'&_a:4&f:3&fa@:0&:0&:0&:1%3B%3B&=%5E%0A%0A%0AF6%0A%0A%0A6%3B&@_y:-0.875%3B&=%0Aprog%0A%0A%0A%0A%0Aesc&_t=%230d0d0b%3B&=!%0A%0A%0AF1%0A%0A%0A1&_x:14%3B&=)%0A%0A%0AF10%0A%0A%0A0&_t=%23000000%3B&=Num%0A%0A%0AF11%0A%0A%0Alock%3B&@_y:-0.375&x:3&fa@:0&:0&:0&:2%3B%3B&=%0A%0A%0A%3Ci%20class%2F='fa%20fa-mouse-pointer'%3E%3C%2F%2Fi%3E%3Ci%20class%2F='fa%20fa-arrow-up'%3E%3C%2F%2Fi%3E%0A%0A%0AE&_x:10&f:3%3B&=%0A%0A%0A%3Ci%20class%2F='fa%20fa-arrow-up'%3E%3C%2F%2Fi%3E%0A%0A%0AI%3B&@_y:-0.875&x:2&t=%230d0d0b&f:3%3B&=%0A%0A%0A%E2%97%B0%0A%0A%0AW&_x:1&t=%23000000&f:3%3B&=%0A%0A%0A%E2%97%B3%0A%0A%0AR&_x:8&fa@:0&:0&:0&:6%3B%3B&=%0A%0A%0A%3Ci%20class%2F='kb%20kb-Line-Start'%3E%3C%2F%2Fi%3E%0A%0A%0AU&_x:1&t=%230d0d0b%3B&=%0A%0A%0A%3Ci%20class%2F='kb%20kb-Line-End'%3E%3C%2F%2Fi%3E%0A%0A%0AO%3B&@_y:-0.875&x:5&t=%23000000&f:3%3B&=%0A%0A%0A%E2%97%B2%0A%0A%0AT&_x:6&fa@:0&:0&:0&:1%3B%3B&=%0A%0A%0AHome%0A%0A%0AY%3B&@_y:-0.875&t=%230d0d0b%3B&=~%0Ainsert%0A%0A%0A%0A%0A%60&_f:3%3B&=%0A%0A%0A%E2%97%B1%0A%0A%0AQ&_x:14&fa@:0&:0&:0&:2%3B%3B&=%0A%0A%0A%C3%85%0A%0A%0AP&_fa@:0&:0&:0&:1%3B%3B&=+%0A%0A%0AF12%0A%0A%0A%2F=%3B&@_y:-0.625&x:6&t=%23000000&a:7&h:1.5%3B&=tab&_x:4&h:1.5%3B&=enter%3B&@_y:-0.75&x:3&a:4&fa@:0&:0&:0&:2%3B%3B&=%0A%0A%0A%3Ci%20class%2F='fa%20fa-mouse-pointer'%3E%3C%2F%2Fi%3E%3Ci%20class%2F='fa%20fa-arrow-down'%3E%3C%2F%2Fi%3E%0A%0A%0AD&_x:10&f:3%3B&=%0A%0A%0A%3Ci%20class%2F='fa%20fa-arrow-down'%3E%3C%2F%2Fi%3E%0A%0A%0AK%3B&@_y:-0.875&x:2&t=%230d0d0b&f:3%3B&=%0A%0A%0A%3Ci%20class%2F='fa%20fa-mouse-pointer'%3E%3C%2F%2Fi%3E%3Ci%20class%2F='fa%20fa-arrow-left'%3E%3C%2F%2Fi%3E%0A%0A%0AS&_x:1&t=%23000000&f:3&n:true%3B&=%0A%0A%0A%3Ci%20class%2F='fa%20fa-mouse-pointer'%3E%3C%2F%2Fi%3E%3Ci%20class%2F='fa%20fa-arrow-right'%3E%3C%2F%2Fi%3E%0A%0A%0AF&_x:8&f:3&n:true%3B&=%0A%0A%0A%3Ci%20class%2F='fa%20fa-arrow-left'%3E%3C%2F%2Fi%3E%0A%0A%0AJ&_x:1&t=%230d0d0b&f:3%3B&=%0A%0A%0A%3Ci%20class%2F='fa%20fa-arrow-right'%3E%3C%2F%2Fi%3E%0A%0A%0AL%3B&@_y:-0.875&x:5&t=%23000000&fa@:0&:0&:0&:1%3B%3B&=%0A%0A%0A%3Cimg%20src%2F=%22data%2F:image%2F%2Fpng%2F%3Bbase64,iVBORw0KGgoAAAANSUhEUgAAAAwAAAAMCAYAAABWdVznAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAADKSURBVChTfc+vDwFhGMDxC+ZXMU0TCGxsJJtigiD4I1BE%2F%2F8EF0xSiJAiSCVTRZrPZbIpgBIqiC3yfe8+5u73z3T67593ds91rUBlFzJBCGl300UQMngoYQJZ6eOGNG8a4oAanBXLoQD78OkCSd2dkrRNlEMQdugWphYkaVfLv7o%2F%2F9Cwmc1KjKw79wRNzlCidZeGL3h2dB7rFRo7YQ5OJOETzsp64qVmr8NcJQjZ7C2KNunVxFscYcJSTRgFzehLYA2lhiiykqsDOMD2PGNL0wCbFeAAAAAElFTkSuQmCC%22%3E%0A%0A%0AG&_x:6%3B&=%0A%0A%0AEnd%0A%0A%0AH%3B&@_y:-0.875&t=%230d0d0b&f:3%3B&=%0A%0A%0A%3Ci%20class%2F='mss%20mss-Unicode-Page-Up-5'%3E%3C%2F%2Fi%3E%0A%0A%0APgUp&_a:6%3B&=A&_x:14&a:4&fa@:0&:0&:0&:2%3B%3B&=%0A%0A%0A%C3%86%0A%0A%0A%0A%0A%2F:%0A%2F%3B&=%0A%0A%0A%C3%98%0A%0A%0A%0A%0A%22%0A'%3B&@_y:-0.375&x:3&t=%23000000&f:3%3B&=%0A%0A%0A%3Ci%20class%2F='fa%20fa-copy'%3E%3C%2F%2Fi%3E%0A%0A%0AC&_x:10&f:3%3B&=%3C%0A%0A%0A%3Ci%20class%2F='kb%20kb-Multimedia-Volume-Down-1'%3E%3C%2F%2Fi%3E%0A%0A%0A.%3B&@_y:-0.875&x:2&t=%230d0d0b&f:3%3B&=%0A%0A%0A%3Ci%20class%2F='fa%20fa-cut'%3E%3C%2F%2Fi%3E%0A%0A%0AX&_x:1&t=%23000000&f:3%3B&=%0A%0A%0A%3Ci%20class%2F='fa%20fa-paste'%3E%3C%2F%2Fi%3E%0A%0A%0AV&_x:8&f:3%3B&=%0A%0A%0A%3Ci%20class%2F='kb%20kb-Multimedia-Mute-2'%3E%3C%2F%2Fi%3E%0A%0A%0AM&_x:1&t=%230d0d0b&f:3%3B&=%3E%0A%0A%0A%3Ci%20class%2F='kb%20kb-Multimedia-Volume-Up-2'%3E%3C%2F%2Fi%3E%0A%0A%0A.%3B&@_y:-0.875&x:5&t=%23000000&fa@:0&:0&:0&:5%3B%3B&=%0A%0A%0A%3Ci%20class%2F='kb%20kb-Unicode-BackSpace-DeleteLeft-Small'%3E%3C%2F%2Fi%3E%0A%0A%0AB&_a:5%3B&=%7B%0A%0A%0A%0A%0A%0A%5B&_x:4&a:4%3B&=%0A%0A%0A%3Ci%20class%2F='kb%20kb-Multimedia-Play-Pause'%3E%3C%2F%2Fi%3E%0A%0A%0A%0A%0A%7D%0A%5D&=%0A%0A%0A%3Ci%20class%2F='kb%20kb-Multimedia-FastForward-End'%3E%3C%2F%2Fi%3E%0A%0A%0AN%3B&@_y:-0.875&a:0%3B&=%0A%0A%0A%3Ci%20class%2F='mss%20mss-Unicode-Page-Down-5'%3E%3C%2F%2Fi%3E%0AWin%0A%0APgDn&_t=%230d0d0b&a:4%3B&=%0A%0A%0A%3Ci%20class%2F='fa%20fa-undo'%3E%3C%2F%2Fi%3E%0A%0A%0AZ&_x:14%3B&=%0A%0A%0A%5C%0A%0A%0A%0A%0A%3F%0A%2F%2F&_t=%23000000&f:9&fa@:0&:0&:0&:5&:0&:0&:0&:0&:6&:5%3B%3B&=%0A%0A%0A%7C%0A%0A%0A%0A%0A%2F&mdash%2F%3B%0A%2F&ndash%2F%3B%3B&@_r:15&rx:6.5&ry:4.25&y:0.5&x:-2&a:7&f:3%3B&=cmd%3B&@_r:20&y:-1&x:-0.75&a:4&fa@:0&:0&:0&:4%3B%3B&=%0A%0A%0A%3Ci%20class%2F='kb%20kb-Unicode-DeleteRight-Small'%3E%3C%2F%2Fi%3E%0A%0A%0A%0A%0A%0Abksp%3B&@_y:0.75&x:-0.5&a:7&w:1.25&h:1.25%3B&=fn%3B&@_r:25&y:-2.75&x:0.5%3B&=shift%3B&@_r:30&y:-1&x:1.75%3B&=ctrl%3B&@_r:-30&y:1.3499999999999996&x:1.25%3B&=ctrl%3B&@_r:-25&y:-1.25&x:2.75%3B&=shift%3B&@_r:-20&y:-1.3499999999999996&x:4.25&a:4&f:3%3B&=%0A%0A%0A%3Cimg%20src%2F=%22data%2F:image%2F%2Fpng%2F%3Bbase64,iVBORw0KGgoAAAANSUhEUgAAAAwAAAAMCAYAAABWdVznAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAADKSURBVChTfc+vDwFhGMDxC+ZXMU0TCGxsJJtigiD4I1BE%2F%2F8EF0xSiJAiSCVTRZrPZbIpgBIqiC3yfe8+5u73z3T67593ds91rUBlFzJBCGl300UQMngoYQJZ6eOGNG8a4oAanBXLoQD78OkCSd2dkrRNlEMQdugWphYkaVfLv7o%2F%2F9Cwmc1KjKw79wRNzlCidZeGL3h2dB7rFRo7YQ5OJOETzsp64qVmr8NcJQjZ7C2KNunVxFscYcJSTRgFzehLYA2lhiiykqsDOMD2PGNL0wCbFeAAAAAElFTkSuQmCC%22%3E%0A%0A%0A%0A%0A%0Aspace%3B&@_y:0.6500000000000004&x:3.5&a:5&w:1.25&h:1.25%3B&=%0Alock%0A%0A%0A%0A%0Afn%3B&@_r:-15&y:-3.1500000000000004&x:5.75&a:4&fa@:0&:0&:0&:0&:0&:0&:0&:0&:1%3B%3B&=%0A%0A%0A%3Cimg%20src%2F=%22data%2F:image%2F%2Fpng%2F%3Bbase64,iVBORw0KGgoAAAANSUhEUgAAAAwAAAAMCAYAAABWdVznAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAADGSURBVChTddA9C0FRGMDx42UxUl5KUTY2qzKaJJvVZKHsrAaDL+AbyMCq5AuIwWI1SJmllFL8n3N17r2H+69fnTM85557lFUWPYzRQRJNDNFACaY+zpjg%2F%2FXVHFwXMkIFOTtkjpXfugHihgjZG0B1QdpY674BYIQG5sorhKgtP9sANphyOiHvYA8IkAw%2F%2FIPwR5wiQnnpxlYPaV1QVpZ%2F%2FlTEfIVXwPIO4f0zi2KDeRJfUWwwBpV5FHDFlP8LYwWlthhjjo8KfUBMQo03HwXEMYAAAAASUVORK5CYII%2F=%22%3E%0A%0A%0A%0A%0Acompose%0AAltGr)
