#include <stdio.h>
#include <float.h>

int main()
{
    double input = 0.0;
    double min = DBL_MAX;
    double max = DBL_MIN;
    double sum = 0.0;
    int count = 0;

    while(scanf("%lf", &input) == 1)
    {
        sum += input;
        
        if (input < min)
            min = input;
        if (input > max)
            max = input;

        // min = (input < min) ? input : min;
        // max = (input > max) ? input : max;
        
        count++;
    }

    printf("min = %f, max = %f, ave = %f", min, max, sum / count);

    return 0;
}