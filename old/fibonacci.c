#include <stdio.h>

int fibonacci(int number);

int main() {
    for (int count = 1; count < 13; ++count)
        printf("%d ", fibonacci(count));

    return 0;
}

int fibonacci(int number){
    // int ans = 1;
    //
    // if(number > 1){
    //     for(int i = 1; number > i; i++){
    //     ans += fibonacci(i-1);
    //     } 
    // }
    if(number > 2)
        return fibonacci(number - 1) + fibonacci(number - 2);
    else
        return 1;
    


    // return ans;
}