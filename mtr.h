#ifndef MTR_H
#define MTR_H
#include <avr/io.h>

#define  POT 0
#define SERV 1

extern float pot_val;

 
void servo_control();
void pot_read();

#endif