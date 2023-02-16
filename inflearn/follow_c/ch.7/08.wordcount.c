#include <stdio.h>

int main()
{
    char ch;
    int characters = 0, words = 0, lines = 0;
    int isWord = 0, isLine = 0;

    printf("Enter text :\n");

    while((ch = getchar()) != '.')
    {
        if(ch != ' ' && ch != '\n')
            characters++;
        if(isWord == 0 && (ch != ' ' || ch != '\n'))
        {
            words++;
            isWord = 1;
        }
        if(ch == ' ' || ch == '\n')
            isWord = 0;

        if(isLine == 0 && ch != '\n')
        {
            lines++;
            isLine = 1;
        }
        if(ch == '\n')
            isLine = 0;
    }

    printf("Charaters = %d, Words = %d, Lines = %d\n", characters, words, lines);
    
    return 0;
}