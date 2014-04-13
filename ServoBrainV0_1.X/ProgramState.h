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
    initialize,
    enterRun,
    run,
    pause,
    outputDebug,
};

enum ProgramState programState = startUp;

#endif	/* PROGRAMSTATE_H */

