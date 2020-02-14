#include "interrupt_manager.h"

short dado;

void __interrupt() INTERRUPT_InterruptManager(void) {
    if (PIR1bits.SSPIF) { // I2C INTERRUPT
        if (!SSPSTATbits.R_nW) { // Master wants to WRITE (R_nW = 0)
            if (SSPSTATbits.D_nA) {
                dado = SSPBUF;
            } else {
                SSPBUF;
            }
        } else { // Master wants to READ (R_nW = 1)
            SSPBUF;
            SSPBUF = dado;
            SSPCONbits.CKP = 1;
        }
        PIR1bits.SSPIF = 0;
    }
}