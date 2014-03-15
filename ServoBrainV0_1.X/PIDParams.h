#ifndef PIDPARAMS_H
#define	PIDPARAMS_H

#include "stdint.h"

typedef struct PIDParams
{
    int16_t P;
    int16_t I;
    int16_t D;

    int32_t error;
    int32_t Iaccum;
    int32_t Pvalue;
    int32_t Dvalue;
    
} PIDParams;






#endif	/* PIDPARAMS_H */

