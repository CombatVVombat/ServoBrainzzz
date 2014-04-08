#include "PushButton.h"

void UpdateButton(const unsigned portToCheck, PushButton* pushButton)
{
    if(!portToCheck)
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
    pushButton->state = portToCheck;

    //printf("timeUp: "); printf("%uli", pushButton->timeUp); printf("\n");
    //printf("timeDown: "); printf("%uli,", pushButton->timeDown); printf("\n");
}

void ResetButton(PushButton* pushButton)
{
    pushButton->state = 0;
    pushButton->lastState = 0;
    pushButton->timeUp = 0;
    pushButton->timeDown = 0;
}
