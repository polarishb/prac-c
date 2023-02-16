#include <stdio.h>

int main()
{
    float won = 0.0f;
    float dollar = 0.0f;

    printf("Input won\n");
    scanf("%f", &won);

    dollar = won * 0.00074f;

    printf("Dollor = %f\n", dollar);

    return 0;
}