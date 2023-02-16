#include <stdio.h>

void check(int piece, int count);

int main()
{
    int king, queen, rook, bishop, knight, pawn;
    scanf("%d %d %d %d %d %d", &king, &queen, &rook, &bishop, &knight, &pawn);

    check(king, 1);
    check(queen, 1);
    check(rook, 2);
    check(bishop, 2);
    check(knight, 2);
    check(pawn, 8);

    return 0;
}

void check(int piece, int count)
{
        printf("%d ", count - piece);
}