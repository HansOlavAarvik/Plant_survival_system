#include "mtr.h"  
#include <Arduino.h>
#include<avr/io.h>
#include <string.h>


void motor_control(const char *configuration) {
    if (strcmp(configuration, "stop") == 0) {
        PORTB &= ~(1 << MOT1);
        PORTB &= ~(1 << MOT2);
        Serial.println("stop");
    }
    else if (strcmp(configuration, "open") == 0) {
        PORTB |= (1 << MOT1);
        PORTB &= ~(1 << MOT2);
        Serial.println("open");
    }
    else if (strcmp(configuration, "close") == 0) {
        PORTB &= ~(1 << MOT1);
        PORTB |= (1 << MOT2);
        Serial.println("close");
    }
    else return;
} 

void pot_read(){
    pot_val = analogRead(POT);
    Serial.println(pot_val);
}
