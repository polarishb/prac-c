#include <stdio.h>

int main(){
    int arr[2][3] = { {1,2,3}, {4,5,6}};

    printf("%p %p %p\n", arr, arr[0], &arr[0]);

    return 0;
}