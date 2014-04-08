#include "VelocityHold.h"

PIDParams VHoldPID = { .P=700, .I=128, .D=0};

void VelocityHold(int32_t vTarget, int32_t vCurrent)
{
    VHoldPID.error = (vTarget - vCurrent);                      //Q<16,0>
    VHoldPID.Pvalue = (VHoldPID.error * VHoldPID.P);            //Q<16,0>*Q<8,8> = Q<24,8>
    VHoldPID.Iaccum += (VHoldPID.error * VHoldPID.I);
    VHoldPID.Dvalue = 0;

    int16_t command = ((VHoldPID.Pvalue + VHoldPID.Iaccum + VHoldPID.Dvalue)>>8);

    //printf("%li", vCurrent); printf("  ");
    //printf("%li", VHoldPID.error); printf("\n");

    if(command >= 0)
    {
        // clockwise, viewed from encoder side
        directionA = 1;
        directionB = 0;
    }
    else
    {
        directionA = 0;
        directionB = 1;
        command *= -1;
    }
    PDC2 = command;
}