
#include "p33EP512MU814.h"
#include "string.h"
#include "Startup.h"
#include "Physics.h"
#include "ProgramState.h"
#include "Motion.h"
#include "VelocityHold.h"


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

uint64_t elapsedFrame;
State currentState;
State targetState;
VelocityProfile velocityProfile;
SerialBuffer UART1Buffer;


void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
    IFS0bits.T1IF = 0;
    elapsedFrame ++;

    currentState.s = readPosition();
    currentState.v = readVelocity();     // Only do this once per dt

    if(elapsedFrame > 128)
    {
        targetState.v *= -1;
        elapsedFrame=0;
    }
    VelocityHold(targetState.v, currentState.v);
}

int main(int argc, char** argv)
{
    Startup();
    AccelTableBuildDefault();

    targetState.v = 2048;

    //CalcProfile(&velocityProfile, &currentState, &targetState);

    EnableInterrupt();
    

   
    
    while(1)
    {

    }
    return 0;
}

