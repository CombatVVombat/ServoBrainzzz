#include "OscSetup.h"

void OscillatorSetup()
{
    CLKDIVbits.PLLPRE = 0;              // Divide by 2
    CLKDIVbits.FRCDIV = 0;              // Divide by 1
    CLKDIVbits.PLLPOST =0;              // Divide by 2
    PLLFBD=41;                          // PPL multiplier
                                        // Totals ~75.54 MHZ
    while(OSCCONbits.COSC != 0b001);    // Wait for new Oscillator to become FRC w/ PLL
    while(OSCCONbits.LOCK != 1);        // Wait for Pll to Lock
}
