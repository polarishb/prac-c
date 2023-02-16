#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if (argc < 3)
        printf("Wrong Usage of %s\n", argv[0]);
    else
    {
        int times = atoi(argv[1]);

        for (int i = 0; i < times; i++)
            puts(argv[2]);

        printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));
    }
    
    return 0;
}