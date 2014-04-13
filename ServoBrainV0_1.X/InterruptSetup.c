#include "InterruptSetup.h"

void InterruptSetup()
{
    /////// T1 & T1 Interrupt //////////////////////////////////////////////////
    T1CONbits.TCKPS = 1;                // Prescaler 1:8
    T1CONbits.TCS = 0;                  // Clock Source: Internal Clock (Fosc/2)
    T1CONbits.TGATE = 0;                // Disable Gated Timer
    TMR1 = 0;                           // Clear timer register
    PR1 = 11059;                        // 1.28ms

    IPC0bits.T1IP = 7;                  // Interrupt Priority (7 = Highest)
    IFS0bits.T1IF = 0;                  // Clear Interrupt Flag
    IEC0bits.T1IE = 0;                  // Interrupt from Timer 1 Starts OFF

    
    ////// T2 & T2 Interrupt ///////////////////////////////////////////////////
    T2CONbits.TCKPS = 2;                // Prescaler 1:64
    T2CONbits.T32 = 0;                  // 32bit mode disabled
    T2CONbits.TCS = 0;                  // Internal Clock Selected  (Timer is Fosc/2)
    T2CONbits.TGATE = 0;                // Disable Gated Timer
    T2CONbits.TSIDL = 0;                // Continue when idle
    TMR2 = 0;                           // Clear timer register
    PR2 = 55295;                        // ~50ms

    IPC1bits.T2IP = 6;                  // Lower Priority than Timer 1 Interrupt
    IFS0bits.T2IF = 0;                  // Clear Interrupt Flag
    IEC0bits.T2IE = 0;                  // Interrupt from Timer2 Starts OFF
}

void EnableT1Interrupt()
{
    IEC0bits.T1IE = 1;
}

void DisableT1Interrupt()
{
    IEC0bits.T1IE = 0;
}

void EnableT2Interrupt()
{
    IEC0bits.T2IE = 1;
}

void DisableT2Interrupt()
{
    IEC0bits.T2IE = 0;
}