#include <avr/io.h>
#include "distance.h"

float distance_reading;

void setup() {
  Serial.begin(9600);  
  // ulstrasonic
  DDRD |= (1 << trig);  // PD1 is output (Trig)
  DDRD &= ~(1 << echo); // PD2 is input (Echo)
  DDRB &= ~(1 << out);
}

void loop() {
  distance_reading = distance_calc();
  Serial.print("Distance: ");
  Serial.print(distance_reading);
  Serial.println(" cm");
  delay(500);
}