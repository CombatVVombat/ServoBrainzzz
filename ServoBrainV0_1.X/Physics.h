/* 
 * File:   Physics.h
 * Author: JRK
 *
 * Created on April 23, 2013, 6:38 PM
 */

#ifndef PHYSICS_H
#define	PHYSICS_H

#include "p33EP512MU814.h"

struct State
{
    signed long s;
    signed long v;
};

signed long readPosition();
signed long readVelocity();

#endif	/* PHYSICS_H */

