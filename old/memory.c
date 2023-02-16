#include <stdio.h>

int main(){

    int a = 3, b = 5, c = 7, d = 9;
    int* a_ptr, * b_ptr, * c_ptr, *d_ptr;

    printf("%p %p %p %p", &a, &b, &c, &d);

    return 0;
}