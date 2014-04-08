
#include "p33EP512MU814.h"
#include "string.h"
#include "Startup.h"
#include "Physics.h"
#include "ProgramState.h"
#include "PushButton.h"
#include "Motion.h"
#include "VelocityHold.h"

////////////////////////////////////////////////////////////////////////////////
/////// THE AMAZING TODO FLOWER BOCKS //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////// Change velocity representations to 16bit and position to 32bit //////////
/////   In VelocityHold
/////   AccelTable???
/////   Motion: CalcProfile
/////   Physics?                Done?  Maybe.
/////

/// Configuration Bits ///
_FGS( GWRP_OFF & GSS_OFF & GSSK_OFF);
_FOSCSEL( IESO_OFF & FNOSC_FRCPLL );
_FOSC( POSCMD_NONE & OSCIOFNC_ON & IOL1WAY_OFF & FCKSM_CSDCMD);
_FWDT( WDTPOST_PS1 & WDTPRE_PR32 & PLLKEN_OFF & WINDIS_OFF & FWDTEN_OFF);
_FPOR( FPWRT_PWR1 & BOREN_OFF & ALTI2C1_ON & ALTI2C2_ON);
_FICD( ICS_PGD3 & RSTPRI_PF & JTAGEN_OFF);
_FAS( AWRP_OFF & APL_OFF & APLK_OFF );

uint64_t elapsedFrame;
State currentState;
State targetState;
PushButton buttonA;
PushButton buttonB;
VelocityProfile velocityProfile;
SerialBuffer UART1Buffer;

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
    IFS0bits.T1IF = 0;
    elapsedFrame ++;

    currentState.s = readPosition();
    currentState.v = readVelocity();     // Only do this once per dt

    if(elapsedFrame == 160)
    {
        targetState.v *= -1;
    }
    VelocityHold(targetState.v, currentState.v);
}

int main(int argc, char** argv)
{
    while(1)
    {
        Startup();
        elapsedFrame=0;
        ResetButton(&buttonA);
        ResetButton(&buttonB);
        AccelTableBuildDefault();

        targetState.v = 3200;

        while(buttonA.timeDown < 1024)   // button not down
        {
            UpdateButton(BUTTON_A_PORT, &buttonA);
        }

        EnablePWM();
        EnableInterrupt();

        while(elapsedFrame < 300)
        {

        }
    }
    return 0;
}

