/* 
 * File:   AccelTable.h
 * Author: JRK
 *
 * Created on April 26, 2013, 6:51 PM
 */

#ifndef ACCELTABLE_H
#define	ACCELTABLE_H

#include "stdio.h"

#define VRANGE 4096
#define QTY_ENTRIES 128
#define STEP (VRANGE / QTY_ENTRIES)
#define Kt 16
#define Wmax 512

struct AccelTable
{
signed long Negative[QTY_ENTRIES];
signed long Positive[QTY_ENTRIES];
};

void AccelTableBuildDefault(struct AccelTable *accelTable);
void DebugAccelTable(const struct AccelTable *const accelTable);




#endif	/* ACCELTABLE_H */

