#ifndef MTR_H
#define MTR_H
#include <avr/io.h>

#define  POT 0

extern float pot_val;
extern bool valve_open;

void pot_read();

#endif