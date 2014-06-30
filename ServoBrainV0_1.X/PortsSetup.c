#include "PortsSetup.h"

void PortsSetup()
{
    AD1CON1bits.ADON=0;
    AD2CON1bits.ADON=0;

    TRISAbits.TRISA6=0; // debug output

    TRISEbits.TRISE3=0; // output for PWM
    TRISEbits.TRISE2=0; // output, direction A
    TRISKbits.TRISK1=0; // output, direction B
    TRISHbits.TRISH9=1; // input, pushbutton A
    TRISHbits.TRISH8=1; // input, pushbutton B
    TRISEbits.TRISE1=1; // input, home sensor
    ANSELEbits.ANSE1=0; // disable ADC on home sensor pin

    IOCON2bits.PENH = 1;    // as PWM port
    IOCON2bits.PENL = 0;    // as I/O
    IOCON2bits.PMOD = 1;    // independent PWM mode

    PPSUnLock;
    PPSInput(IN_FN_PPS_U1RX, IN_PIN_PPS_RP98);      // UART1 from Max3232->Pic
    PPSOutput(OUT_FN_PPS_U1TX, OUT_PIN_PPS_RP104);  // UART1 from Pic->Max3232

    PPSInput(IN_FN_PPS_QEA1, IN_PIN_PPS_RP125);      // QEI1 A
    PPSInput(IN_FN_PPS_QEB1, IN_PIN_PPS_RPI124);     // QEI1 B
    PPSInput(IN_FN_PPS_QEI1, IN_PIN_PPS_RP126);      // QEI1 Index
    PPSLock;
}
