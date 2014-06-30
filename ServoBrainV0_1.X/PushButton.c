#include "PushButton.h"

void UpdateButton(const volatile unsigned int port, PushButton* pushButton)
{
    if(!port)
    {
        pushButton->timeUp=0;
        pushButton->timeDown++;
    }
    else
    {
        pushButton->timeDown=0;
        pushButton->timeUp++;
    }

    pushButton->lastState = pushButton->state;
    pushButton->state = port;
}

void ResetButton(PushButton* pushButton)
{
    DisableT2Interrupt();   // Prevent concurrent writing to button by main and interrupt
    pushButton->state = 0;
    pushButton->lastState = 0;
    pushButton->timeUp = 0;
    pushButton->timeDown = 0;
    EnableT2Interrupt();
}
