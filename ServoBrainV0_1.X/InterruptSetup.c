#include "InterruptSetup.h"

void InterruptSetup()
{
    T1CONbits.TCKPS = 2;                // Prescaler 1:64
    T1CONbits.TCS = 0;                  // Clock Source: Internal Clock (Fosc/2)
    T1CONbits.TGATE = 0;                // Disable Gated Timer
    TMR1 = 0;                           // Clear timer register
    PR1 = 11059;                        // 10.24ms

    IPC0bits.T1IP = 7;                  // Interrupt Priority (7 = Highest)
    IFS0bits.T1IF = 0;                  // Clear Interrupt Flag
    IEC0bits.T1IE = 0;                  // Interrupt from Timer 1 Starts OFF

    T2CONbits.TCKPS = 0;                // Prescaler 1:1
    T2CONbits.T32 = 1;                  // 32bit mode
    T2CONbits.TCS = 0;                  // Internal Clock Selected  (Timer is Fosc/2)
    T2CONbits.TGATE = 0;                // Disable Gated Timer
    T2CONbits.TSIDL = 0;                // Continue when idle
    IEC0bits.T3IE = 0;                  // Interrupt on 32bit T2/T3 pair disabled
    TMR3 = 0;                           // Clear MSW
    TMR2 = 0;                           // Clear LSW
    PR2 = 0xFFFF;                       // Maximum PR2:PR3
    PR3 = 0xFFFF;
}

unsigned long ReadT2T3Pair()
{
    unsigned int temp_lsb;
    unsigned int temp_msb;

    temp_lsb = TMR2;
    temp_msb = TMR3HLD;

    TMR2=0;
    TMR3=0;

    return (((unsigned long)temp_msb)<<16) + temp_lsb;
}

void EnableInterrupt()
{
    IEC0bits.T1IE = 1;
}

void DisableInterrupt()
{
    IEC0bits.T1IE = 0;
}