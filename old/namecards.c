#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH   20
#define NAME    "&name&"
#define ADDRESS "&address&"

void print_multiple_chars(char c, int n_stars, bool print_newline);
void print_centered_str(char str[]);

int main() {

    print_multiple_chars('*', WIDTH, true);

    print_centered_str(NAME);
    print_centered_str(ADDRESS);

    print_multiple_chars('*', WIDTH, false);

    return 0;
}

void print_multiple_chars(char c, int n_stars, bool print_newline){
    for (int i = 0; i < n_stars; i++)
        printf("%c", c);

    if(print_newline)
        printf("\n");
}

void print_centered_str(char str[]){
    int n_blanks = 0;
    n_blanks = (WIDTH - strlen(str)) / 2;
    print_multiple_chars(' ', n_blanks, false);
    printf("%s\n", str);

}