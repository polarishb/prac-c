#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const char num);

int main()
{
    unsigned char i = to_decimal("01000110");
    unsigned char mask = to_decimal("00000101");

    print_binary(127);
    print_binary(-127);
    print_binary(~127 + 1);

    print_binary(12);
    print_binary(-12);
    print_binary(~12 + 1);

    print_binary(7);
    print_binary(-7);
    print_binary(~-7 + 1);

    return 0;
}

unsigned char to_decimal(const char bi[])
{
    size_t bits = strlen(bi);
    int sum = 0;

    for(int i = 0; i < bits; i++)
        if(bi[i] == '1') sum += pow(2, bits - 1 - i);

    return sum;
}

void print_binary(const char num)
{
    unsigned char bits[8] = { '0', '0', '0', '0', '0', '0', '0', '0'};
    int power = strlen(bits);
    // int sum = num;
    int mask;

    for(int i = 0; i < power; i++){
        // if( sum >= pow(2, power - 1 - i) ){
        //     sum -= pow(2, power - 1 - i);
        //     bits[i] = '1';
        // }
        mask = pow(2, power - 1 - i);
        if((num & mask) == mask) bits[i] = '1';

    }

    printf("Decimal\t%d\t== Binary %s\n", num, bits);
}
