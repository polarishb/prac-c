#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

struct _Movie {
    char title[MAX];
    float rate;
    struct _Movie* next;
};

typedef struct _Movie* p_Movie;

void read_file(p_Movie* p_head)
{
    char filename[MAX] = { 0, };

    printf("Please input filename to read and press Enter. \n>> ");

    if (scanf("%[^\n]%*c", filename) != 1) {
        printf("Wrong input. Terminating. \n");
        exit(EXIT_FAILURE);
    }

    FILE* file = fopen(filename, "r");

    if (file == NULL){
        printf("ERROR: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    int num;
    if (fscanf(file, "%d%*c", &num) != 1){
        printf("ERROR: Wrong file format.");
        exit(EXIT_FAILURE);
    }

    p_Movie prev = *p_head;

    for (int n = 0; n < num; n++){
        p_Movie new_movie = (p_Movie)malloc(sizeof(struct _Movie));
        if (new_movie == NULL){
            printf("ERROR: malloc failed.\n");
            exit(EXIT_FAILURE);
        }

        new_movie->next = NULL;

        if (fscanf(file, "%[^\n]%*c", new_movie->title) != 1 ||
             fscanf(file, "%f%*c", &new_movie->rate) != 1){
                printf("ERROR: Wrong file format.\n");
                exit(EXIT_FAILURE);
        }

        if(prev == NULL){
            *p_head = new_movie;
            prev = new_movie;
        }
        else{
            prev->next = new_movie;
            prev = new_movie;
        }
    }

    fclose(file);
    printf("%d items have been read from the file.\n", num);
}

unsigned int count_items(const p_Movie head)
{
    unsigned int count = 0;
    p_Movie pnode = head;

    while (pnode != NULL) {
        count += 1;
        pnode = pnode->next;
    }

    return count;
}

void write_file(p_Movie head)
{
    char filename[MAX];

    printf("Please input filename to write and press Enter.\n>> ");

    if (scanf("%[^\n]%*c", filename) != 1){
        printf("Wrong input. Terminating.\n");
        exit(EXIT_FAILURE);
    }

    FILE* file = fopen(filename, "w");

    if (file == NULL){
        printf("ERROR: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;

    fprintf(file, "%d\n", (int)count_items(head));

    p_Movie pnode = head;

    while (pnode != NULL){
        fprintf(file, "%s\n", pnode->title);
        fprintf(file, "%.1f\n", pnode->rate);

        pnode = pnode->next;

        count++;
    }

    fclose(file);

    printf("%d items have been saved to the file.\n", count);
}

int input_int()
{
    int input;

    while (1){
        if(scanf("%d%*c", &input) == 1) return input;
        else{
            printf("Please input an integer and press enter. Try again.\n");
            while (getchar() != '\n') continue;
        }
    }
}

int input_menu()
{
    while(1){
        printf("Please select an option adn press enter.\n");
        printf("1. Print all items\t2. Print an item\n");
        printf("3. Edit an item\t\t4. Add an item\n");
        printf("5. Insert an item\t6. Delete an item\n");
        printf("7. Delete all items\t8. Save file\n");
        printf("9. Search by name\t10. Quit\n>> ");

        int input = input_int();

        if(input > 0 && input < 11) return input;
        else
            printf("%d is invalid. Please try again.\n", input);
    }
}

void print_all(p_Movie head)
{
    p_Movie pnode = head;

    int count = 0;
    while (pnode != NULL){
        printf("%d : \"%s\", %.1f\n", count, pnode->title, pnode->rate);
        pnode = pnode->next;
        count++;
    }
}

void print_an_item(p_Movie head)
{
    printf("Input the index of item to print.\n");
    int index = input_int();

    p_Movie pnode = head;

    int count = 0;

    while (pnode != NULL){
        if (count == index) break;

        pnode = pnode->next;
        count++;
    }

    if (pnode != NULL)
        printf("%d : \"%s\", %.1f\n", count, pnode->title, pnode->rate);
    else
        printf("Inavlid item.\n");
}

void edit_an_item(p_Movie head)
{
    printf("Input the index of item to print.\n");
    int index = input_int();

    p_Movie pnode = head;

    int count = 0;

    while (pnode != NULL){
        if (count == index) break;

        pnode = pnode->next;
        count++;
    }

    if (pnode != NULL){
        printf("Input new title and press enter.\n>> ");
        int f = scanf("%[^\n]%*c", pnode->title);
        printf("Input new rating and press enter.\n>> ");
        f = scanf("%f%*c", &pnode->rate);
    }
    else
        printf("Inavlid item.\n");
}

void add_an_item(p_Movie* p_head)
{
    printf("Input title and press enter.\n>> ");

    p_Movie new_movie = (p_Movie)malloc(sizeof(struct _Movie));
    if (new_movie == NULL){
        printf("ERROR: malloc failed.\n");
        exit(EXIT_FAILURE);
    }
    new_movie->next = NULL;

    printf("Input new title and press enter.\n>> ");
    int f = scanf("%[^\n]%*c", new_movie->title);
    printf("Input new rating and press enter.\n>> ");
    f = scanf("%f%*c", &new_movie->rate);

    int count = 0;
    p_Movie pnode = *p_head;

    if (pnode == NULL)
        *p_head = new_movie;
    else{
        while(pnode->next != NULL){
            pnode = pnode->next;
            count++;
        }
        pnode->next = new_movie;
        count++;
    }

    printf("%d : \"%s\", %.1f\n", count, pnode->title, pnode->rate);
}

void insert_item(p_Movie* p_head)
{
    printf("Input the index of item to insert.\n");
    int index = input_int();

    p_Movie pnode = *p_head;
    p_Movie prev = NULL;

    int count = 0;

    while (pnode != NULL){
        if(count == index) break;
        prev = pnode;
        pnode = pnode->next;
        count++;
    }

    if (pnode == NULL){
        printf("Wrong index\n");
        return;
    }

    p_Movie new_movie = (p_Movie)malloc(sizeof(struct _Movie));
    if (new_movie == NULL){
        printf("ERROR: malloc failed.\n");
        exit(EXIT_FAILURE);
    }
    new_movie->next = NULL;

    printf("Input new title and press enter.\n>> ");
    int f = scanf("%[^\n]%*c", new_movie->title);
    printf("Input new rating and press enter.\n>> ");
    f = scanf("%f%*c", &new_movie->rate);

    if (prev == NULL)
        *p_head = new_movie;
    else   
        prev->next = new_movie;
    new_movie->next = pnode;
}

void delete_an_item(p_Movie* p_head)
{
    printf("Input the index of item to delete.\n");
    int index = input_int();

    p_Movie pnode = *p_head;
    p_Movie prev = NULL;
    p_Movie temp;

    int count = 0;

    while (pnode != NULL){
        if(count == index) break;
        prev = pnode;
        pnode = pnode->next;
        count++;
    }

    if (pnode == NULL){
        printf("Wrong index\n");
        return;
    }

    if (prev == NULL)
        *p_head = pnode->next;
    else   
        prev->next = pnode->next;
    free(pnode);
}

void delete_all_items(p_Movie* p_head)
{
    int count = 0;
    p_Movie search = *p_head;

    if (search == NULL){
        printf("Nothing to delete.\n");
        return;
    }

    p_Movie temp = NULL;

    while (*p_head != NULL){
        temp = (*p_head)->next;
        free(*p_head);
        *p_head = temp;
        count++;
    }

    printf("%d items deleted.\n", count);
}

void search_by_name(p_Movie head)
{
    printf("Input title to search and press enter.\n>> ");

    char title[MAX] = { 0, };
    if (scanf("%[^\n]%*c", title) != 1){
        printf("Wrong input.\n");
        return;
    }

    p_Movie pnode = head;

    int count = 0;
    while (pnode != NULL){
        if (strcmp(pnode->title, title) == 0) break;
        pnode = pnode->next;
        count++;
    }

    if (pnode == NULL){
        printf("No movie found : %s", title);
        return;
    }

    printf("%d : \"%s\", %.1f\n", count, pnode->title, pnode->rate);
}

int main()
{
    p_Movie head = NULL;

    read_file(&head);

    while(1)
    {
        printf("\n");

        switch (input_menu())
        {
        case 1:
            print_all(head);
            break;
        case 2:
            print_an_item(head);
            break;
        case 3:
            edit_an_item(head);
            break;
        case 4:
            add_an_item(&head);
            break;
        case 5:
            insert_item(&head);
            break;
        case 6:
            delete_an_items(&head);
            break;
        case 7:
            delete_all_items(&head);
            break;
        case 8:
            write_file(head);
            break;
        case 9:
            search_by_name(head);
            break;
        case 10:
            printf("Goodbye\n");
            delete_all_items(&head);
            return 0;
        }
    }

    return 0;
}