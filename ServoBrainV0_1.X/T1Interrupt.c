#include "T1Interrupt.h"

char T1IntOverBudget = 0;
static MotionMode motionMode = MM_VELOCITYHOLD;
static int16_t command = 0;

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
    T1IntOverBudget = 1;

    currentState.s = readPosition();    // Update from encoder
    currentState.v = readVelocity();    // Only do this once per dt

    motionMode = SelectControlMode(&currentState, &targetState);

    switch(motionMode)
    {
        case MM_VELOCITYHOLD:
            command = VelocityHold(currentState.v, GetVelTarget(&currentState, &targetState));
            debug8[0].buffer[debugIndex] = 'V';
            break;
        case MM_POSITIONHOLD:
            command = PositionHold(&currentState, &targetState);
            debug8[0].buffer[debugIndex] = 'P';
            break;
    }
    CommandMotor(command);

    if(debugIndex < DEBUG_BUF_SIZE)
    {
        debug32[0].buffer[debugIndex] = currentState.s;
        debug32[1].buffer[debugIndex] = targetState.s;
        debug16[0].buffer[debugIndex] = currentState.v;
        debug16[1].buffer[debugIndex] = targetState.v;
        debug16[2].buffer[debugIndex] = command;
        debugIndex++;
    }
    else
    {
        // loop around
        debugIndex = 0;
    }
    T1IntOverBudget = 0;
    IFS0bits.T1IF = 0;
}
