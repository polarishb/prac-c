#include <stdio.h>

int main()
{
    unsigned num;
    int isPrime = 1;

    scanf("%u", &num);

    for ( int i = 2; (i*i) <= num; i++)
    {
        if (num % i == 0)
        {
            isPrime = 0;

            if ( num == i * i)
                printf("%u is divisable by %d.\n", num, i);
            else
                printf("%u is divisable by %d and %u .\n", num, i, num/i);
        }
    }

    // for ( int i = 2;i <= num; i++)
    // {
    //     if(num % i != 0 || num == i)
    //         isPrime = 1;
    //     else if(num % i == 0)
    //     {
    //         isPrime = 0;
    //         break;
    //     }
    // }

    if (isPrime)
        printf("%u is a prime number.\n", num);
    else
        printf("%u is a not prime number.\n", num);

    return 0;
}