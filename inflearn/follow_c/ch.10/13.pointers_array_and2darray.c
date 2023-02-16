#include <stdio.h>

int main()
{
    /* Two of 1D arrays */

    // int arr0[3] = { 1, 2, 3};
    // int arr1[3] = { 4, 5, 6};

    // int* parr[2] = { arr0, arr1};

    // for (int j = 0; j < 2; ++j)
    // {
    //     for (int i = 0; i < 3; ++i)
    //         printf("%d(==%d, %d) ", parr[j][i], *(parr[j]+i), (*(parr + j))[i]);
    //     printf("\n");
    // }
    // printf("\n");

    /* 2D arrays are arrays of 1D arrays */

    // int arr[2][3] = { {1, 2, 3,}, {4, 5, 6} };

    // int *parr0 = arr[0];
    // int *parr1 = arr[1];

    // for (int i = 0; i < 3; i++)
    //     printf("%d ", parr0[i]);
    // printf("\n");

    // for (int i = 0; i < 3; i++)
    //     printf("%d ", parr1[i]);
    // printf("\n");

    /* Array of string of diverse lengths example */

    char* name[] = {"Aladdin", "Jasmine", "Magic Carpet", "Genie"};

    const int n = sizeof(name) / sizeof(char*);

    for(int i = 0; i < n; i++)
        printf("%s at %llu\n", name[i], (unsigned long long)name[i]);
    printf("\n");

    char aname[][15] = {"Aladdin", "Jasmine", "Magic Carpet", "Genie"};

    const int an = sizeof(aname) / sizeof(char[15]);

    for (int i = 0; i < an; i++)
        printf("%s at %llu\n", aname[i], (unsigned long long)aname[i]);
    printf("\n");

    return 0;
}