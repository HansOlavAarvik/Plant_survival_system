#include <avr/io.h>
#include "distance.h"
#include "mtr.h"
#include <Arduino.h>

float distance_reading;
//unsigned long delay_time = 20000;

void setup() {
    Serial.begin(9600);
    
    DDRD |= (1 << TRIG);
    DDRD &= ~(1 << ECHO);
    DDRB &= ~(1 << OUT);
    DDRB |= (1<< MOT1);
    DDRB |= (1<< MOT2);
    DDRC &= ~(1 << POT);
}

// At the top, change the delay time variable:
unsigned long delay_time = 2000;  // 2 seconds in milliseconds

void loop() {
    motor_control("stop");
    delay(delay_time);           // Use delay instead of delayMicroseconds
    motor_control("open");
    delay(delay_time);
    motor_control("stop");
    delay(delay_time);
    motor_control("close");
    delay(delay_time);
}

// Distancel calcu
//distance_reading = distance_calc();
// Serial.print("Distance: ");
// Serial.print(distance_reading);
// Serial.println(" cm");
//delay(500);