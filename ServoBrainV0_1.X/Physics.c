#include "Physics.h"

int32_t readPosition()
{
    // First read the position from the encoder.  This is in Q<32,0> since the encoder cannot give fractioanl counts.
    int32_t position;
    position = POS1CNTL;
    position += ((int32_t)(POS1CNTH)) << 16;

    return position;
}

int16_t readVelocity()
{
    int16_t velocity = (int16_t)VEL1CNT;    // it's actually signed.  Fuck the header file.
    return velocity;
}

void integrate(State *initial, int16_t (*accelFunc)(const State *state), const int16_t dt)
{
    static State b;     // must be static to prevent possible need of 32bit pointer
    b.s = initial->s;
    b.v = initial->v;

    b.v += accelFunc(&b) * dt;
    b.s += b.v * dt;
    
    initial->s = b.s;
    initial->v = b.v;
}