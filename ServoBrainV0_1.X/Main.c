
#include "p33EP512MU814.h"
#include "string.h"
#include "Startup.h"
#include "Physics.h"
#include "ProgramState.h"
#include "PushButton.h"
#include "Motion.h"
#include "MotionDebug.h"
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

int32_t elapsedFrame;
char T1IntOverBudget;
State currentState;
State targetState;
PushButton buttonA;
PushButton buttonB;
SerialBuffer UART1Buffer;

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
    IFS0bits.T1IF = 0;
    T1IntOverBudget = 1;
    
    currentState.s = readPosition();
    currentState.v = readVelocity();     // Only do this once per dt

    GotoState(&currentState, &targetState);

    if(debugIndex < DEBUG_BUF_SIZE)
    {
        debugPosBuf[debugIndex] = currentState.s;
        debugVelBuf[debugIndex] = currentState.v;
        debugIndex++;
    }
    elapsedFrame++;
    T1IntOverBudget = 0;
}

void __attribute__((__interrupt__,no_auto_psv)) _T2Interrupt(void)
{
    IFS0bits.T2IF = 0;
    UpdateButton(BUTTON_A_PORT, &buttonA);
    UpdateButton(BUTTON_B_PORT, &buttonB);
}

int main(int argc, char** argv)
{
    while(1)
    {
        switch(programState)
        {
            case startUp:
            {
                Startup();
                programState = initialize;
                break;
            }
            case initialize:
            {
                printf("Entering State: initialize.\n");
                ResetButton(&buttonA);
                ResetButton(&buttonB);
                AccelTableBuildDefault();

                programState = enterRun;
                break;
            }
            case enterRun:
            {
                printf("Entering State: enterRun.\n");
                EnablePWM();
                EnableT1Interrupt();
                printf("Entering State: run.\n");
                programState = run;
                break;
            }
            case run:
            {
                if(buttonA.timeDown > 10)
                {
                    targetState.s = -131072;
                    programState = enterRun;
                    printf("Start Button Ack.\n");
                }
                if(buttonB.timeDown > 10)
                {
                    targetState.s = 131072;
                    programState = enterRun;
                    printf("Start Button Ack.\n");
                }
                if(T1IntOverBudget)
                {
                    printf("T1IntOverBudget.\n");
                    programState = pause;
                }
                break;
            }
            case pause:
            {
                printf("Entering State: pause.\n");
                DisableT1Interrupt();
                DisablePWM();
                while(buttonB.timeDown < 50)
                {
                    Nop();
                }
                programState = enterRun;
                break;
            }
            case outputDebug:
            {
                printf("Entering State: outputDebug\n");
                DisableT1Interrupt();
                DisablePWM();

                //OutputBuffer();

                programState = initialize;
                break;
            }
        }
    }
    return 0;
}

