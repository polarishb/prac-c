#include <stdio.h>

int main()
{
    const int arr[5] = { 1, 2, 3, 4, 5};

    const double arr2[3] = { 1.0, 2.0, 3.0};

    const double* const pd = arr2;
    // *pd = 3.0;
    // pd[2] = 1024.0;

    printf("%f %f", pd[2], arr2[2]);

    // pd++;

    return 0;
}