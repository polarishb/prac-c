#include <stdio.h>

int main()
{

    int hour, minute, time, temp;
    scanf("%d %d %d", &hour, &minute, &time);

    minute+= time;

    temp = minute / 60;
    minute %= 60;

    hour += temp;
    hour %= 24;

    printf("%d %d", hour, minute);

    return 0;
}