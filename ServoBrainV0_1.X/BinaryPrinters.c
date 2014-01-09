#include "BinaryPrinters.h"

void PrintQ16B16(const int64_t value)
{
    double valueFloat;
    valueFloat = value;
    valueFloat /= 65536;

    printf("%+09.3f", valueFloat); printf(" ");
}
