#include <stdio.h>

int fibonacci(int number);
int fibonacci_loop(int number);

int main()
{
    for (int count = 1; count < 13; count++)
        printf("%d ", fibonacci(count));
    printf("\n");
    for (int count = 1; count < 13; count++)
        printf("%d ", fibonacci_loop(count));
    return 0;
}

int fibonacci(int number)
{
    if(number > 2){
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
    else
        return 1;
}

int fibonacci_loop(int number)
{
    int num_arr[number];

    for(int i = 0; i < number; i++){
        if(i > 1){
           num_arr[i] = num_arr[i-1] + num_arr[i-2];
        }
        else
            num_arr[i] = 1;
    }

    return num_arr[number - 1];
}