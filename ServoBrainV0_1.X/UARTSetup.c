#include "UARTSetup.h"

void UARTSetup()
{
    U1MODEbits.BRGH = 1;
    U1BRG = 74;             // 230400
    U1MODEbits.PDSEL = 0;   // 8bits, No Parity
    U1MODEbits.STSEL = 0;   // 1 Stop bit
    U1MODEbits.URXINV = 0;  // Receive Polarity Invert
    U1MODEbits.ABAUD = 0;   // AutoBaud OFF
    U1MODEbits.LPBACK = 0;  // Loopback disabled
    U1MODEbits.WAKE = 0;    // Wake-up disabled

    U1STAbits.UTXINV = 0;   // Transmit Polarity Invert
    U1STAbits.ADDEN = 0;    // Address Mode disabled

    U1MODEbits.UARTEN = 1;  // Enable UART1
    U1STAbits.UTXEN = 1;    // Transmit Enabled
}

void putch(unsigned char byte)
{
    while(!U1STAbits.TRMT);
    U1TXREG = byte;
}

void clearBuffer(SerialBuffer *SB)
{
    for(int i = 0; i < bufferSize; i++)
    {
        SB->buffer[i] = 0;
    }
    SB->index = 0;
}

void receiveSerial(SerialBuffer *SB)
{
    if(U1STAbits.OERR)  // Check Overrun
        printf("Serial Buffer Overrun\n");
    if(U1STAbits.FERR)
        printf("Framing Error\n");
    if(U1STAbits.PERR)
        printf("Parity Error\n");
    if(U1STAbits.URXDA)
    {
        if(SB->index < (bufferSize-1))               // Check buffer is not full
        {
            SB->index++;
            SB->buffer[SB->index]= U1RXREG;         // Take character from RX line into buffer
            printf("%c", SB->buffer[SB->index]);    // Echo to console
        }
        else
        {
            clearBuffer(SB);
        }
    }
}

char compareLastChar(const SerialBuffer *const SB, const char* c)
{
    if(SB->buffer[SB->index] == *c)
        return 1;
    else
        return 0;
}