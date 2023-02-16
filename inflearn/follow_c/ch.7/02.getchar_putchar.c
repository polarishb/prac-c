#include <stdio.h>

int main()
{
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (ch >= 'a' && ch <= 'z')
            ch -= 'a' - 'A';
        else if (ch >= 'A' && ch <= 'Z')
            ch += 'a' - 'A';
        if (ch >= '0' && ch <= '9')
            ch = '*';
        if (ch == 'f' || ch == 'F')
            ch = 'X';

        putchar(ch);
    }

    putchar(ch);

    return 0;
}