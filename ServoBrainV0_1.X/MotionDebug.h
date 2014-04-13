/* 
 * File:   MotionDebug.h
 * Author: JRK
 *
 * Created on April 9, 2014, 6:12 PM
 */

#ifndef MOTIONDEBUG_H
#define	MOTIONDEBUG_H

#include "stdint.h"
#include "stdio.h"

#define DEBUG_BUF_SIZE 512

// Output array for debugging motion
extern uint16_t debugIndex;
__attribute__((far)) extern int32_t debugPosBuf[DEBUG_BUF_SIZE];
__attribute__((far)) extern int16_t debugVelBuf[DEBUG_BUF_SIZE];
__attribute__((far)) extern int16_t debugCtrlBuf[DEBUG_BUF_SIZE];
__attribute__((far)) extern int32_t debugCommandBuf[DEBUG_BUF_SIZE];
__attribute__((far)) extern char    debugModeBuf[DEBUG_BUF_SIZE];

void OutputBuffer();

#endif	/* MOTIONDEBUG_H */

