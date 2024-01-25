//This is a flash for the Arduino UNO from the Space adventure kit from inventr.io
//they had a strange non-carriage returned placement of curly braces so I added those
//I also reversed the switch pins because my bradboard holder is 180 from their wiring diagram.
#include "Arduino.h"

#define CABIN_LIGHTS_PJN 12
#define CABIN_LIGHTS_SWITCH_PIN 2

void setup() {
  pinMode(CABIN_LIGHTS_PIN, OUTPUT);
  pinMode(CABIN_LIGHTS_SWITCH_PIN, INPUT);
}

void loop(){
  if (digitalRead(CABIN_LIGHTS_SWITCH_PIN) == HIGH){
    digitalWrite(CABIN_LIGHTS_SWITCH_PIN, HIGH);
  }
  else {
    digitalWrite(CABIN_LIGHTS_PIN, LOW)
  }
}
