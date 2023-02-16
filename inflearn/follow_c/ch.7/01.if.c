#include <stdio.h>

int main()
{
    int number;

    printf("Input a positive integer : ");
    scanf("%d", &number);

    if (number % 2 == 0)
        printf("Even");

    if (number % 2 != 0)
        printf("Odd");

        return 0;

}