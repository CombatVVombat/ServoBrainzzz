#include "Physics.h"

int32_t readPosition()
{
    ///// Position Returned as Q<24,8>  /////
    // First read the position from the encoder.  This is in Q<32,0> since the encoder cannot give fractioanl counts.
    int32_t position;
    position = POS1CNTL;
    position += ((int32_t)(POS1CNTH)) << 16;
    
    // Convert to Q<24,8>
    position = (position << 8);
    return position;
}

int16_t readVelocity()
{
    int16_t velocity = (int16_t)VEL1CNT;    // it's actually signed.  Fuck the header file.
    ///// Velocity Returned as Q<13,3> //////
    return velocity;
}

void integrate(State *initial, int32_t (*accelFunc)(const State *state), const uint16_t dt)
{
    // state.s stored as Q<24,8>
    // state.v stored as Q<13,3>
    static State b;     // must be static to prevent possible need of 32bit pointer
    b.s = initial->s;
    b.v = initial->v;

    b.v += (int32_t)(( (int64_t)accelFunc(&b) * dt) >> 16);
    b.s += (( (int64_t)b.v * dt) >> 16);
    
    initial->s = b.s;
    initial->v = b.v;
}