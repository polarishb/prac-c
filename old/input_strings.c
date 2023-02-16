#include <stdio.h>

#define STRLEN 81

char* custom_string_input(char* st, int n);

int main(){
    // //char* name = "";  // Error
    // char name[128];
    // int result = scanf("%s", name);


    // char words[STRLEN] = "";
    // gets(words);
    // //gets_s(words, sizeof(words)); //c11
    // //int result = scanf("%s", words);
    // printf("START\n");
    // printf("%s", words);
    // puts(words);
    // puts("END.");


    // char words[STRLEN] = "";
    // fgets(words, STRLEN, stdin);    // NOT remove \n

    // // for(int i = 0; i < STRLEN; i++){
    // //     if(words[i] == '\n'){
    // //         words[i] = '\0';
    // //         break;
    // //     }
            
    // // }

    // int i = 0;
    // while (words[i] != '\n' && words[i] != '\0')
    //     i++;
    // if (words[i] == '\n')
    //     words[i] = '\0';

    // fputs(words, stdout);
    // fputs("END", stdout);


    // char small_array[5];
    // puts("Enter long strings:");
    // //fgets(small_array, 5, stdin);   // FILE *_Stream
    // printf("%p\n", small_array);
    // printf("%p\n", fgets(small_array, 5, stdin));    // Return value of fgets
    // fputs(small_array, stdout);


    // char small_array[5];
    // puts("Enter long strings:");
    // while (fgets(small_array, 5, stdin) != NULL && small_array[0] != '\n')
    //     fputs(small_array, stdout);


    // char str1[6], str2[6];
    // //int count = scanf("%5s %5s", str1, str2);
    // //int count = scanf("%6s %6s", str1, str2);
    // int count = scanf_s("%5s %5s", str1, 6, str2, 6);
    // printf("%s|%s \n", str1, str2);


    char word[11];
    puts(custom_string_input(word, 11));

    return 0;
}

char* custom_string_input(char* st, int n){
    char* ret_ptr;
    int i = 0;

    ret_ptr = fgets(st, n, stdin);
    if (ret_ptr){
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_ptr;
}