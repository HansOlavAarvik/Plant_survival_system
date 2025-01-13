#include <avr/io.h>
#include "distance.h"
#include "mtr.h"

float distance_reading;

void setup() {
    Serial.begin(9600);
    
    DDRD |= (1 << TRIG);
    DDRD &= ~(1 << ECHO);
    DDRB &= ~(1 << OUT);
    DDRA &= ~(1 << POT);
}

void loop() {
    distance_reading = distance_calc();
    
    Serial.print("Distance: ");
    Serial.print(distance_reading);
    Serial.println(" cm");
    
    delay(500);
}