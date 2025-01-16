#include <avr/io.h>
#include "distance.h"
#include "mtr.h"

float distance_reading;

void setup() {
    Serial.begin(9600);
    
    DDRD |= (1 << TRIG);
    DDRD &= ~(1 << ECHO);
    DDRB &= ~(1 << OUT);
    DDRB |= (1<< SERV);
    DDRA &= ~(1 << POT);
}

void loop() {
    servo_control(open)
    
    
    
}

// Distancel calcu
//distance_reading = distance_calc();
// Serial.print("Distance: ");
// Serial.print(distance_reading);
// Serial.println(" cm");
//delay(500);