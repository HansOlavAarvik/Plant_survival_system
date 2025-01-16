#include "mtr.h"  
#include <Arduino.h>
#include <Servo.h>
#include<avr/io.h>

Servo Servo1;

servo_control(configuration){
    for (i = 0; i < 10; i++) {
        PORTB |=(1<<SERV);
        delayMicroseconds(configuragtion);
        PORTB &= ~(1<<SERV);
        delayMicroseconds(configuration);
    }    
}



void pot_read(){
    pot_val = anaoglRead(POT);
    serial.monitor(pot_val);
}
