#include "MotionDebug.h"

uint16_t debugIndex = 0;
__attribute__((far)) DebugChannel32 debug32[CHANNELS32];
__attribute__((far)) DebugChannel16 debug16[CHANNELS16];
__attribute__((far)) DebugChannel8 debug8[CHANNELS8];

void SetupDebugBuffers()
{
    for(unsigned int x = 0; x < CHANNELS32; ++x)
    {
        strcpy(debug32[x].name, "default");
    }
    for(unsigned int y = 0; y < CHANNELS16; ++y)
    {
        strcpy(debug16[y].name, "default");
    }
    for(unsigned int z = 0; z < CHANNELS8; ++z)
    {
        strcpy(debug8[z].name, "default");
    }

    ////////////////////////////////////////////////////////////////////
    ////// make sure the channels actually exist in MotionDebug.h //////
    ///// names cannot be longer than 15 characters ////////////////////
    strcpy(debug32[0].name, "c-pos");
    strcpy(debug32[1].name, "t-pos");
    strcpy(debug16[0].name, "c-vel");
    strcpy(debug16[1].name, "t-vel");
    strcpy(debug16[2].name, "cmnd");
    strcpy(debug8[0].name, "mode");
}

void OutputBuffer()
{
    printf("Outputting Debug Buffer...\n");
    // Print channel names
    printf("i,");
    for(unsigned int x = 0; x < CHANNELS32; ++x)
    {
        printf(debug32[x].name); printf(",");
    }
    for(unsigned int y = 0; y < CHANNELS16; ++y)
    {
        printf(debug16[y].name); printf(",");
    }
    for(unsigned int w = 0; w < CHANNELS8; ++w)
    {
        printf(debug8[w].name); printf("\n");
    }

    for(unsigned int i = 0; i < DEBUG_BUF_SIZE; ++i)
    {
        printf("%u", i); printf(",");
        for(unsigned int j = 0; j < CHANNELS32; ++j)
        {
            printf("%li", debug32[j].buffer[i]); printf(",");
        }
        for(unsigned int k = 0; k < CHANNELS16; ++k)
        {
            printf("%i", debug16[k].buffer[i]); printf(",");
        }
        for(unsigned int z = 0; z < CHANNELS8; ++z)
        {
            printf("%c", debug8[z].buffer[i]); printf("\n");
        }
    }
}