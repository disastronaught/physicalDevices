//this is the day 12 addition to the 4x4 keypad we added yesterday
//this sends the designated frequency to the buzzer we have wired onto 
//the breadboard. 
//I'm curious as to the actual frequency of the tones and whether it 
//reflects the Hertz of the numbers listed in the array. If that's the case, then 
//it'll be easy to make a literal tone generator from this and segway into
//the jammer project utilizing the ultrasonic transducer.
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

Keypad theKeypad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

const unsigned int TONES[ROWS][COLS] = {
  {31, 93, 147, 208},
  {247, 311, 370, 440},
  {523, 587, 698, 880},
  {1397, 2637, 3729, 0}
};

const byte BUZZER_PIN = 10;

void setup() 
{
  Serial.begin(9600);//seting up the serial monitor by loading the right baud rate
}

void loop(){
  char button_character = theKeypad.waitForKey();

unsigned int tone_frequency = 0;
for (byte i = 0; i < ROWS; i++){
  for (byte j = 0; j < COLS; j++){
    if (button_character == BUTTONS[i][j]){
      tone_frequency = TONES[i][j];
    }
  }
}

Serial.print("Key: ");
Serial.print(button_character);
Serial.print("   Freq: ");
Serial.println(tone_frequency);

if (tone_frequency > 0) {
  tone(BUZZER_PIN, tone_frequency);
}else {
  Serial.println("Stop tone");
  noTone(BUZZER_PIN);
}
}
