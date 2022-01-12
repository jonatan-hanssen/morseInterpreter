# Arduino Morse Interpreter

This project is for a simple program for an Arduino Uno. It
consists only of a button and a small LCD-screen along with the
Arduino. Inputs from the button will be read and interpreted as
morse code, which will be displayed on the LCD-screen.

## Setup
- Connect a Hitachi HD44780 compatible LCD display to the Arduino
Uno as described [here](https://docs.arduino.cc/learn/electronics/lcd-displays)
- Connect a NO-button to 5V and ground with a 10k Ohm pulldown resistor
between the button and ground.
- Connect pin 7 to the node between the resistor and the button.

