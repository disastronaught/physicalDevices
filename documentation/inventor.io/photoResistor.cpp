#include "Arduino.h"

const byte PHOTORESISTOR_PIN = A0;
const unasigned int MIN_DELAY = 50;
const unasigned int MAX_DELAY = 500;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PHOTORESISTOR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  unasigned int light_value = analogRead(PHOTORESISTOR_PIN);
  Serial.print("Light value: ");
  Serial.print(light_value);

  static unasigned int darkest_light = light_value;
  static unasigned int brightest_light = light_value;

  if (light_value < darkest_light) {
    darkest_light = light_value;
  }
  if (light_value > brightest_light) {
    brightest_light = light_value;
  }

  unasigned int delay_value = map(light_value, darkest_light, brightest_light, MAX_DELAY, MIN_DELAY);
  Serial.print(", Delay value: ");
  Serial.println(delay_value);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(delay_value);
  digitalWrite(LED_BUILTIN, LOW);
  delay(delay_value);
}
