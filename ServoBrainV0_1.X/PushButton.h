/* 
 * File:   PushButton.h
 * Author: JRK
 *
 * Created on April 2, 2014, 8:16 PM
 */

#ifndef PUSHBUTTON_H
#define	PUSHBUTTON_H

#include "stdint.h"
#include "stdio.h"

typedef struct PushButton
{
    uint8_t state:1;
    uint8_t lastState:1;
    uint16_t timeDown;
    uint16_t timeUp;

} PushButton;

void UpdateButton(const unsigned portToCheck, PushButton* pushButton);
void ResetButton(PushButton* pushButton);


#endif	/* PUSHBUTTON_H */

