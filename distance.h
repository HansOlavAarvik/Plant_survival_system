// distance.h
#ifndef DISTANCE_H
#define DISTANCE_H

#include <avr/io.h>

// Pin definitions
#define TRIG 3
#define ECHO 2
#define OUT 0

// Variables
static float duration, distance;

// Function implementation directly in header
static float distance_calc() {
    PORTD &= ~(1 << TRIG);  // Make sure Trig is low for 2 microseconds
    delayMicroseconds(2);
    
    PORTD |= (1 << TRIG);   // Send a 10-microsecond HIGH pulse to the Trig pin
    delayMicroseconds(10);
    PORTD &= ~(1 << TRIG);  // Set Trig low after pulse
    
    duration = pulseIn(ECHO, HIGH);
    distance = duration * 0.0343 / 2;  // Calculate distance in cm
    
    return distance;
}

#endif