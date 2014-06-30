#include "HomeSwitch.h"

static HomeSwitch homeSwitch;

void ReadSwitch(volatile unsigned int port)
{
    homeSwitch.lastState = homeSwitch.state;
    homeSwitch.state = !port;
}

ProgramState GoHome(State *current, State *target)
{
    // If the home switch is covered, move off it.  (stage 0)
    // Move to the home switch                      (stage 1)
    // Move away from switch until index is found   (stage 2)

    printf("Entering State: homing.\n");
    DisableT1Interrupt();   // prevent concurrent write to states
    ReadSwitch(HOME_SWITCH_PORT);

    if(homeSwitch.state)   // switch is covered
    {
        if(homeSwitch.stage == 0)   // switch booted up already covered
        {
            target->s -= 25;    // move away
        }
        if(homeSwitch.stage == 1)   // switch made from "not covered" state
        {
            target->s = current->s;  // park for a moment
            homeSwitch.stage = 2;
            INDX1CNTL = 0;  // reset index count;
        }
    }
    else    // switch not covered
    {
        homeSwitch.stage = 1;   // move towards switch
        target->s += 20;
    }
    if(homeSwitch.stage == 2)   // sneak up on index
    {
        target->s += 1;
        if(INDX1CNTL > 0)
        {
            POS1CNTL = 0;
            POS1CNTH = 0;
            current->s = 0;
            target->s = 0;
            homeSwitch.stage = 3;
        }
    }
    if(homeSwitch.stage == 3)
    {
        printf("Entering State: run.\n");
        EnableT1Interrupt();
        homeSwitch.stage = 0;
        return PS_RUN;
    }
    EnableT1Interrupt();
    return PS_HOMING;
}