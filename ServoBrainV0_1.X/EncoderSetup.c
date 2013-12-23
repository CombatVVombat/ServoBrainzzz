#include "EncoderSetup.h"

void Encoder1Setup()
{
    ///////////// SETUP QEI1 //////////////////////////////////////////////////////////
    QEI1IOCbits.FLTREN = 1;     // Filter Enable
    QEI1IOCbits.QFDIV = 0;      // 1:1 Clock Divide?
    QEI1CONbits.PIMOD = 0;      // Index has no effect on count
    QEI1CONbits.CCM = 0;        // Quadrature Mode
    QEI1CONbits.QEIEN = 1;
}
