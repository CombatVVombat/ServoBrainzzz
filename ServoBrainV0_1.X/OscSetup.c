#include "OscSetup.h"

void OscillatorSetup()
{
    CLKDIVbits.FRCDIV = 0;              // Clock divided by 1
    CLKDIVbits.PLLPRE = 0;              // Divide by 2
    CLKDIVbits.PLLPOST =0;              // Divide by 2
    PLLFBD=73;                          // PPL multiplier
                                        // Totals ~75.54 MHZ
    while(OSCCONbits.COSC != 0b001);    // Wait for new Oscillator to become FRC w/ PLL
    while(OSCCONbits.LOCK != 1);        // Wait for Pll to Lock
}
