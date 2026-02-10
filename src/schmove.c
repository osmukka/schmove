#include <stdint.h>
#include <stdlib.h>

#include "schmove.h"


int schmove(uint8_t* src, uint8_t* dest)
{
    if(!src || !dest)
        return 1;

    for(int i = 0; i < 3; i++)
        if(src[i] < 0x41 || src[i] > 0x5a)
            return 1;

    uint8_t f = src[0];
    uint8_t s = src[1];
    uint8_t t = src[2];
    return 0;
}

int schmove_reverse(uint8_t* src, uint8_t* dest)
{
    return 0;
}

int schmove_block(uint8_t* src, uint8_t* dest, size_t size)
{
    return 0;
}

int schmove_block_reverse(uint8_t* src, uint8_t* dest, size_t size)
{
    return 0;
}


