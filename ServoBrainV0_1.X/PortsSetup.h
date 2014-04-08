/* 
 * File:   PortsSetup.h
 * Author: JRK
 *
 * Created on April 23, 2013, 6:20 PM
 */

#ifndef PORTSSETUP_H
#define	PORTSSETUP_H

#include "PPS.h"

#define BUTTON_A_PORT PORTHbits.RH9
#define BUTTON_B_PORT PORTHbits.RH8

void PortsSetup();

#endif	/* PORTSSETUP_H */

