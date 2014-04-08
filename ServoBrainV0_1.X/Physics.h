#ifndef PHYSICS_H
#define	PHYSICS_H

#include "p33EP512MU814.h"
#include "stdint.h"

#define DT ((uint16_t)(671))   // seconds, Q<0,16>
                               // 2^16 * time in seconds
                               // Example: 65536 * (0.01024) = 671.09

typedef struct State
{
    int32_t s;          // Position as 32bits  Using Q<24,8>
                        // Maximum +/-2048 Shaft Turns.  Approx +/-157 inch with 1/13th screw pitch
    int16_t v;          // velocity as 16bits  Using Q<13,3>
                        // +/-4096 counts/frame.  5860RPM @ 10.24ms frames
} State;

int32_t readPosition();
int16_t readVelocity();
void integrate(State *initial, int32_t (*accelFunc)(const State *state), const uint16_t dt);

#endif	/* PHYSICS_H */

