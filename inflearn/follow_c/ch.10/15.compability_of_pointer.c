#include <stdio.h>

int main()
{
    // const int** pp2;
    // int* p1;
    // const int n = 13;
    // pp2 = &p1;
    // *pp2 = &n;
    // *p1 = 10;

    // printf("%d", n);

    const int y;
    const int* p2 = &y;
    int* p1;
    p1 = p2;
    *p1 = 2;

    printf("%d\n", y);
}