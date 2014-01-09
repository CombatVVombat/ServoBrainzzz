#include "AccelTable.h"

static const int16_t QtyEntries = QTY_ENTRIES;
static int32_t Step;
static int32_t VRange;
static int32_t Kt;
static int32_t Wmax;

static AccelTable accelTable;

int32_t (*accelFuncPositive)(const State* state) = &GetPositiveAccel;
int32_t (*accelFuncNegative)(const State* state) = &GetNegativeAccel;

void AccelTableBuildDefault()
{
    // Build a table of values for acceleration as a function of velocity.
    // The table values span between -VRange to +VRange
    // The units of VRange are (encoder counts per dt) shifted to Q<16,16>
    // Kt is torque constant
    // Wmax is the maximum

    VRange = (8192L << 16);              // Q<16,16>
    Step = (2*VRange)/QtyEntries;        // Q<16,16>
    Kt = (int32_t)(1500.0f*65536);        // Q<16,16>
    Wmax = (4096L << 16);                // Q<16,16>

    // Build a table of values for acceleration as a function of velocity.  The table spans from -VRANGE to +VRANGE
    // The values are spaced by VRANGE / QTY_ENTRIES
    for(signed int i = 0; i < QtyEntries; i++)
    {
        //AccelNegative = kt*w/wmax + kt
        int32_t w = (i-(QtyEntries/2))*Step;    // w = Q<16,16>
        if((w > Wmax) || (w < -Wmax))
        {
            accelTable.Velocity[i] = 0;
            accelTable.Positive[i] = 0;
            accelTable.Negative[i] = 0;
        }
        else
        {
            accelTable.Velocity[i] = w;                                         // Q<16,16>
            accelTable.Positive[i] =    (( (int32_t)( ((int64_t)-Kt*(int64_t)w) / Wmax)) + Kt );    // Q<16,16>
            accelTable.Negative[i] = -1*(( (int32_t)( ((int64_t)Kt*(int64_t)w)  / Wmax)) + Kt );    // Q<16,16>
        }
    }
}

void DebugAccelTable()
{
    printf("DebugAccelTable\n");
    for(signed int i = 0; i < QtyEntries; i++)
    {
        printf("%-5u", i);
        PrintQ16B16(accelTable.Velocity[i]);
        PrintQ16B16(accelTable.Negative[i]);
        PrintQ16B16(accelTable.Positive[i]);  printf("\n");
    }
}

int32_t GetPositiveAccel(const State *state)
{
    int16_t i = 0;
    int16_t x = 0;
    int32_t accel = 0;
    int32_t v = (state->v);

    if(v < -VRange)
    {
        i = 0;
        return accel;
    }
    else if(v > VRange)
    {
        i = (QtyEntries-1);
        return accel;
    }
    else
    {
        i = ((v/Step) + (QtyEntries/2));
        // Find "x", a percent of distance that w is between w(i) and w(i+1)

        int32_t a = (v - accelTable.Velocity[i]);                               // Q<16,16>
        int32_t b = (accelTable.Velocity[i+1] - accelTable.Velocity[i]);        // Q<16,16>
        int32_t c = 0;
        x = (a/b);                                                              
        
        c = (accelTable.Positive[i+1] - accelTable.Positive[i]);                // Q<16,16>
        accel = ((c*x)>>8);                                                     // Q<16,16> * Q<0,8> = Q<16,24> >> 8 = Q<16,16>
        accel += accelTable.Positive[i];                                        // Q<16,16>
        accel = accel;                                                          // Q<16,16>
    }
        //printf("Velocity: ");  PrintQ16B16(v);  printf("\n");
        //printf("x: ");  printf("%u", x);  printf("\n");
        //printf("Index: ");  printf("%u", i);  printf("\n");
        //printf("AccelValue: ");  PrintQ16B16(accel); printf("\n");
        //printf("\n");
    return accel;
}

int32_t GetNegativeAccel(const State *state)
{
    int16_t i = 0;
    int16_t x = 0;
    int32_t accel = 0;
    int32_t v = state->v;  

    if(v < -VRange)
    {
        i = 0;
        return accel;
    }
    else if(v > VRange)
    {
        i = (QtyEntries-1);
        return accel;
    }
    else
    {
        i = ((v/Step) + (QtyEntries/2));
        // Find "x", a percent of distance that w is between w(i) and w(i+1)

        int32_t a = (v - accelTable.Velocity[i]);                     
        int32_t b = (accelTable.Velocity[i+1] - accelTable.Velocity[i]);  
        int32_t c = 0;
        x = (a/b);

        c = (accelTable.Negative[i+1] - accelTable.Negative[i]);          
        accel = ((c*x)>>8);
        accel += accelTable.Negative[i];                              
        accel = accel;      
    }
        //printf("Velocity: ");  PrintQ16B16(v);  printf("\n");
        //printf("x: ");  printf("%u", x);  printf("\n");
        //printf("Index: ");  printf("%u", i);  printf("\n");
        //printf("AccelValue: ");  PrintQ16B16(accel); printf("\n");
        //printf("\n");
    return accel;
}