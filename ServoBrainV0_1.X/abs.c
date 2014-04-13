#include "abs.h"

int16_t abval16(int16_t val)
{
    return (val<0 ? (-val) : val);
}

 int32_t abval32(int32_t val)
 {
     return (val<0 ? (-val) : val);
 }
