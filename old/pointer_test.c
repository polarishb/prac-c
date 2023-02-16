#include <stdio.h>

int main(){
    long long *ptr = 0;

    printf("%p %lld\n", ptr, (long long)ptr);

    ptr++;

    printf("%p %lld\n", ptr, (long long)ptr);
}