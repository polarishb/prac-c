#include <stdio.h>

void clear_temp();

int main(){

    int total = 0, num = 0, price = 0, value = 0, sum = 0;

    scanf("%d", &total);
    clear_temp;
    scanf("%d", &num);
    clear_temp;

for(int i = 0; i < num; i++)
    {
        scanf("%d %d", &price, &value);
        clear_temp;
        sum += price * value;
    }

    if(total == sum)
        printf("Yes");
    else
        printf("No");

    return 0;
}

void clear_temp(){
    while (getchar() != '\n')
        continue;
}