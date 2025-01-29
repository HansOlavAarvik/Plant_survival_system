#ifndef MTR_H
#define MTR_H
#include <avr/io.h>
#include <Arduino.h>
#define  POT 0
#define MOT1 4
#define MOT2 5

extern float pot_val;
// kommentar
void motor_control(const char *configuration);
void pot_read();

#endif