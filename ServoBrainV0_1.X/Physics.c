#include "Physics.h"

signed long readPosition()
{
    signed long position;
    position = POS1CNTL;
    position += ((signed long)(POS1CNTH)) << 16;
    return position;
}

signed long readVelocity()
{
    signed long velocity = VEL1CNT;
    return velocity;
}