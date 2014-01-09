/* 
 * File:   Motion.h
 * Author: JRK
 *
 * Created on May 6, 2013, 7:16 PM
 */

#ifndef MOTION_H
#define	MOTION_H

#include "stdint.h"
#include "Physics.h"
#include "AccelTable.h"
#include "PWMSetup.h"
#include "BinaryPrinters.h"

extern struct State currentState;

#define QtyProfilePoints 64

typedef struct VelocityProfilePoint
{
    int32_t time;
    int32_t v;
} VelocityProfilePoint;

typedef struct VelocityProfile
{
    VelocityProfilePoint dataPoint[QtyProfilePoints];
    int64_t endPosition;
} VelocityProfile;

void CalcProfile(VelocityProfile *velocityProfile, const State *current, const State *target);


#endif	/* MOTION_H */

