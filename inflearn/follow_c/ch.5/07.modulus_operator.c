#include <stdio.h>

int main()
{
    int hour = 0, minute = 0, second = 0;

    while (second >= 0){
        printf("Input seconds : ");
        scanf("%d", &second);
        if(second >= 0){
          minute = second / 60;
           second %= 60;

           hour = minute / 60;
           minute %= 60;

            printf("%d hours, %d minutes, %d seconds\n", hour, minute, second);
        } 
    }

    printf("Good bye\n");

    return 0;
}