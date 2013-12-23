
#include "p33EP512MU814.h"
#include "string.h"
#include "Startup.h"
#include "Physics.h"
#include "ProgramState.h"
#include "VelocityTest.h"
#include "Motion.h"
#include "AccelTable.h"

/// Configuration Bits ///
_FGS( GWRP_OFF & GSS_OFF & GSSK_OFF);
_FOSCSEL( IESO_OFF & FNOSC_FRCPLL );
_FOSC( POSCMD_NONE & OSCIOFNC_ON & IOL1WAY_OFF & FCKSM_CSDCMD);
_FWDT( WDTPOST_PS1 & WDTPRE_PR32 & PLLKEN_OFF & WINDIS_OFF & FWDTEN_OFF);
_FPOR( FPWRT_PWR1 & BOREN_OFF & ALTI2C1_ON & ALTI2C2_ON);
_FICD( ICS_PGD3 & RSTPRI_PF & JTAGEN_OFF);
_FAS( AWRP_OFF & APL_OFF & APLK_OFF );

#define pushButtonA !PORTHbits.RH9
#define pushButtonB !PORTHbits.RH8

unsigned long elapsedTime;
struct SerialBuffer UART1Buffer;
signed long SpeedPercent=0;
unsigned long looper=0;
unsigned long testCounter=0;



void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
    IFS0bits.T1IF = 0;
    elapsedTime++;

    currentState.s = readPosition();
    currentState.v = readVelocity();     // Only do this once per dt

    if(programState == test)
    {
        testCounter++;
        if(testCounter>512)
        {
            printf("%li", looper);
            looper++;
            testCounter = 0;
        }
    }
}

int main(int argc, char** argv)
{
    while(1)
    {
        if( compareLastChar(&UART1Buffer, "v") )
        {
            clearBuffer(&UART1Buffer);
            programState = velocityTest;
        }
        if( compareLastChar(&UART1Buffer, "a") )
        {
            clearBuffer(&UART1Buffer);
            SpeedPercent+=5;
            SetPowerOpenLoop(SpeedPercent);
            printf("SpeedPercent: ");
            printf("%li", SpeedPercent);
            printf("\n");
            programState = fixedTimeInterrupt;  
        }
        if( compareLastChar(&UART1Buffer, "z") )
        {
            clearBuffer(&UART1Buffer);
            SpeedPercent-=5;
            SetPowerOpenLoop(SpeedPercent);
            printf("SpeedPercent: ");
            printf("%li", SpeedPercent);
            printf("\n");
            programState = fixedTimeInterrupt;
        }
        if( compareLastChar(&UART1Buffer, "q") )
        {
            clearBuffer(&UART1Buffer);
            SpeedPercent=0;
            SetPowerOpenLoop(SpeedPercent);
            printf("SpeedPercent: ");
            printf("%li", SpeedPercent);
            printf("\n");
            programState = fixedTimeInterrupt;
        }
        if( compareLastChar(&UART1Buffer, "t") )
        {
            clearBuffer(&UART1Buffer);
        }
        
        if(programState == startUp)
        {
            Startup();
            AccelTableBuildDefault(&accelTable);
            //programState = fixedTimeInterrupt;
            programState = test;
        }

        if(programState == fixedTimeInterrupt)
        {
            IEC0bits.T1IE = 1;  // Enable Interrupt
            receiveSerial(&UART1Buffer);
        }

        if(programState == velocityTest)
        {
            IEC0bits.T1IE = 0;  // Disable Interrupt
            VelocityTest();
            programState = fixedTimeInterrupt;
        }
    }
    return 0;
}

