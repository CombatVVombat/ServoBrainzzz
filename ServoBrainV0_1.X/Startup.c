#include "Startup.h"
#include "BinaryPrinters.h"

void Startup()
{
    OscillatorSetup();
    InterruptSetup();
    DisableT1Interrupt();
    EnableT2Interrupt();
    PortsSetup();
    UARTSetup();
    Encoder1Setup();
    PWMSetup();

    T1CONbits.TON = 1;                  // Timer2 ON
    T2CONbits.TON = 1;                  // Timer2 ON
    printf("Welcome -- ServoBrain V0.1\n\n");
}
