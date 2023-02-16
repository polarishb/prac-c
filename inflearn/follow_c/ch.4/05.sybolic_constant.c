#include <stdio.h>
#define PI 3.141592f

int main()
{
    float radius, area, circum;

    printf("Input radois\n");

    scanf("%f", &radius);

    area = PI * radius * radius;
    circum = 2.0 * PI * radius;

    printf("Area is %f\n", area);
    printf("Circumference is %f\n", circum);

    return 0;
}