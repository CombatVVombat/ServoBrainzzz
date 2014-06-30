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
#include "string.h"

#define DEBUG_BUF_SIZE 1024
#define CHANNELS32 2
#define CHANNELS16 3
#define CHANNELS8 1

typedef struct DebugChannel32
{
    char name[16];
    int32_t buffer[DEBUG_BUF_SIZE];
} DebugChannel32;

typedef struct DebugChannel16
{
    char name[16];
    int16_t buffer[DEBUG_BUF_SIZE];
} DebugChannel16;

typedef struct DebugChannel8
{
    char name[16];
    int8_t buffer[DEBUG_BUF_SIZE];
} DebugChannel8;


// Output array for debugging motion
extern uint16_t debugIndex;

__attribute__((far)) extern DebugChannel32 debug32[CHANNELS32];
__attribute__((far)) extern DebugChannel16 debug16[CHANNELS16];
__attribute__((far)) extern DebugChannel8 debug8[CHANNELS8];

void SetupDebugBuffers();
void OutputBuffer();

#endif	/* MOTIONDEBUG_H */

