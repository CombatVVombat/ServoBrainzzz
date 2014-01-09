#include "Physics.h"

int32_t readPosition()
{
    ///// Position Returned as Q<32,0> (The encoder cannot return fractional counts)
    int32_t position;
    position = POS1CNTL;
    position += ((int32_t)(POS1CNTH)) << 16;
    return position;
}

int32_t readVelocity()
{
    ///// Velocity Returned as Q<32,0> //////
    int32_t velocity = VEL1CNT;
    return velocity;
}

void integrate(State *initial, int32_t (*accelFunc)(const State *state), const int16_t dt)
{
    // state.s stored as Q<48,16>
    // state.v stored as Q<16,16>
    static State b;     // must be static to prevent possible need of 32bit pointer
    b.s = initial->s;
    b.v = initial->v;

    b.v += (int32_t)(( (int64_t)accelFunc(&b) * dt) >> 16);
    b.s += (( (int64_t)b.v * dt) >> 16);
    
    initial->s = b.s;
    initial->v = b.v;
}