#include <stdio.h>

#define NUMBER 5

int main()
{
    int num_arr[NUMBER];
    int sum = 0;

    printf("Enter %d numbers : ", NUMBER);
    
    for(int i = 0; i < NUMBER; i++){
        scanf("%d", &num_arr[i]);
        sum += num_arr[i];
    }

    printf("Sum = %d", sum);

    return 0;
}