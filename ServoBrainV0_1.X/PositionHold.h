#ifndef POSITIONHOLD_H
#define	POSITIONHOLD_H

#include "stdint.h"
#include "Physics.h"
#include "PIDParams.h"
#include "PWMSetup.h"
#include "MotionDebug.h"

extern PIDParams PHoldPID;

int16_t PositionHold(const State *current, const State *target);








#endif	/* POSITIONHOLD_H */

