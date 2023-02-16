#include <stdio.h>

#define MAX_NUM 100

void clear_temp(){
    while (getchar() != '\n')
        continue;
}

int main(){
    int num = 0;
    int count = 0;
    int arr[MAX_NUM] = {0, };
    int val = 0;

    scanf("%d", &num);
    clear_temp;

    for(int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
        clear_temp;
    }

    scanf("%d", &val);
    clear_temp;
    
    for(int i = 0; i < num; i++)
    {
        if(arr[i] == val)
            count++;
    }

    printf("%d", count);

    return 0;
}