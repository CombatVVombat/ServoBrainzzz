#include "T2Interrupt.h"

PushButton buttonA;
PushButton buttonB;

void __attribute__((__interrupt__,no_auto_psv)) _T2Interrupt(void)
{
    UpdateButton(BUTTON_A_PORT, &buttonA);
    UpdateButton(BUTTON_B_PORT, &buttonB);
    IFS0bits.T2IF = 0;
}
