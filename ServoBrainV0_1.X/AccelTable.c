#include "AccelTable.h"

static const int16_t QtyEntries = QTY_ENTRIES;
static int16_t Step;
static int16_t VRange;
static int16_t KtMult;
static int16_t KtDiv;
static int16_t Wmax;

static AccelTable accelTable;

int16_t (*accelFuncPositive)(const State* state) = &GetPositiveAccel;
int16_t (*accelFuncNegative)(const State* state) = &GetNegativeAccel;

void AccelTableBuildDefault()
{
    // Build a table of values for acceleration as a function of velocity.
    // The table values span between -VRange to +VRange
    // The units of VRange are (encoder counts per dt)
    // Kt is torque constant
    // Wmax is the maximum

    VRange = 1024;
    Step = (2*VRange)/QtyEntries;        
    KtMult = 1;
    KtDiv = 50;
    Wmax = 800;

    // Build a table of values for acceleration as a function of velocity.  The table spans from -VRANGE to +VRANGE
    // The values are spaced by Step
    for(int i = 0; i < QtyEntries; i++)
    {
        //AccelNegative = kt*w/wmax + kt
        int16_t w = (i-(QtyEntries/2))*Step;
        if((w > Wmax) || (w < -Wmax))
        {
            accelTable.Velocity[i] = 0;
            accelTable.Positive[i] = 0;
            accelTable.Negative[i] = 0;
        }
        else
        {
            accelTable.Velocity[i] = w;                                         
            accelTable.Positive[i] = ((-KtMult*w)/KtDiv) + ((KtMult*Wmax)/KtDiv);
            accelTable.Negative[i] = -1*(((KtMult*w)/KtDiv) + ((KtMult*Wmax)/KtDiv));
        }
    }
}

void DebugAccelTable()
{
    printf("DebugAccelTable\n");
    for(unsigned int i = 0; i < QtyEntries; i++)
    {
        printf("%u", i);  printf(",");
        printf("%i", accelTable.Velocity[i]);  printf(",");
        printf("%i", accelTable.Positive[i]);  printf(",");
        printf("%i", accelTable.Negative[i]);  printf("\n");
    }
}

int16_t GetPositiveAccel(const State *state)
{
    int16_t v = state->v;
    int16_t i = 0;

    if((v < -VRange) || (v > VRange))
    {
        return 0;
    }
    else
    {
        i = ((v/Step) + (QtyEntries/2));
        return accelTable.Positive[i];
    }
}

int16_t GetNegativeAccel(const State *state)
{
    int16_t v = state->v;
    int16_t i = 0;

    if((v < -VRange) || (v > VRange))
    {
        return 0;
    }
    else
    {
        i = ((v/Step) + (QtyEntries/2));
        return accelTable.Negative[i];
    }
}