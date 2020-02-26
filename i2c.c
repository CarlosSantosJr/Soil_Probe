#include <xc.h>
#include "i2c.h"

void I2C_Iniatialize(short address) {
    ANSEL           = 0b00000000;               //All digital inputs
    TRISA           = 0b11111000;               //porta   
    PORTA           = 0b00000000;
    PIR1            = 0x00;
    PIE1            = 0x00;
    INTCON          = 0x00;             //Disable all interrupts
    TRISB           = 0b00010010;       //RB1 = SDA + RB4 = SCL - as inputs
    PORTB           = 0b00000000;
    SSPCON          = 0b00110110;       //(SSPEN)SDA+SCL are serial port source pins ; Enable clock ; I2C mode 7-bits address ; Start stoP interrupts disabled    
    PIR1bits.SSPIF  = 0;                //Clear the serial port interrupt flag
    PIE1bits.SSPIE  = 1;                //enable Synchronious Serial Port interrupts
    SSPADD          = address;
}
