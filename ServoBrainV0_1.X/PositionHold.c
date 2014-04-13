#include "PositionHold.h"

PIDParams PHoldPID = { .P=700, .I=24, .D=2, .IaccumMax=1000000 };

void PositionHold(const State *current, const State *target)
{
    PHoldPID.error = (target->s - current->s);
    PHoldPID.Pvalue = (PHoldPID.error * PHoldPID.P);
    PHoldPID.Iaccum += (PHoldPID.error * PHoldPID.I);
    PHoldPID.Dvalue = (current->v * -PHoldPID.D);

    if(PHoldPID.Iaccum > PHoldPID.IaccumMax)
        PHoldPID.Iaccum = PHoldPID.IaccumMax;
    if(PHoldPID.Iaccum < -PHoldPID.IaccumMax)
        PHoldPID.Iaccum = -PHoldPID.IaccumMax;

    int32_t command = ((PHoldPID.Pvalue + PHoldPID.Iaccum + PHoldPID.Dvalue)>>8);
    if(command > 32767)
        command = 32767;
    if(command < -32767)
        command = -32767;
    command = (int16_t)command;

    debugCtrlBuf[debugIndex] = command;
    debugCommandBuf[debugIndex] = target->s;
    debugModeBuf[debugIndex] = 'P';

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