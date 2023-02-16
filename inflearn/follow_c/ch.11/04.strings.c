#include <stdio.h>

#define STRLEN 81

int main()
{
    char words[STRLEN] = "";
    fgets(words, STRLEN, stdin);

    for(int i = 0; i < STRLEN; i++)
        if(words[i] == '\n') words[i] = '\0';

    fputs(words, stdout);
    fputs("END", stdout);

    return 0;
}