#include <stdio.h>

#define MESSAGE "A symbolic string contant"
#define MAXLENGTH 81

int main(){
    char words[MAXLENGTH] = "A string in an array";
    const char* pt1 = "A pointer to a string.";

    puts("Puts() adds a newline at the end:");
    puts(MESSAGE);
    puts(words);
    puts(pt1);
    words[3] = 'p';
    puts(words);
    //pt[8] = 'A';

    char greeting[50] = "Hello, and"" How are" " you"
        " today!";

    puts(greeting);

    printf("\" To be, or not to be\" Hamlet said.\n");

    printf("%s, %p, %c\n", "We", "are", *"excellent programmers");

    const char m1[15] = "Love you!";

    for (int i = 0; i < 15; i++)
        printf("%d ", (int)m1[i]);
    printf("\n");

    const char m2[15] = { 'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '!', '\0'};

    for (int i = 0; i < 15; i++)
        printf("%d ", (int)m2[i]);
    printf("\n");

    const char m3[] = "Love you, too!";

    int n = 8;
    char cookies[1] = { 'A', };
    char cakse[2 + 5] = { 'A', };
    char pies[2 * sizeof(long double) + 1] = { 'A', };
    char crumbs[n];

    char truth[10] = "Truth is ";
    
}