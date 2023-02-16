#include <stdio.h>

extern int el;
//extern int il;

void testLinkage(){

    printf("DoSomethin called\n");
    printf("%d\n", el);
    //printf("%d\n", il);
    //printf("%d", dodgers);

    el++;
}