#include <stdio.h>

// int main(){
//     char num[2];
//     char calc[2];
//     int num_a, num_b, num_c;
//     int time = 1;

//     scanf("%s", num);
//     if(num[1] == 0){
//         num[1] = num[0];
//         num[0] = '0';
//     }
//     num_a = num[0] - 48;
//     num_b = num[1] - 48;

//     num_c = (num_a + num_b) % 10;

//     while(1){
//         calc[0] = num_b + 48;
//         calc[1] = num_c + 48;

//         if(num[0] == calc[0] && num[1] == calc[1]){
//             printf("%d", time);
//             break;
//         }
//         else{
//             num_a = num_b;
//             num_b = num_c;
//             num_c = (num_a + num_b) % 10;

//             time++;
//         }
//     }

//     return 0;
// }

int main(){

    int num = 0;
    int n;
    int t = 0;
    int a = 0, b = 0, c = 0;

    scanf("%d", &num);
    n = num;
    while(1){
        a = num / 10;
        b = num % 10;
        c = (a + b) % 10;
        num = (b*10) + c;

        t++;

        if(num == n)
            break;
    }
    
    printf("%d", t);

    return 0;
}