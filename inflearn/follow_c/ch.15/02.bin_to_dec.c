#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

unsigned char to_decimal(const char bi[]);

int main()
{
    printf("Binary (string) to Decimal conversion\n");

    printf("%d\n", to_decimal("00000110"));
    printf("%d\n", to_decimal("00010110"));

    printf("%d\n", to_decimal("10010100"));

    return 0;
}

unsigned char to_decimal(const char bi[])
{
    int num = 0;
    double count = 7;

    for(int i = 0; i < 8; i++){
        if(bi[i] == '1') num += pow(2, count);
        count--;
    }

    return num;
}