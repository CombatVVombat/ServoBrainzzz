#include "VelocityTest.h"

void VelocityTest()
{
    directionA = 1;
    directionB = 0;
    PDC2 = 5000;
    __delay32(50000000);

    unsigned long velCounter = VEL1CNT;
    velCounter = 0;
    for(unsigned short i = 0; i < 128; i++)
    {
        while(!IFS0bits.T1IF) { __delay32(1); }     // wait until timer overflows
        velCounter += VEL1CNT;
        IFS0bits.T1IF = 0;
    }
    PDC2 = 0;
    unsigned long velMax = velCounter / 128;
    printf("%s", "VelMax: ");
    printf("%i", velMax);
    printf("\n");

    __delay32(50000000);
}
