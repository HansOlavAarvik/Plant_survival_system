#include <avr/io.h>

float duration, distance;

// pins
int trig = 3;
int echo = 2;
int out = 0;

float distance_calc(){
  PORTD &= ~(1 << trig);// Make sure Trig is low for 2 microseconds
  delayMicroseconds(2);
  PORTD |= (1 << trig);// Send a 10-microsecond HIGH pulse to the Trig pin (trig)
  delayMicroseconds(10);
  PORTD &= ~(1 << trig);  // Set Trig low after pulse
  duration = pulseIn(out, HIGH);
  distance = duration * 0.0343 / 2;  // Calculate distance in cm
  return distance;
}