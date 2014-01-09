#include "PortsSetup.h"

void PortsSetup()
{
    AD1CON1bits.ADON=0;
    AD2CON1bits.ADON=0;


    
    TRISAbits.TRISA6=0; // debug output



    TRISEbits.TRISE3=0; // output for PWM
    TRISEbits.TRISE2=0; // output, direction A
    TRISKbits.TRISK1=0; // output, direction B
    TRISHbits.TRISH9=1; // pushbutton A
    TRISHbits.TRISH8=1; // pushbutton B

    IOCON2bits.PENH = 1;    // as PWM port
    IOCON2bits.PENL = 0;    // as I/O
    IOCON2bits.PMOD = 1;    // independent PWM mode

    RPINR18bits.U1RXR = IN_PIN_PPS_RP98;    // UART1 from Max3232->Pic
    OUT_PIN_PPS_RP104 = OUT_FN_PPS_U1TX;    // UART1 from Pic->Max3232

    RPINR14bits.QEA1R = IN_PIN_PPS_RP125;      // QEI1 A
    RPINR14bits.QEB1R = IN_PIN_PPS_RP124;      // QEI1 B
    RPINR17bits.INDX2R = IN_PIN_PPS_RP126;     // QEI1 Index
}
