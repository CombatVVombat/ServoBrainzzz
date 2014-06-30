
#include "p33EP512MU814.h"
#include "T1Interrupt.h"
#include "T2Interrupt.h"
#include "string.h"
#include "HomeSwitch.h"
#include "Physics.h"
#include "ProgramState.h"
#include "PushButton.h"
#include "Motion.h"
#include "MotionDebug.h"
#include "Startup.h"
#include "VelocityHold.h"

////////////////////////////////////////////////////////////////////////////////
/////// THE AMAZING TODO FLOWER BOCKS //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//////  Home routine
//////  Tinker with AccelTable resolution
//////  Self-Learn
//////   

/// Configuration Bits ///
_FGS( GWRP_OFF & GSS_OFF & GSSK_OFF);
_FOSCSEL( IESO_OFF & FNOSC_FRCPLL );
_FOSC( POSCMD_NONE & OSCIOFNC_ON & IOL1WAY_OFF & FCKSM_CSDCMD);
_FWDT( WDTPOST_PS1 & WDTPRE_PR32 & PLLKEN_OFF & WINDIS_OFF & FWDTEN_OFF);
_FPOR( FPWRT_PWR1 & BOREN_OFF & ALTI2C1_ON & ALTI2C2_ON);
_FICD( ICS_PGD3 & RSTPRI_PF & JTAGEN_OFF);
_FAS( AWRP_OFF & APL_OFF & APLK_OFF );

ProgramState programState = PS_STARTUP;


int main(int argc, char** argv)
{
    while(1)    
    {
        switch(programState)
        {
            case PS_STARTUP:
            {
                Startup();
                SetupDebugBuffers();
                programState = PS_INITIALIZE;
                break;
            }
            case PS_INITIALIZE:
            {
                printf("Entering State: initialize.\n");
                ResetButton(&buttonA);
                ResetButton(&buttonB);
                AccelTableBuildDefault();
                programState = PS_ENTER_RUN;
                break;
            }
            case PS_ENTER_RUN:
            {
                printf("Entering State: enterRun.\n");
                EnablePWM();
                EnableT1Interrupt();
                printf("Entering State: run.\n");
                programState = PS_RUN;
                break;
            }
            case PS_RUN:
            {
                if(buttonB.timeDown > 10)
                {
                    ResetButton(&buttonB);
                    printf("Start Button Ack.\n");
                    programState = PS_HOMING;
                }
                if(T1IntOverBudget)
                    printf("T1OverBudget.\n");
                break;
            }
            case PS_HOMING:
            {
                programState = GoHome(&currentState, &targetState);
                break;
            }
            case PS_PAUSE:
            {
                printf("Entering State: pause.\n");
                DisableT1Interrupt();
                DisablePWM();
                while(buttonB.timeDown < 50)
                {
                    Nop();
                }
                programState = PS_ENTER_RUN;
                break;
            }
            case PS_OUTPUT_DEBUG:
            {
                printf("Entering State: outputDebug\n");
                DisableT1Interrupt();
                DisablePWM();
                printf("Push ButtonB to output...\n");

                while(buttonB.timeDown < 50)
                {
                    Nop();
                }
                OutputBuffer();

                programState = PS_INITIALIZE;
                break;
            }
        }
    }
    return 0;
}

