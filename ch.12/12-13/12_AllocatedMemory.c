#include <stdio.h>
#include <stdlib.h>

int main(){
    float x;
    //char str[];

    int arr[100];

    /*
        malloc() returns a void type pointer.
        void* : generic pointer

        free() deallocates the memory
    */

    double* ptr = NULL;

    ptr = (double*)malloc(30 * sizeof(double));

    if(ptr == NULL){
        puts("Memory allocation failed.");

        /*
            exit(EXIT_FAILUTRE) is similar to return 1 IN main().
            exit(EXIT_SUCCESS) is similar to return 0 IN main().
        */

       exit(EXIT_FAILURE);
    }

    printf("Before free %p\n", ptr);

    free(ptr); // no action occurs when ptr is NULL

    printf("After free %p\n", ptr);

    ptr = NULL; // optional

    /* Dynamic Allocated Array */

    int n = 5;
    ptr = (double*)malloc(n * sizeof(double));

    if (ptr != NULL){   // if(!ptr)
        for(int i = 0; i < n; i++)
            printf("%f ", ptr[i]);
        printf("\n");

        for(int i = 0; i < n; i++)
            * (ptr + i) = (double)i;

        for(int i = 0; i < n; i++)
            printf("%f ", ptr[i]);
        printf("\n");
    }

    free(ptr);
    ptr = NULL;

    /*
        Comparision to VLA

        VLA
        - not supported by VS compilers.
        - automatic duration, cannot be resized
        - limited by stack size (when compiler plcaes VLA in stack segment)
    */

    return 0;
}