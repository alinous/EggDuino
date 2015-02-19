Eggduino
====

This is a fork of Arduino Firmware for Eggbot / Spherebot with Inkscape-Integration by cocktailyogi.

Improvements over the original version:
- stepper move command acknowledges _before_ movement - it allows to receive next command in background providing smoother operation
- PRG button support - allows to pause plotting
- pen toggle button (pen up and down positions are stored in eeprom)
- motor on/off button
- switched to 16x microstepping

I have also modified inkscape extension:
- you don't have to disable autoreset (although it is still better to do it anyway)
- arduinos are properly autodetected in linux (tested with chinese CH340G-based arduino)

Below slightly updated README from original repository:

Version 1.2

Regards: Eggduino-Firmware by Joachim Cerny, 2014

Thanks for the nice libs ACCELSTEPPER and SERIALCOMMAND, which made this project much easier. Thanks to the Eggbot-Team for such a funny and enjoyable concept! Thanks to my wife and my daughter for their patience. :-)

Features:

- Implemented Eggbot-Protocol-Version 2.1.0
- Turn-on homing: switch-on position of pen will be taken as reference point.
- No collision-detection!!
- Supported Servos: At least one type ;-) I use Arduino Servo-Lib with TG9e- standard servo.
- Full Arduino-Compatible. I used an Arduino Uno

Tested and fully functional with Inkscape.

Installation:

- Upload Eggduino.ino with Arduino-IDE or similar tool to your Arudino (i.e. Uno)
- Disable Autoreset on Arduinoboard (there are several ways to do this... Which one does not matter...)
- Install Inkscape Tools wit Eggbot extension. Detailed instructions: (You just need to complete Steps 1 and 2)
http://wiki.evilmadscientist.com/Installing_software or my modified version: https://github.com/bartebor/eggbot_extensions

Todos and Feature-Wishlist:

- collision control via penMin/penMax
- implement homing sequence via microswitch or optical device
