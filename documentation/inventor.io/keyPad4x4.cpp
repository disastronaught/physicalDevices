//having 16 buttons on a microcomputer is incredibly helpful
//this allows us to theoretically access as many peripherals (not likely due to I/O limits) it'd look kinda funny to have 
//a microcontroller chip long enough to account for 16 inputs
//My plans for this specific script is to tune the ultrasonic transducer as a jammer on 16 different wavelengths
//That's an easy project because we can take in the libraries used on channel analyzers and code in
//loop statements where transmissions are make on specific channels at different gains

#include "Arduino.h"
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

const byte ROW_PINS[ROWS] = {5, 4, 3, 2 };
const byte COL_PINS[COLS] = {6, 7, 8, 9 };

const char BUTTONS[ROWS][COLS] = {
  { '1', '2', '3', 'A'}, //row 0
  { '4', '5', '6', 'B'},
  { '7', '8', '9', 'C'},
  { '*', '0', '#', 'D'}  //row 3
};

Keypad heroKeypad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

void setup() 
{
  Serial.begin(9600);//seting up the serial monitor by loading the right baud rate
}

void loop(){
  char pressedButton = heroKeypad.waitForKey();
  Serial.println(pressedButton);
}
