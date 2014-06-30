/* 
 * File:   UARTSetup.h
 * Author: JRK
 *
 * Created on April 23, 2013, 6:23 PM
 */

#ifndef UARTSETUP_H
#define	UARTSETUP_H

#include "stdio.h"
#include "p33EP512MU814.h"

#define bufferSize 64

typedef struct SerialBuffer
{
    unsigned char index;
    char buffer[bufferSize];
} SerialBuffer;

extern SerialBuffer UART1Buffer;

void UARTSetup();
void putch(unsigned char byte);
void receiveSerial(struct SerialBuffer *SB);
void clearBuffer(struct SerialBuffer *SB);
char compareLastChar(const struct SerialBuffer *const SB, const char* c);

#endif	/* UARTSETUP_H */

