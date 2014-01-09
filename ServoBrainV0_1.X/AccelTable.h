/* 
 * File:   AccelTable.h
 * Author: JRK
 *
 * Created on April 26, 2013, 6:51 PM
 */

#ifndef ACCELTABLE_H
#define	ACCELTABLE_H

#include "stdint.h"
#include "stdio.h"
#include "Physics.h"
#include "BinaryPrinters.h"

#define QTY_ENTRIES 64

typedef enum { Positive, Negative } AccelDirection;

typedef struct AccelTable
{
    int32_t Velocity[QTY_ENTRIES];
    int32_t Negative[QTY_ENTRIES];
    int32_t Positive[QTY_ENTRIES];
} AccelTable;


void AccelTableBuildDefault();
void DebugAccelTable();
int32_t GetPositiveAccel(const State *state);
int32_t GetNegativeAccel(const State *state);

extern int32_t (*accelFuncPositive)(const State* state);
extern int32_t (*accelFuncNegative)(const State* state);




#endif	/* ACCELTABLE_H */

