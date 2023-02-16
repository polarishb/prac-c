#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d_3(int* ar, int row, int col);

int main()
{
    int data[ROWS][COLS] = {
                                            {1, 2, 3, 4},
                                            {5, 6, 7, 8},
                                            {9, 0, 1, 2}
                                                                    };

    int* ptr = &data[0][0];
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++)
            printf("%d ", *(ptr + j + COLS * i));
        printf("\n");
    }

}

int sum2d_3(int* ar, int row, int col)
{
    int r, c, tot = 0;
    for (r = 0; r < row; r++)
        for (c = 0; c < col; c++)
            tot += *(ar + c + col * r);

    return tot;    
}