#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SLEN 81

struct namect {
    char* fname;
    char* lname;
    int letters;
};

void getinfo(struct namect*);
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);
char* s_gets(char* st, int n);

int main()
{


    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);

    return 0;
}

void getinfo(struct namect* name)
{
    char buffer[SLEN] = { 0, };
    int flag;

    printf("Please enter your first name.\n");
    // s_gets(name->fname, SLEN);
    flag = scanf("%[^\n]%*c", buffer);
    if (flag != 1)
        printf("Wrong input");
    else
    {
        name->fname = (char*)malloc(strlen(buffer) + 1);
        if (name->fname != NULL)
            strcpy(name->fname, buffer);
        else
            printf("Malloc() failed");
    }

    printf("Please enter your last name.\n");
    // s_gets(name->lname, SLEN);
    flag = scanf("%[^\n]%*c", buffer);
    if (flag != 1)
        printf("Wrong input");
    else
    {
        name->lname = (char*)malloc(strlen(buffer) + 1);
        if (name->lname != NULL)
            strcpy(name->lname, buffer);
        else
            printf("Malloc() failed");
    }
}

void makeinfo(struct namect* name)
{
    name->letters = strlen(name->fname) + strlen(name->lname);
}

void showinfo(const struct namect* name)
{
    printf("%s %s, your name contains %d letters.\n", name->fname, name->lname, name->letters);
}

void cleanup(struct namect* name)
{
    free(name->fname);
    free(name->lname);
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n') continue;
    }

    return ret_val;
}