#ifndef VELOCITYHOLD_H
#define	VELOCITYHOLD_H

#include "stdint.h"
#include "PIDParams.h"
#include "PWMSetup.h"
#include "BinaryPrinters.h"

extern PIDParams VHoldPID;       // PID VALUES in Q<8,8>

void VelocityHold(int32_t vTarget, int32_t vCurrent);






#endif	/* VELOCITYHOLD_H */

