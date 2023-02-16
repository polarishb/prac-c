#include <stdio.h>

int main()
{
    const int code = 337;
    int try = 0;

    // while(try != code)
    // {
    //     printf("Enter secret code : ");
    //     scanf("%d", &try);
    // }
    
    do
    {
        printf("Enter secret code : ");
        scanf("%d", &try);
    }
     while (try != code);
    

    printf("Good!\n");
}