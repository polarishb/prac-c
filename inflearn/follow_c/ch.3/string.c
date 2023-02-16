#include <stdio.h>

int main()
{
    char c = 'A';
    char d = '*';// d = 'A'

    printf("%c %hhd\n", c, c);
    printf("%c %hhd\n", d, d);

    printf("%c \n", c + 1);

    char a = '\a';
    printf("%c\n", a);

    return 0;
}