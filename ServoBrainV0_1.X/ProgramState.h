/* 
 * File:   ProgramState.h
 * Author: JRK
 *
 * Created on April 23, 2013, 7:15 PM
 */

#ifndef PROGRAMSTATE_H
#define	PROGRAMSTATE_H

typedef enum ProgramState
{
    PS_STARTUP,
    PS_INITIALIZE,
    PS_ENTER_RUN,
    PS_RUN,
    PS_PAUSE,
    PS_OUTPUT_DEBUG,
    PS_HOMING
} ProgramState;

#endif	/* PROGRAMSTATE_H */

