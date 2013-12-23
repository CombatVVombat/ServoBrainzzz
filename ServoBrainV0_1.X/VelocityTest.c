#include "VelocityTest.h"

void VelocityTest()
{
    printf("%s", "Running Maximum Velocity Test...\n");
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
    signed int velMax = velCounter / 128;
    __delay32(500000);

    directionA = 0;
    directionB = 1;
    PDC2 = 5000;
    __delay32(50000000);

    velCounter = VEL1CNT;
    velCounter = 0;
    for(unsigned short i = 0; i < 128; i++)
    {
        while(!IFS0bits.T1IF) { __delay32(1); }
        velCounter += VEL1CNT;
        IFS0bits.T1IF = 0;
    }
    PDC2 = 0;
    signed int velMin = velCounter / 128;

    printf("%s", "Velocity Max: ");  printf("%i", velMax);  printf("%s", " counts per sampling period.\n");
    printf("\n");
    printf("%s", "Velocity Min: ");  printf("%i", velMin);  printf("%s", " counts per sampling period.\n");
    printf("\nCompleted.\n");
}
