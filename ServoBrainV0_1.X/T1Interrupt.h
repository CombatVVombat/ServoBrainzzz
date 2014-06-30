/* 
 * File:   T1Interrupt.h
 * Author: JRK
 *
 * Created on June 29, 2014, 8:47 PM
 */

#ifndef T1INTERRUPT_H
#define	T1INTERRUPT_H

#include "p33EP512MU814.h"
#include "Motion.h"
#include "MotionDebug.h"

extern char T1IntOverBudget;

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void);

#endif	/* T1INTERRUPT_H */

