#include <stdio.h>
#include <stdlib.h>

//#include "tests.h"
#include "schmove.h"


int main()
{
    uint8_t triplet[3] = {'A', 'B', 'C'};
    uint8_t encoded_triplet[2];
    uint8_t decoded_triplet[3];

    schmove(triplet, encoded_triplet);
    printf("Encoded triplet: %d %d\n", 
            encoded_triplet[0],
            encoded_triplet[1]);

    schmove_reverse(encoded_triplet, decoded_triplet);
    printf("Decoded triplet: %d %d %d\n", 
            decoded_triplet[0],
            decoded_triplet[1],
            decoded_triplet[2]);

    uint8_t string[25] = "ABCDEFGHIJKLMNOPQRSTUVWX\0";
    uint8_t encoded[17] = {0};
    uint8_t decoded[25] = {0};

    schmove_block(string, encoded, 24);
    printf("Encoded block: ");
    for(int i = 0; i < 16; i++)
        printf(" %d", encoded[i]);
    printf("\n");

    schmove_block_reverse(encoded, decoded, 16);
    printf("Decoded block: ");
    for(int i = 0; i < 24; i++)
        printf(" %d", decoded[i]);
    printf("\n");

    return 1;
}

