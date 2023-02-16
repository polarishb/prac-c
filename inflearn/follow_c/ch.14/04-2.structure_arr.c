#include <stdio.h>
#include <string.h>

#define MAX 40
#define MAX_BOOKS 3

struct book
{
    char title[MAX];
    char author[MAX];
    float price;
};

void get_books(struct book*, int);
void print_books(struct book*, int);


int main()
{
    struct book larr[MAX_BOOKS] = {{"","",0.0},};
    
    int count = 0;

    while(1){
        get_books(&larr[count], MAX);
        if(larr[count].title[0] == '\n') break;

        count++;
        if(count == MAX_BOOKS) break;
    }

    print_books(&larr[0], count);    

    return 0;
}

void get_books(struct book *st, int max)
{
    printf("Input a book title or press [Enter] to stop.\n>>");
    fgets(st->title, max, stdin);
    if(st->title[0] == '\n')  return;
    else  for(int i = 0; i < max; i++) st->title[i] = (st->title[i] == '\n') ? '\0' : st->title[i];
    // char* c = strchr(st->title, '\n');
    // *c = '\0';

    printf("Input the author.\n>>");
    fgets(st->author, max, stdin);
    for(int i = 0; i < max; i++) st->author[i] = (st->author[i] == '\n') ? '\0' : st->author[i];

    printf("Input the price.\n>>");
    scanf("%f", &st->price);
    while(getchar() != '\n') continue;
}

void print_books(struct book *st, int count)
{
    printf("The list of books:\n");
    if(count == 0) printf("No books\n");
    else for(int n = 0; n < count; n++) printf("[%d] \"%s\" written by %s: $%.2f\n", n+1, st[n].title, st[n].author, st[n].price);
}
