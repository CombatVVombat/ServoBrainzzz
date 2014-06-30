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
#include "InterruptSetup.h"

#define BUTTON_A_PORT PORTHbits.RH9
#define BUTTON_B_PORT PORTHbits.RH8

typedef struct PushButton
{
    uint8_t state:1;
    uint8_t lastState:1;
    uint16_t timeDown;
    uint16_t timeUp;

} PushButton;

void UpdateButton(const unsigned int port, PushButton* pushButton);     // Only called by interrupt T2
void ResetButton(PushButton* pushButton);


#endif	/* PUSHBUTTON_H */

