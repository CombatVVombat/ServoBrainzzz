/* 
 * File:   Motion.h
 * Author: JRK
 *
 * Created on May 6, 2013, 7:16 PM
 */

#ifndef MOTION_H
#define	MOTION_H

#include "stdint.h"
#include "abs.h"
#include "Physics.h"
#include "AccelTable.h"
#include "PositionHold.h"
#include "VelocityHold.h"

#define VMax 850

int16_t GetVelTarget(const State *current, const State *target);
void GotoState(const State *current, const State *target);


#endif	/* MOTION_H */

