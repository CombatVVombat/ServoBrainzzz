/* 
 * File:   T2Interrupt.h
 * Author: JRK
 *
 * Created on June 29, 2014, 8:57 PM
 */

#ifndef T2INTERRUPT_H
#define	T2INTERRUPT_H

#include "p33EP512MU814.h"
#include "PushButton.h"

extern PushButton buttonA;
extern PushButton buttonB;

void __attribute__((__interrupt__,no_auto_psv)) _T2Interrupt(void);

#endif	/* T2INTERRUPT_H */

