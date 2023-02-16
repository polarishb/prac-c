#include <stdio.h>

int main()
{
    int a = 0;
    a++;// a = a + 1 or a += 1;
    printf("%d\n", a);

    ++a;
    printf("%d\n", a);

    double b = 0;
    b++;
    printf("%f\n", b);

    ++b;
    printf("%f\n", b);

    int count = 0;
    while (count < 10)
    {
        printf("%d ", count);
        count++;
    }

    int i = 1, j = 1;
    int i_post, pre_j;

    i_post = i++;
    pre_j = ++j;

    printf("%d %d\n", i, j);
    printf("%d %d\n", i_post, pre_j);

    
}