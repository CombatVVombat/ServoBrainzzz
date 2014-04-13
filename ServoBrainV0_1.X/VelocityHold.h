#ifndef VELOCITYHOLD_H
#define	VELOCITYHOLD_H

#include "stdint.h"
#include "PIDParams.h"
#include "PWMSetup.h"
#include "MotionDebug.h"

extern PIDParams VHoldPID;       // PID VALUES in Q<8,8>

void VelocityHold(int16_t vCurrent, int16_t vTarget);






#endif	/* VELOCITYHOLD_H */

