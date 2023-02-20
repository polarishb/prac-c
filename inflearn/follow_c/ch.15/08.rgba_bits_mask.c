#include <stdio.h>

#define BYTE_MASK 0xff

int main()
{
    unsigned int rgba_color = 0x66CDAAFF;

    unsigned char red, green, blue, alpha;

    alpha     = 0;
    blue       = 0;
    green     = 0;
    red         = 0;

    alpha = (rgba_color & BYTE_MASK);
    blue = ((rgba_color >> 8) & BYTE_MASK);
    green = ((rgba_color >> 16) & BYTE_MASK);
    red = ((rgba_color >> 24) & BYTE_MASK);

    printf("(R, G, B, A) = (%hhu, %hhu, %hhu, %hhu)\n", red, green, blue, alpha);

    return 0;
}