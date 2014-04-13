#ifndef PHYSICS_H
#define	PHYSICS_H

#include "p33EP512MU814.h"
#include "stdint.h"

//#define DT ((uint16_t)(671))   // seconds, Q<0,16>
                               // 2^16 * time in seconds
                               // Example: 65536 * (0.01024) = 671.09

typedef struct State
{
    int32_t s;                         
    int16_t v;          
                        
} State;

int32_t readPosition();
int16_t readVelocity();
void integrate(State *initial, int16_t (*accelFunc)(const State *state), const int16_t dt);

#endif	/* PHYSICS_H */

