#include "Motion.h"

void GotoState(const State *current, const State *target)
{
    int32_t distanceToTarget = abval32(target->s - current->s);
    if(distanceToTarget > 64)
    {
        VelocityHold(current->v, GetVelTarget(current, target));
    }
    else
    {
        PositionHold(current, target);
    }
}

int16_t GetVelTarget(const State *current, const State *target)
{
    // If target position is relatively far away, compute a move to prevent major overshoot
        // Integate ending state backwards
        // 1) j's position goes past the current position
        //        Take the velocity at the position crossing
        //        If the position crossing happened quickly, switch to PID
        // 2) j's velocity exceeds the current velocity
        //        Now Integrate J and I together until their positions pass each other
    // If target position is relatively close, switch to position holding PID

    static State a, b, i, j;
    a.s = current->s;   // a = starting state
    a.v = current->v;
    b.s = target->s;    // b = ending state
    b.v = target->v;
    i.s = a.s;          // i = iterating from start
    i.v = a.v;
    j.s = b.s;          // j = iterating from end
    j.v = b.v;

    if(b.s > a.s)   // Target position is in the positive direction
    {
        ////////////////////////////////////////////////////////////////////////
        //////////////// Does part 1 for heading in positive direction /////////
        while(j.v < a.v)    // integrate j backwards in time until velocities match
        {
            integrate(&j, accelFuncNegative, -1);
            if(j.s < a.s)   // if the positions cross, escape early
            {
                return j.v;
            }
        }                               // loop falls through if no position crossing occured
                                        // continue below...
        ///////////// Does part 2 for heading in positive direction ////////////
        while(i.s < j.s)        // integrate the start and end states together until they cross
        {                       // trying to maintain velocities roughly together
            if(i.v < j.v)
                integrate(&i, accelFuncPositive, 1);
            else
                integrate(&j, accelFuncNegative, -1);

            if((j.v > VMax) || (i.v > VMax))        // or until one of them exceeds VMax
                return VMax;
        }
        return i.v;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    //////// Handles part 1 for negative direction /////////////////////////////
    else    // must go in negative direction
    {
        while(j.v > a.v)    // integrate j backwards until velocities match
        {
            integrate(&j, accelFuncPositive, -1);
            if(j.s > a.s)       // escape early if the positions cross
            {
                return j.v;
            }
        }                           // loop falls through if positions do not cross
                                    // continue below....

        //// handles part 2 for negative direction /////////////////////////////
        while(i.s > j.s)    // integrate start and end states together until they cross
        {
            if(i.v > j.v)
                integrate(&i, accelFuncNegative, 1);
            else
                integrate(&j, accelFuncPositive, -1);

            if((j.v < -VMax) || (i.v < -VMax))
                return -VMax;
        }
        return j.v;
    }
}


