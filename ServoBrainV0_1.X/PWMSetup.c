#include "PWMSetup.h"

void PWMSetup()
{
    PTCONbits.PTEN = 0;     // Disable PWM before changing PTCON values
    PTCONbits.SYNCEN = 0;
    PTCONbits.SYNCOEN = 1;  // Sync to primary time base
    PTCONbits.SYNCPOL = 0;
    PTCONbits.EIPU = 0;
    PTCONbits.SEIEN = 0;
    PTCONbits.PTSIDL = 1;
    PTCON2bits.PCLKDIV = 0; // Divide timebase by 1
    PWMCON2bits.MDCS = 0;   // Duty Cycle by PDC2 register
    PWMCON2bits.ITB = 0;    // Period by PTPER register
    PWMCON2bits.IUE = 0;    // Immediate Updates
    PWMCON2bits.XPRES = 0;  // External pins do not effect PWM time base
    PWMCON2bits.CAM = 0;    // Edge Aligned
    PWMCON2bits.MTBS = 0;   // Use Primary time base
    PWMCON2bits.DTC = 2;    // Dead Time Disabled
    PTPER = PWM_PERIOD;     // PWM Period
    PDC2 = 0;               // Initial Duty Cycle

    PTCONbits.PTEN = 1;
    POS1CNTL = 0;
    POS1CNTH = 0;
}

void SetPowerOpenLoop(signed char Percent)
{
    if(Percent>0)
    {
        directionA = 1;
        directionB = 0;
    }
    else
    {
        directionA = 0;
        directionB = 1;
        Percent *= -1;
    }
    
    PDC2 = (unsigned int)((PWM_PERIOD * (unsigned long)Percent) / 100);
}