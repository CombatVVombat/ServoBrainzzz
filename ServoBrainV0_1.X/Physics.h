#ifndef PHYSICS_H
#define	PHYSICS_H

#include "p33EP512MU814.h"
#include "stdint.h"

#define DT ((uint16_t)(65536 * 0.01024f))             // seconds, Q<0,16>

typedef struct State
{
    int64_t s;          // position as 64bits  Using Q<48,16>
    int32_t v;          // velocity as 32bits  Using Q<16,16>
} State;

int32_t readPosition();
int32_t readVelocity();
void integrate(State *initial, int32_t (*accelFunc)(const State *state), const int16_t dt);

#endif	/* PHYSICS_H */

