#include <stdio.h>

int main(int argc,char* argv[]){
    int m;
    float f;
    scanf("%2d%*c%*c%f", &m, &f);
    printf("%-+2d%7.2f\n", m, f);

    return 0;
}