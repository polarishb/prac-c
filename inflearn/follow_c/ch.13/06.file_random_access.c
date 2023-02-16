#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch;
    long cur;

    FILE* fp = fopen("test", "r");

    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);

    fseek(fp, 2L, SEEK_SET);
    cur = ftell(fp);
    printf("ftell = %ld\n", cur);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);
    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);

    fseek(fp, -2L, SEEK_CUR);
    cur = ftell(fp);
    printf("ftell = %ld\n", cur);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);


    fseek(fp, 0L, SEEK_END);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);

    fseek(fp, -1L, SEEK_END);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);

    fseek(fp, -2L, SEEK_END);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);


    fpos_t pt;
    pt = 10;
    fsetpos(fp, &pt);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);
    fgetpos(fp, &pt);
    printf("%lld\n", pt);

    return 0;
}