#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int arr_num[] = {0,};
    int max_arr = INT_MIN;
    int time = 0;

    for(int i = 0;i < 9; i++){
        scanf("%d", &arr_num[i]);
    }
    
    for(int i = 0; i < 9; i++){
        if(max_arr < arr_num[i]){
            max_arr = arr_num[i];
        }
    }

    printf("%d %d", )


}