#include <stdio.h>
#include <math.h>

void char_binary(const char num);
void int_binary(const int num);

int main()
{

}

void char_binary(const char num)
{
    printf("Decimal %3d \t== Binary ", num);

    const size_t bits = sizeof(num) * 8;
    for (size_t i = 0; i < bits; i++)
    {
        const char mask = 1 << (bits - 1 - i);

        if ((num & mask) == mask)
            printf("%d", 1);
        else
            printf("%d", 0);
    }

    printf("\n");
}

void int_binary(const int num)
{
    printf("Decimal %3d \t== Binary ", num);

    const size_t bits = sizeof(num) * 8;
    for (size_t i = 0; i < bits; i++)
    {
        const int mask = 1 << (bits - 1 - i);

        if ((num & mask) == mask)
            printf("%d", 1);
        else
            printf("%d", 0);
    }

    printf("\n");
}