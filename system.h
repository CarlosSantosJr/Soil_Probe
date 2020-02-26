#ifndef SYSTEM_H
#define	SYSTEM_H

#include "i2c.h"
#include "tmr0.h"
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <pic16f88.h>

void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);

#endif	/* SYSTEM_H */

