#include <stdio.h>

/*
    loop vs recursion
    factorial : 3! = 3 * 2* 1, 0! = 1
    5! = 5 * 4! = 5 * 4 * 3! = ....
*/

long loop_factorial(int n);
long recursion_factorial(int n);

int main()
{
    int num = 5;

    printf("%ld\n", loop_factorial(num));
    printf("%ld\n", recursion_factorial(num));

    return 0;
}

long loop_factorial(int n)
{
    long ans;
    for(ans = 1; n > 1; n--)
        ans *= n;

    return ans;
}

long recursion_factorial(int n)
{
    if (n > 0)
        return n * recursion_factorial(n - 1);
    else
        return 1;
}