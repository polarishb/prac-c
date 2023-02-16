#include <stdio.h>

void clear_temp(){
    while (getchar() != '\n')
        continue;
}

int main()
{
    int num_arr[9] = {0, };
    int max = 0;
    int count = 0;

    for(int i = 0; i < 9; i++)
    {
        scanf("%d", &num_arr[i]);
        clear_temp;
    }

    for(int i = 0; i < 9; i++)
    {
        if(num_arr[i] > max)
        {
            max = num_arr[i];
            count = i + 1;
        }
    }

    printf("%d\n%d", max, count);

    return 0;
}