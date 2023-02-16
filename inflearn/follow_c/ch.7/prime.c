#include <stdio.h>
#include <stdbool.h>

int checkPrime(int a);

int main()
{

    unsigned num;
    bool isPrime;

    scanf("%u", &num);
    isPrime = checkPrime(num);   

    if (isPrime)
        printf("%u is a prime number.\n", num);
    else
        printf("%u is not a prime number.\n", num);

    return 0;
}

int checkPrime(int a){
    for (int i = 2; i < a; i++){
        if(a % i == 0)
            return 0;
    }

    return 1;
}
