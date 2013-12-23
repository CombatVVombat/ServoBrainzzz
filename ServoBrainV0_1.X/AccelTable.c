#include "AccelTable.h"

void AccelTableBuildDefault(struct AccelTable *accelTable)
{
    // Build a table of values for acceleration as a function of velocity.  The table spans from -VRANGE/2 to +VRANGE/2
    // The values are spaced by VRANGE / QTY_ENTRIES
    for(signed int i = 0; i < QTY_ENTRIES; i++)
    {
        //AccelNegative = kt*w/wmax + kt
        signed long w = (i-(QTY_ENTRIES/2))*STEP;
        if((w > Wmax) || (w < -Wmax))
        {
            accelTable->Positive[i] = 0;
            accelTable->Negative[i] = 0;
        }
        else
        {
            accelTable->Positive[i] =    ((((-Kt*w)<<8)/Wmax) + (Kt<<8));      // Scaled up by 2^8
            accelTable->Negative[i] = -1*(((( Kt*w)<<8)/Wmax) + (Kt<<8));       // Scaled up by 2^8
        }
    }
}

void DebugAccelTable(const struct AccelTable *const accelTable)
{
    printf("DebugAccelTable\n");
    for(signed int i = 0; i < QTY_ENTRIES; i++)
    {
        signed long w = (i-(QTY_ENTRIES/2))*STEP;
        printf("%ld", w);  printf(",");
        printf("%ld", accelTable->Negative[i]);  printf(",");
        printf("%ld", accelTable->Positive[i]);  printf("\n");
    }
}
