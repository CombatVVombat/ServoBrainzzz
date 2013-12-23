#include "Startup.h"
#include "BinaryPrinters.h"

void Startup()
{
    OscillatorSetup();
    InterruptSetup();
    PortsSetup();
    UARTSetup();
    Encoder1Setup();
    PWMSetup();

    T1CONbits.TON = 1;                  // Timer ON
    T2CONbits.TON = 1;                  // Timer2/3 ON
    IEC0bits.T1IE = 1;                  // Enable
    printf("Welcome -- ServoBrain V0.1\n\n");
}
