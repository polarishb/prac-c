#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
    unsigned int u_max = UINT_MAX;

    // i to binary representation
    char buffer[33];
    unsigned int buffer2;
    buffer2 = u_max;
    for(int i = 0; i < sizeof(buffer); i++){
        buffer[i] = buffer2 % 2;
        buffer2 = buffer2 / 2;
    }

    //print decimal and binary
    printf("decimal: %u\n", u_max);
    printf("binary: %s\n", buffer);

    return 0;
}