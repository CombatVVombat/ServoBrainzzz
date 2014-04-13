#include "MotionDebug.h"

uint16_t debugIndex = 0;
__attribute__((far)) int32_t debugPosBuf[DEBUG_BUF_SIZE];
__attribute__((far)) int16_t debugVelBuf[DEBUG_BUF_SIZE];
__attribute__((far)) int16_t debugCtrlBuf[DEBUG_BUF_SIZE];
__attribute__((far)) int32_t debugCommandBuf[DEBUG_BUF_SIZE];
__attribute__((far)) char    debugModeBuf[DEBUG_BUF_SIZE];

void OutputBuffer()
{
    printf("Outputting Debug Buffer...\n");
    printf("Index,"); printf("Pos,"); printf("Vel,"); printf("Ctrl"); printf("\n");

    for(unsigned int i = 0; i < DEBUG_BUF_SIZE; i++)
    {
        printf("%u", i); printf(",");
        printf("%li", debugPosBuf[i]); printf(",");
        printf("%i", debugVelBuf[i]); printf(",");
        printf("%i", debugCtrlBuf[i]); printf(",");
        printf("%ld", debugCommandBuf[i]); printf(",");
        printf("%c", debugModeBuf[i]); printf("\n");
    }
}