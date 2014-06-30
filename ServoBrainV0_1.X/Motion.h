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

typedef enum MotionMode
{
    MM_VELOCITYHOLD,
    MM_POSITIONHOLD
} MotionMode;

extern State currentState;
extern State targetState;

void CommandMotor(const int16_t power);
MotionMode SelectControlMode();
int16_t GetVelTarget();



#endif	/* MOTION_H */

