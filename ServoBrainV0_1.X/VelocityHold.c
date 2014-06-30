#include "VelocityHold.h"

PIDParams VHoldPID = { .P=5000, .I=40, .D=0, .IaccumMax=1000000 };

int16_t VelocityHold(int16_t vCurrent, int16_t vTarget)
{
    // D is not implemented

    VHoldPID.error = (vTarget - vCurrent);                      
    VHoldPID.Pvalue = (VHoldPID.error * VHoldPID.P);            
    VHoldPID.Iaccum += (VHoldPID.error * VHoldPID.I);
    VHoldPID.Dvalue = 0;

    if(VHoldPID.Iaccum > VHoldPID.IaccumMax)
        VHoldPID.Iaccum = VHoldPID.IaccumMax;
    if(VHoldPID.Iaccum < -VHoldPID.IaccumMax)
        VHoldPID.Iaccum = -VHoldPID.IaccumMax;

    int32_t command = ((VHoldPID.Pvalue + VHoldPID.Iaccum + VHoldPID.Dvalue)>>8);
    if(command > 32767)
        command = 32767;
    if(command < -32767)
        command = -32767;
    command = (int16_t)command;

    return command;
}