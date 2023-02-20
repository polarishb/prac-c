#include <stdio.h>
#include <stdalign.h>

int main()
{
#ifdef __clang_major__
    printf ("clang detected version %d.%d\n", __clang_major__, __clang_minor__);
#endif

#ifdef __GNUC__
    printf("gcc detected version %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif
    printf("Alignment of char = %zu\n", alignof(char));
    printf("alignof(float[10]) = %zu\n", alignof(float[10]));
    printf("alignof(struct{char c; int n;}) = %zu\n", alignof(struct {char c; int n;}));

    double dx;
    char ca;
    char cx;
    double dz;
    char cb;
    //char _Alignas(double) cz;
    //char alignas(16) cz;
    char cz;

    printf("char alignment: %zd\n", alignof(char));
    printf("double alignment: %zd\n", alignof(double));

    printf("&dx: %p %lld\n", &dx, (long long)&dx % 8);

    return 0;
}