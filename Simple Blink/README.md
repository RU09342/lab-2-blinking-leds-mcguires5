# Simple Blink
Code was written to make the led light on the boards blink at a constant rate. In every block of code the wastchdog timer is disabled. The code works by controlling registers which are used to store the output value for the pin. The direction of the pin must be set to ouput so this register is loaded with a 1. Setting a bit is done by or'ing the bit with one ``P1DIR |= 0x01``. An infinate loop is then initiated and inside a delay is added and the led is toggled on and off. The led is toggled on and off by xor'ing the register. ``P1OUT ^= 0x01``


## The following projects were created:
* Lab2SimpleBlinkF5529
* Lab2SimpleBlinkFR2311
* Lab2SimpleBlinkFR5994
* Lab2SimpleBlinkG2553
* Lab2SimpleBlinkFR6989

### Lab2SimpleBlinkF5529
Pin 1 bit 0 is used to control the led on the board.

### Lab2SimpleBlinkFR2311
Pin 1 bit 0 is used to control the led on the board.

### Lab2SimpleBlinkFR5994
Pin 1 bit 0 is used to control the led on the board.

### Lab2SimpleBlinkFR6989
Pin 1 bit 0 is used to control the led on the board.

### Lab2SimpleBlinkG2553
Pin 1 bit 0 is used to control the led on the board.
