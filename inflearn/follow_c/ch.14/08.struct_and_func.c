#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
    char first[NLEN];
    char last[NLEN];
    int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
void s_gets(char* st, int n);

int main()
{
    struct name_count user_name;

    receive_input(&user_name);
    count_characters(&user_name);
    show_result(&user_name);

    return 0;
}

void receive_input(struct name_count* name)
{
    int flag;

    printf("Input your first name:\n>>");
    // s_gets(name->first, NLEN);
    flag = scanf("%[^\n]%*c", name->first);
    if(flag != 1)
        printf("Wrong input.\n");

    printf("Input your last name:\n>>");
    s_gets(name->last, NLEN);
}

void count_characters(struct name_count* name)
{
    name->num = strlen(name->first) + strlen(name->last);
}

void show_result(const struct name_count* name)
{
    printf("Hi, %s %s. Your name has %d characters.\n", name->first, name->last, name->num);
}

void s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st , n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n') continue;
    }
}