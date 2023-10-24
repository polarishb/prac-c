#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int main() {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int count = 0;
    const char* my_string = "i love you";

    for (int i = 0; i < strlen(my_string); i++) {
        if (my_string[i] == ' ')
            count++;
    }

    char* str = (char*)malloc(sizeof(char) * (strlen(my_string) + 1));
    strcpy(str, my_string);
    char* ptr = strtok(str, " ");

    char** answer = (char**)malloc(sizeof(char*) * (count + 1));
    for (int i = 0; i < count + 1; i++) {
        answer[i] = (char*)malloc(sizeof(char) * strlen(ptr));
        memset(answer[i], '\0', strlen(ptr));
        answer[i] = ptr;
        ptr = strtok(NULL, " ");
        printf("%s\n", answer[i]);
    }

    return 0;
}