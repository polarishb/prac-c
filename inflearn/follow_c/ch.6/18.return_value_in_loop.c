#include <stdio.h>

int power(int base, int exp);

int main()
{
    int base, exp;
    while(scanf("%d %d", &base, &exp) == 2)
    {
        printf("Result = %d\n", power(base, exp));
    }

    return 0;
}

int power(int base, int exp)
{
    int result = 1;
    for(int i = 0; i < exp; i++)
        result *= base;

    return result;
}