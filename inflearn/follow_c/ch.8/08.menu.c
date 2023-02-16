#include <stdio.h>

void get_integer(void);

int main()
{
    char c;
    int num;

    while(c != 'q')
    {
        printf("Enter the letter of your choice:\n");
        printf("a. avengers\tb. beep\n");
        printf("c. count\tq. quit\n");

        scanf("%c", &c);

        if ( c == 'a')
            printf("Avengers Assemble\n");
        else if ( c == 'b')
            printf("\a\n");
        else if ( c == 'c')
        {
            printf("Enter an integer :\n");
            get_integer();
        }
        else if ( c == 'q');         
        else
        {
            printf("Error with %d.\n", c);
            exit(1);
        }

        
    while(getchar() != '\n')     continue;
    }

    return 0;
}

void get_integer(void)
{
    int num;
    scanf("%d", &num);
    
    for(int i = 1; i <= num; i++)
        printf("%d\n", i);
}