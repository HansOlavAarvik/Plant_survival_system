#ifndef DISTANCE_H    // Start of header guard
#define DISTANCE_H

#include <avr/io.h>

// Pin definitions - these are constants that get replaced by the preprocessor
#define TRIG 3
#define ECHO 2
#define OUT 0

// extern tells the compiler "these variables exist somewhere else"
extern float duration;
extern float distance;

// Function declaration - just tells compiler the function exists and its signature
float distance_calc();

#endif              // End of header guard