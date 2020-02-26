#include "system.h"
#include "tmr0.h"

void init_timer0(void) {
    INTCONbits.TMR0IE = 1;      // Habilita interrupção do TMR0;
    OPTION_REG = 0b10000001;    // Modo Temporizador, prescaler 1:4;
}

void start_timer0(short time) {
    TMR0 = 0xFF - time;
}