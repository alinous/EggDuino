Eggduino
====

This is a fork of Arduino Firmware for Eggbot / Spherebot with Inkscape-Integration by cocktailyogi made after painting few eggs :)

I found that steppers did not move fluently. Furthermore, it was annoying to not have PRG button to pause plotting and also to toggle pen and disable motors (my steppers are very audible while stationary). Two latter buttons double function of manual commands in eggbot extension.

So, lets summarize changes over the original version:
- added new move command joining together move and PRG button testing (SM + OB = SMOB :) ). This command acknowledges _before_ engaging motion what allows to receive next command in background. It makes BIG difference, plotting is much more fluent. This command requires my custom version of eggbot inkscape extension, see below.
- PRG button support - allows to pause plotting and make adjustments
- pen toggle button (pen up and down positions are stored in eeprom)
- motor on/off button
- 16x microstepping instead of original 8x

I have also modified [inkscape extension](https://github.com/bartebor/eggbot_extensions):
- you don't have to disable autoreset (although it is still better to do it anyway)
- arduinos are properly autodetected in linux (tested with chinese CH340G-based arduino)
- SMQB command support

Note that this code is compatible with original eggbot inkscape extension (tested with version 2.4.0), but only with disabled autoreset. Of course smooth movement will not be available.

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
