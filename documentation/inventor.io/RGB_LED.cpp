//This is my first time working with RGB LEDs
//I didn't really know what to make of the physical component at first
//It just looked like a typical LED with 4 leads instead of two.
//I could tell it wasn't a transistor because it had an epoxy cap and the same inner structure as other LEDS.

#include "Arduino.h"


 
const byte RED_PIN = 11;    
const byte GREEN_PIN = 10;  
const byte BLUE_PIN = 9;    

const byte OFF = 0;                 
const byte DIM = 64;                
const byte BRIGHT = DIM + 64;     
const byte BRIGHTER = BRIGHT + 64;  
const byte BRIGHTEST = 255;         


const unsigned int COLOR_DELAY = 500;  

void setup() {

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}


void loop() {
  
  displayColor(OFF, OFF, OFF); 
  delay(COLOR_DELAY);
  displayColor(DIM, OFF, OFF);  
  delay(COLOR_DELAY);
  displayColor(BRIGHT, OFF, OFF); 
  delay(COLOR_DELAY);
  displayColor(BRIGHTER, OFF, OFF); 
  delay(COLOR_DELAY);
  displayColor(BRIGHTEST, OFF, OFF);  
  delay(COLOR_DELAY);

  
  displayColor(OFF, BRIGHT, OFF);  
  delay(COLOR_DELAY);
  displayColor(OFF, OFF, BRIGHT);  
  delay(COLOR_DELAY);

  
  displayColor(BRIGHT, BRIGHT, OFF);  
  delay(COLOR_DELAY);
  displayColor(OFF, BRIGHT, BRIGHT);  
  delay(COLOR_DELAY);
  displayColor(BRIGHT, OFF, BRIGHT); 
  delay(COLOR_DELAY);

  
  displayColor(BRIGHT, BRIGHT, BRIGHT);  
  delay(COLOR_DELAY);
}


void displayColor(
  byte red_intensity,    
  byte green_intensity,  
  byte blue_intensity    
) 
{
  analogWrite(RED_PIN, red_intensity);      
  analogWrite(GREEN_PIN, green_intensity); 
  analogWrite(BLUE_PIN, blue_intensity);    
}
