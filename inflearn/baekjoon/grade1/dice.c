#include <stdio.h>

int main()
{
    int dice1, dice2, dice3;
    scanf("%d %d %d", &dice1, &dice2, &dice3);

    if (dice1 == dice2 && dice1  == dice3)
        printf("%d ", 10000 + dice1 * 1000);
    else if (dice1 == dice2 || dice1 == dice3 || dice2 == dice3)
    {
        if (dice2 == dice3)
            printf("%d ", 1000 + dice2 * 100);
        else
            printf("%d ", 1000 + dice1 * 100);
    }
    else
    {
        int max = 0;

        dice3 < (dice1 < dice2 ? (max = dice2) : (max = dice1)) ?  : (max = dice3);

        printf("%d", max * 100);
    }
        
}