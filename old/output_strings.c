#include <stdio.h>

#define TEST "A string from #define."

void custom_put(const char* str);
int custom_put2(const char* str);

int main(){

    // char str[60] = "String array initialized";
    // const char* ptr = "A pointer initialized";

    // puts("String without \\n");
    // puts("END");
    // puts(TEST);
    // puts(TEST + 5);
    // puts(&str[3]);
    // //puts(str[3]); // Error
    // puts(ptr + 3);


    // char str[] = { 'H', 'I', '!' }; // No \0 at the end.
    // puts(str);


    // char line[100];
    // while (gets(line))  // while (gets(line) != NULL)
    //     puts(line);

    // char line[100];
    // while (fgets(line, 100, stdin))
    //     fputs(line, stdout);


    // char str[] = "Just do it, do it!";
    // printf("%s\n", str);
    // puts(str);


    // char input[100] = "";
    // int ret = scanf("%10s", input); // Input : "Just do it, do it!\n" (Note %10s)
    // printf("%s\n", input);  // Output : "Just"
    // ret = scanf("%10s", input);     // Reads remaning buffer
    // printf("%s\n", input);          // Output : "do"


    custom_put("Just ");
    custom_put("Do it!");

    printf("%d\n", custom_put2("12345"));

    return 0;
}

void custom_put(const char* str){
    // for (int i = 0; i < sizeof(str); i++)
    //     putchar(str[i]);

    while (*str != '\0')    // while(*str)
        putchar(*str++);
}

int custom_put2(const char* str){
    int count = 0;
    while (*str){
        putchar(*str++);
        count++;
    }
    putchar('\n');

    return count;
}