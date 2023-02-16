#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

#define SLEN 101

struct book
{
    char name[SLEN];
    char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);
struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** books_dptr, int* n);

int main()
{
    int temp;
    int n = 3;

    struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);

    if (!my_books) {
        printf("Malloc Failed\n");
        exit(EXIT_FAILURE);
    }

    my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
    my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
    my_books[2] = (struct book){ "The Odyssey", "Homer" };

    print_books(my_books, 3);

    printf("\nWriting to a file.\n");
    write_books("books", my_books, n);
    free(my_books);
    n = 0;
    printf("Done.\n");

    printf("\nPress any key to read data from a file.\n\n");
    temp = getchar();

    // my_books = read_books("books", &n);
    read_books2("books", &my_books, &n);
    print_books(my_books, n);
    free(my_books);
    n = 0;

    return 0;
}

void print_books(const struct book* books, int n)
{
    for (int i = 0; i < n; i++)
        printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books[i].name, books[i].author);
}

void write_books(const char* filename, const struct book* books, int n)
{
    FILE* fw;

    if ((fw = fopen(filename, "w")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(fw, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(fw, "%s\n%s\n", books[i].name, books[i].author);

    fclose(fw);
}

struct book* read_books(const char* filename, int* n)
{
    FILE* fr;

    if ((fr = fopen(filename, "r")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int flag = fscanf(fr, "%d%*c", n);
    if(flag != 1){
        printf("File read failed\n");
        exit(EXIT_FAILURE);
    }

    struct book* my_books = (struct book*)malloc(sizeof(struct book) * (*n));

    if(!my_books){
        printf("Malloc() failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *n; i++) {
        flag = fscanf(fr, "%[^\n]%*c%[^\n]%*c", my_books[i].name, my_books[i].author);

        if (flag != 2){
            printf("File read failed\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fr);

    return my_books;
}

void read_books2(const char* filename, struct book** books_dptr, int* n)
{
    FILE* fr;

    if ((fr = fopen(filename, "r")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int flag = fscanf(fr, "%d%*c", n);
    if(flag != 1){
        printf("File read failed\n");
        exit(EXIT_FAILURE);
    }

    struct book* my_books = (struct book*)malloc(sizeof(struct book) * (*n));

    if(!my_books){
        printf("Malloc() failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *n; i++) {
        flag = fscanf(fr, "%[^\n]%*c%[^\n]%*c", my_books[i].name, my_books[i].author);

        if (flag != 2){
            printf("File read failed\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fr);

    *books_dptr = my_books;
}