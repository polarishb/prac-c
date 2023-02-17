#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);

int main()
{
    char options[] = { 'u', 'l', 't' };
    int n = sizeof(options) / sizeof(char);

    typedef void (*FUNC_TYPE)(char*);
    FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose};

    printf("Enter a string\n>> ");

    char input[100];

    while (scanf("%[^\n]%*c", input) != 1)
        printf("Please try again.\n>> ");

        
    while(1){
        printf("Choose an option:\nu) to upper\nl) to lower\nt) transpose\n");
    
        char temp;

        while (scanf("%[^\n]%*c", &temp) != 1)
            printf("Please try again.\n>> ");

        bool check = false;

        for(int i = 0; i < n; i++){
            if(temp == options[i]){
                operations[i](input);
                check = true;
                break;
            }
        }
        if (!check) printf("Please try again\n>> ");
        else break;
    }

    printf("%s\n", input);

    return 0;
}

void update_string(char* str, int(*pf)(int))
{
        while(*str)
    {
        *str = (*pf)(*str);
        str++;
    }
}

void ToUpper(char* str)
{
    update_string(str, toupper);
}

void ToLower(char* str)
{
    update_string(str, tolower);
}

void Transpose(char* str)
{
    while (*str)
    {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}
