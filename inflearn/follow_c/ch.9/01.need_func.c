#include <stdio.h>
#include <string.h>

#define WIDTH      30
#define NAME        "Woo-Jun Kim"
#define ADDRESS "Seoul, Korea"

// void print_bar(int width);
// void print_space(int n_string);
void print_multiple_char(char c, int n);
void print_string(char str[]);

int main()
{
    // print_bar(WIDTH);
    // print_space(strlen(NAME));
    // printf("%s\n", NAME);
    // print_space(strlen(ADDRESS));
    // printf("%s\n", ADDRESS);
    // print_bar(WIDTH);

    print_multiple_char('*', WIDTH);
    printf("\n");
    print_string(NAME);
    print_string(ADDRESS);
    print_multiple_char('*', WIDTH);
    printf("\n");

    return 0;
}

void print_multiple_char(char c, int n)
{
    for(int i = 0; i < n; i++)
        printf("%c", c);
}

void print_string(char str[])
{
    print_multiple_char(' ', (WIDTH - strlen(str)) / 2);
    printf("%s\n", str);
}

// void print_bar(int width)
// {
//     for(int i = 0; i < width; i++)
//         printf("*");
//     printf("\n");
// }

// void print_space(int n_string)
// {
//     int space = 0;

//     space = (WIDTH - n_string) / 2;
    
//     for (int i = 0; i < space; i++)
//         printf(" ");
// }