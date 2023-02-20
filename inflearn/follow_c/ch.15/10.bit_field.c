#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void char_to_binary(unsigned char uc)
{
    const int bits = CHAR_BIT * sizeof(unsigned char);
    for (int i = bits - 1; i >= 0; i--)
        printf("%d", (uc >> i) & 1);
}

void print_binary(char* data, int bytes)
{
    for(int i = 0; i < bytes; i++)
        char_to_binary(data[bytes - 1 - i]);
    printf("\n");
}

int main()
{
    struct items{
        bool has_sword  : 1;
        bool has_shield : 1;
        bool has_potion : 1;
        bool has_guntlet    : 1;
        bool has_hammer : 1;
        bool has_key    : 1;
        bool has_ring   : 1;
        bool has_amulet : 1;
    } items_flag;

    items_flag.has_sword    = 1;
    items_flag.has_shield   = 1;
    items_flag.has_potion   = 0;
    items_flag.has_guntlet  = 1;
    items_flag.has_hammer   = 0;
    items_flag.has_key  = 0;
    items_flag.has_ring = 0;
    items_flag.has_amulet   = 0;

    printf("Size = %zd\n", sizeof(items_flag));

    print_binary((char*)&items_flag, sizeof(items_flag));

    union {
        struct items bf;
        unsigned char uc;
    } uni_flag;

    uni_flag.uc = 0;
    uni_flag.bf.has_amulet = true;
    uni_flag.uc |= ( 1 << 4);

    print_binary((char*)&uni_flag, sizeof(uni_flag));
    
    struct file_time {
        unsigned int seconds : 5;
        unsigned int minutes : 6;
        unsigned int hours : 5;
    };

    struct file_date {
        unsigned int day : 5;
        unsigned int month : 4;
        unsigned int year : 7;
    } fd;

    fd.day = 28;
    fd.month = 12;
    fd.year = 8;

    printf("day %u, Month %u, Year %u\n", fd.day, fd.month, fd.year);

    return 0;
}