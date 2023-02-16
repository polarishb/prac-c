#include <stdio.h>

int main()
{
    float seed;
    float target;
    float interest;
    int count = 0;

    printf("Input seed money : ");
    scanf("%f", &seed);

    printf("Input target money : ");
    scanf("%f", &target);

    printf("Input annual interest (%%) : ");
    scanf("%f", &interest);

    while(seed < target){
        seed = seed + seed * (0.01 * interest);
        printf("%f\n", seed);
        count++;
    }
    printf("It takes %d years\n", count);

    return 0;
}