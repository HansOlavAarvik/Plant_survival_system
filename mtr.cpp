#include "mtr.h"  
#include <Arduino.h>



void pot_read(){
    pot_val = anaoglRead(POT);
    serial.monitor(pot_val);
}