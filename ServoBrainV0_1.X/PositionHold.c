#include "PositionHold.h"

PIDParams PHoldPID = { .P=300, .I=12, .D=4, .IaccumMax=1000000 };

int16_t PositionHold(const State *current, const State *target)
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

    return command;
}