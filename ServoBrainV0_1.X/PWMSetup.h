/* 
 * File:   PWMSetup.h
 * Author: JRK
 *
 * Created on April 23, 2013, 6:26 PM
 */

#ifndef PWMSETUP_H
#define	PWMSETUP_H

#include "p33EP512MU814.h"
#include "stdio.h"

#define PWM_PERIOD 4096
#define directionA LATEbits.LATE2
#define directionB LATKbits.LATK1

void PWMSetup();
void SetPowerOpenLoop(signed char Percent);

#endif	/* PWMSETUP_H */

