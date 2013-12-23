/* 
 * File:   Motion.h
 * Author: JRK
 *
 * Created on May 6, 2013, 7:16 PM
 */

#ifndef MOTION_H
#define	MOTION_H

#include "Physics.h"
#include "AccelTable.h"
#include "PWMSetup.h"

extern struct AccelTable accelTable;

extern struct State currentState;   // currentstate
extern struct State targetState;    // final state to get to
extern struct State goal;           // intermediate state to path towards the target

signed long MoveAbsolute(const struct State *const current, const struct State *const target);    // try to approach the target at maximum acceleration.  Predict the distance required.
signed long AccelDistance(const struct State *const current, const struct State *const target);


#endif	/* MOTION_H */

