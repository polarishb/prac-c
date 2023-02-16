#include <stdio.h>

int num2arr(int num){

    int arr[2];
    for(int i = 0; i < 2; i++){
        scanf("%1d", &arr[i]);
    }

    return arr[1];
}

int main(){
    // 26 > 2 + 6 = 8 >> 68 > 6 + 8 = 14 >> 84 > 8 + 4 = 12 >> 42 > 4 + 2 = 6 >> 26
    int num[2];
    int arr[2];
    int sum = 0;
    int sum_arr[2];
    int count = 0;

    for(int i = 0; i < 2; i++){
        scanf("%1d", &arr[i]);
    }
    num[0] = arr[0];
    num[1] = arr[1];
    while(1){   
        sum = arr[0] + arr[1];
        printf("sum is %d\n", sum);
        
        
        if(sum > 10){
           for(int i = 0; i < 2; i++){
               sum_arr[i] = scanf("%1d", &sum);
           }

           arr[0] = arr[1];
           arr[1] = sum_arr[1];
           printf("%d %d\n", arr[0], arr[1]);
        }
        else{
            arr[0] = arr[1];
            arr[1] = sum;
            printf("%d %d\n", arr[0], arr[1]);
        }
        count++;
        if(num[0] == arr[0] && num[1] == arr[1])
        break;
    }

    return 0;
}