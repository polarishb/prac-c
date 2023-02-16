#include <stdio.h>

void print_binary(unsigned long n);
void print_binary_loop(unsigned long n);

int main()
{
    unsigned long num = 100;

    print_binary_loop(num);    printf("\n");
    print_binary(num);

    return 0;
}

void print_binary(unsigned long n)
{
    if(n > 0){
        print_binary(n/2);
        printf("%ld", n % 2);
    }
}

void print_binary_loop(unsigned long n)
{
    unsigned long num_arr[sizeof(long) * 8];
    int num = 0;
    for(num = 0; n > 0; num++){
        num_arr[num] = n % 2;
        n /= 2;
    }
    for(int i = num - 1; i >= 0; i--){
        printf("%ld", num_arr[i]);
    }
}