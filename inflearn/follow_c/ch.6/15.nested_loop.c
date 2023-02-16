#include <stdio.h>

// int main()
// {


//     for (int i = 0; i < 5; i++){
//     char c = 'A';
//         for (int j = 0; j < 11; j++){
//             printf("%c ", c);
//             c++;
//         }            
//     printf("\n");
//     }

//     return 0;
// }

// #define NUM_ROWS 5
// #define FIRST_CHAR 'A'
// #define LAST_CHAR 'K'

// int main()
// {
//     int r;
//     int c;

//     for (r = 0; r < NUM_ROWS; ++r)
//     {
//         for (c = FIRST_CHAR; c <= LAST_CHAR; ++c)
//             printf("%c ", c);
//         printf("\n");
//     }

//     return 0;
// }

// #define NUM_ROWS 10
// #define FIRST_CHAR 'A'

// int main()
// {
//     int r;
//     int c;

//     for (r = 0; r < NUM_ROWS; ++r)
//     {
//         for (c = FIRST_CHAR; c <= FIRST_CHAR + r; ++c)
//             printf("%c ", c);
//         printf("\n");
//     }

//     return 0;
// }

#define NUM_ROWS 12
#define FIRST_CHAR 'A'
#define LAST_CHAR 'L'

int main()
{
    int r;
    int c;

    for (r = 0; r < NUM_ROWS; ++r)
    {
        for (c = FIRST_CHAR + r; c <= LAST_CHAR; ++c)
            printf("%c ", c);
        printf("\n");
    }

    return 0;
}