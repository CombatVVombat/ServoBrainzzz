#include "VelocityHold.h"

PIDParams VHoldPID = { .P=9000, .I=64, .D=0, .IaccumMax=1000000 };

void VelocityHold(int16_t vCurrent, int16_t vTarget)
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

    debugCtrlBuf[debugIndex] = command;
    debugCommandBuf[debugIndex] = vTarget;
    debugModeBuf[debugIndex] = 'V';

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