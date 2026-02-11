#include <stdint.h>
#include <stdlib.h>

#include "schmove.h"

// Calculates the first byte of the output.
static uint8_t A(uint8_t f, uint8_t t)
{
    return f | (t & 0x1c) << 3;
}

// Calculates the second byte of the output.
static uint8_t B(uint8_t s, uint8_t t)
{
    return s | t << 6;
}

// Extracts the 1st or 2nd byte from encoded data.
static uint8_t Ar(uint8_t f)
{
    return f & 0x1f;
}

// Extracts the 3rd byte from encoded data.
static uint8_t Br(uint8_t f, uint8_t s)
{
    return (f & 0xe0) >> 3 | s >> 6;
}


int schmove(uint8_t* src, uint8_t* dest)
{
    if(!src || !dest)
        return 1;

    for(int i = 0; i < 3; i++)
        if(src[i] < 0x41 || src[i] > 0x5a)
            return 1;

    uint8_t f = src[0] - 64;
    uint8_t s = src[1] - 64;
    uint8_t t = src[2] - 64;

    dest[0] = A(f, t);
    dest[1] = B(s, t);

    return 0;
}

int schmove_reverse(uint8_t* src, uint8_t* dest)
{
    if(!src || !dest)
        return 1;

    uint8_t f = src[0];
    uint8_t s = src[1];

    dest[0] = Ar(f) + 64;
    dest[1] = Ar(s) + 64;
    dest[2] = Br(f, s) + 64;
    return 0;
}

int schmove_block(uint8_t* src, uint8_t* dest, size_t size)
{
    if(!src || !dest || !size || size % 3)
        return 1;

    for(int i = 0; i < size / 3; i++)
    {
        schmove(src, dest);
        src += 3;
        dest += 2;
    }
    return 0;
}

int schmove_block_reverse(uint8_t* src, uint8_t* dest, size_t size)
{
    if(!src || !dest || !size || size % 2)
        return 1;

    for(int i = 0; i < size / 2; i++)
    {
        schmove_reverse(src, dest);
        src += 2;
        dest += 3;
    }
    return 0;
}


