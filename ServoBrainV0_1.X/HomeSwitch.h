/* 
 * File:   HomeSwitch.h
 * Author: JRK
 *
 * Created on June 15, 2014, 12:08 PM
 */

#ifndef HOMESWITCH_H
#define	HOMESWITCH_H

#include "stdint.h"
#include "stdio.h"
#include "p33EP512MU814.h"
#include "InterruptSetup.h"
#include "Motion.h"
#include "ProgramState.h"

#define HOME_SWITCH_PORT PORTEbits.RE1

typedef struct HomeSwitch
{
    uint8_t state:1;
    uint8_t lastState:1;
    uint8_t stage;

} HomeSwitch;

void ReadSwitch(volatile unsigned int port);
ProgramState GoHome(State *current, State *target);




#endif	/* HOMESWITCH_H */

