#include "distance.h"    // Include our own header first
#include <Arduino.h>     // For Arduino-specific functions like delayMicroseconds

// Actually create the variables that were declared with extern
float duration;
float distance;

// The actual implementation of our function
float distance_calc() {
    PORTD &= ~(1 << TRIG);
    delayMicroseconds(2);
    
    PORTD |= (1 << TRIG);
    delayMicroseconds(10);
    PORTD &= ~(1 << TRIG);
    
    duration = pulseIn(ECHO, HIGH);
    distance = duration * 0.0343 / 2;
    
    return distance;
}