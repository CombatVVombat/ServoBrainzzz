/* 
 * File:   ProgramState.h
 * Author: JRK
 *
 * Created on April 23, 2013, 7:15 PM
 */

#ifndef PROGRAMSTATE_H
#define	PROGRAMSTATE_H

enum ProgramState
{
    startUp,
    fixedTimeInterrupt,
    velocityTest,
    test
};

enum ProgramState programState = startUp;

#endif	/* PROGRAMSTATE_H */

