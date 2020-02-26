//#include "system.h"

#include "system.h"

void main(void){
    OSCILLATOR_Initialize();
    I2C_Iniatialize(0xE0);
    SYSTEM_Initialize();
    while (1);
}