#ifndef SCHMOVE_H
#define SCHMOVE_H

#include <stdint.h>
#include <stdlib.h>


int schmove(uint8_t* src, uint8_t* dest);
int schmove_reverse(uint8_t* src, uint8_t* dest);
int schmove_block(uint8_t* src, uint8_t* dest, size_t size);
int schmove_block_reverse(uint8_t* src, uint8_t* dest, size_t size);

#endif

