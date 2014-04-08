#include "Motion.h"

void CalcProfile(VelocityProfile *velocityProfile, const State *current, const State *target)
{
    static State a, t;
    a.s = current->s;
    a.v = current->v;
    t.s = target->s;
    t.v = target->v;

    int16_t iterationCount = 0;

    if(a.v > t.v)
    {
        while( (a.v > t.v) && (iterationCount < QtyProfilePoints) )
        {
            velocityProfile->dataPoint[iterationCount].time = DT*8*(int32_t)iterationCount;
            velocityProfile->dataPoint[iterationCount].v = a.v;
            integrate(&a, accelFuncNegative, DT*8);
            iterationCount++;
        }
    }
    else
    {
        while( (a.v < t.v) && (iterationCount < QtyProfilePoints) )
        {
            velocityProfile->dataPoint[iterationCount].time = DT*8*(int32_t)iterationCount;
            velocityProfile->dataPoint[iterationCount].v = a.v;
            integrate(&a, accelFuncPositive, DT*8);
            iterationCount++;
        }
    }

    velocityProfile->endPosition = a.s;

    /*printf("VelocityProfile Debug\n");
    for(int i = 0; i < QtyProfilePoints; i++)
    {
        printf("t: "); PrintQ16B16(velocityProfile->dataPoint[i].time); printf("  v: "); PrintQ16B16(velocityProfile->dataPoint[i].v); printf("\n");
        
    }
    printf("final-position: "); PrintQ16B16(velocityProfile->endPosition); printf("\n");*/
}


