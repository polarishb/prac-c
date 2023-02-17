#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum spectrum {red, orange, yellow, green, blue};
const char* colors[] = { "red", "orange", "yellow", "green", "blue"};

#define LEN 30

int main()
{
    char choice[LEN] = { 0, };
    enum spectrum color;
    bool color_is_found = false;

    while (1)
    {
        printf("Input a color name (empty line to quit):\n");
        if (scanf("%[^\n]%*c", choice) != 1) break;
        for(color = red; color <= blue; color++){
            if (strcmp(choice, colors[color]) == 0){
                color_is_found = true;
                break;
            }
        }
        switch (color)
        {
            case red:
                printf("Red rose\n");
                break;
            case orange:
                printf("Orange fruit\n");
                break;
            case yellow:
                printf("Yellow sunflowers\n");
                break;
            case green:
                printf("Green apples\n");
                break;
            case blue:
                printf("Blue ocean\n");
                break;
        }
        if(!color_is_found) printf("Please try different color %s.\n", choice);
        color_is_found = false;
    }

    printf("Goodbye!\n");

    return 0;
}