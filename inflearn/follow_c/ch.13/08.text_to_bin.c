#include <stdio.h>
#include <windows.h>

int main()
{
    FILE* fp = fopen("test", "rb");

    unsigned char ch;

    SetConsoleOutputCP(CP_UTF8);

    while (fread(&ch, sizeof(unsigned char), 1, fp) > 0)
    {
        printf("%c", ch);
    }

    fclose(fp);

    return 0;
}