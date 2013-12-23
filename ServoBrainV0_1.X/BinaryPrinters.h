/* 
 * File:   BinaryPrinters.h
 * Author: JRK
 *
 * Created on June 11, 2013, 5:31 PM
 */

#ifndef BINARYPRINTERS_H
#define	BINARYPRINTERS_H

#include "UARTSetup.h"

// Prints in format acceptable to MakerPlot
// % Byte Byte Byte Byte /r

void PrintLU(const unsigned long var)
{
    char var1 = (char)var;
    //char var2 = (char)(var>>8);
    //char var3 = (char)(var>>16);
    //char var4 = (char)(var>>24);
    //char checksum = var1+var2+var3+var4;

    //putch(var4);
    //putch(var3);
    //putch(var2);
    putch(var1);
    //putch(checksum);
}



#endif	/* BINARYPRINTERS_H */

