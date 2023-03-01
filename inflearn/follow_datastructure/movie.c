#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

struct _Movie {
    char title[MAX];
    float rate;
};

void open_file(char* filename, size_t* num);
void print_menu(size_t* num);
int select_menu(int input);
struct _Movie* read_list(const char* filename, size_t* num);
void print_list(const struct _Movie* lists, size_t num);
void print_item(const struct _Movie* lists, size_t num);
void edit_item(struct _Movie* lists, size_t num);
void add_item(struct _Movie* lists, size_t* num);
void insert_item(struct _Movie* lists, size_t* num);
void delete_item(struct _Movie* lists, size_t* num);
void delete_all(struct _Movie* lists, size_t* num);
void save_file(char* filename, const struct _Movie* lists,size_t num);
void search_item(const struct _Movie* lists, size_t num);

int main()
{
    char tmp[MAX];
    // int num = 0;
    size_t n_items = 0;
    int input = 0;

    printf("Please input filename to read and press Enter\n>> ");
    scanf("%[^\n]%*c", tmp);

    char* filename = (char*)malloc(strlen(tmp) + 1);
    strcpy(filename, tmp);

    open_file(filename, &n_items);

    struct _Movie* my_lists = (struct _Movie*)malloc(sizeof(struct _Movie) * n_items);

    my_lists = read_list(filename, &n_items);
    while(1){
        print_menu(&n_items);
        switch (select_menu(input))
        {
        case 1:
            print_list(my_lists, n_items);
            break;
        case 2:
            print_item(my_lists, n_items);
            break;
        case 3:
            edit_item(my_lists, n_items);
            break;
        case 4:
            add_item(my_lists, &n_items);
            break;
        case 5:
            insert_item(my_lists, &n_items);
            break;
        case 6:
            delete_item(my_lists, &n_items);
            break;
        case 7:
            delete_all(my_lists, &n_items);
            break;
        case 8:
            save_file(filename, my_lists, n_items);
            break;
        case 9:
            search_item(my_lists, n_items);
            break;
        }
    }
    
    free(filename);
    free(my_lists);

    return 0;
}

void open_file(char* filename, size_t* num)
{
    FILE* fr;

    if ((fr = fopen(filename, "r")) == NULL){
        printf("ERROR: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    int flag = fscanf(fr, "%zu%*c", num);

    if (flag != 1){
        printf("ERROR: Read failed.\n");
        exit(EXIT_FAILURE);
    }
    fclose(fr);

    printf("%zu items have been read from the file.\n\n", *num);
}

void print_menu(size_t* num)
{
    printf("Please select an option adn press enter.\n");
    printf("1. Print all items\t2. Print an item\n");
    printf("3. Edit an item\t\t4. Add an item\n");
    printf("5. Insert an item\t6. Delete an item\n");
    printf("7. Delete all items\t8. Save file\n");
    printf("9. Search by name\t10. Quit\n>> ");
}

int select_menu(int input)
{
    scanf("%d", &input);
    while(getchar() != '\n');
    if(input < 1 || input > 11){
        printf("ERROR: Out of range.\n\n");
        return 0;
    }
    else if(input == 10){
        printf("Goodbye.\n");
        exit(EXIT_SUCCESS);
    }

    return input;
}

struct _Movie* read_list(const char* filename, size_t* n)
{
    FILE* fr = fopen(filename, "r");

    int flag = fscanf(fr, "%zu%*c", n);
    if(flag != 1){
        printf("File read failed\n");
        exit(EXIT_FAILURE);
    }

    struct _Movie* my_lists = (struct _Movie*)malloc(sizeof(struct _Movie) * (*n));
    
    if(!my_lists){
        printf("Malloc() failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *n; i++) {
        flag = fscanf(fr, "%[^\n]%*c%f%*c", my_lists[i].title, &(my_lists[i].rate));

        if (flag != 2){
            printf("File read failed\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fr);

    return my_lists;
}

void print_list(const struct _Movie* lists, size_t num)
{
    for (int i = 0; i < num; i++)
        printf("%d : \"%s\", %.1f\n", i, lists[i].title, lists[i].rate);
    printf("\n");
}

void print_item(const struct _Movie* lists, size_t num)
{
    printf("Input the index of item to print.\n>> ");
    int i;
    scanf("%d%*c", &i);
    if(i < 0 || i >= num){
        printf("ERROR: Out of range.\n\n");
        return;
    }
    printf("%d : \"%s\", %.1f\n\n", i, lists[i].title, lists[i].rate);
}

void edit_item(struct _Movie* lists, size_t num)
{
    printf("Input the index of item to edit.\n>> ");
    int i;
    scanf("%d%*c", &i);
    if(i < 0 || i >= num){
        printf("ERROR: Out of range.\n\n");
        return;
    }

    printf("Input new title and press enter.\n>> ");
    scanf("%[^\n]%*c", lists[i].title);
    printf("Input new rating and press enter.\n>> ");
    scanf("%f%*c", &(lists[i].rate));
    printf("\n");
}

void add_item(struct _Movie* lists, size_t *num)
{
    lists = realloc(lists, sizeof(struct _Movie) * (*num+1));

    printf("Input new title and press enter.\n>> ");
    scanf("%[^\n]%*c", lists[*num].title);
    printf("Input new rating and press enter.\n>> ");
    scanf("%f%*c", &(lists[*num].rate));

    *num += 1;

    printf("%zu : \"%s\", %.1f\n\n", *num, lists[*num].title, lists[*num].rate);
}

void insert_item(struct _Movie* lists, size_t* num)
{
    printf("Input the index of item to insert.\n>> ");
    int i;
    scanf("%d%*c", &i);
    if(i < 0 || i > *num){
        printf("ERROR: Out of range.\n\n");
        return;
    }

    lists = realloc(lists, sizeof(struct _Movie) * (*num+1));
    memcpy(&lists[i+1], &lists[i], sizeof(struct _Movie) * (*num+1 - i));

    printf("Input title and press enter.\n>> ");
    scanf("%[^\n]%*c", lists[i].title);
    printf("Input rating and press enter.\n>> ");
    scanf("%f%*c", &(lists[i].rate));
    printf("\n");

    *num += 1;
}

void delete_item(struct _Movie* lists, size_t* num)
{
    printf("Input the index of item to delete.\n>> ");
    int i;
    scanf("%d%*c", &i);
    if(i < 0 || i > *num){
        printf("ERROR: Out of range.\n\n");
        return;
    }

    memcpy(&lists[i], &lists[i+1], sizeof(struct _Movie) * (*num-1 - i));
    lists = realloc(lists, sizeof(struct _Movie) * (*num-1));

    *num -= 1;
}

void delete_all(struct _Movie* lists, size_t* num)
{
    lists = realloc(lists, sizeof(struct _Movie) * (0));

    *num = 0;
}

void save_file(char* filename, const struct _Movie* lists,size_t num)
{
    char tmp[MAX];
    printf("Please input filename to write and press Enter\n>> ");
    scanf("%[^\n]%*c", tmp);

    filename = realloc(filename, strlen(tmp) + 1);
    strcpy(filename, tmp);

    FILE* fw;

    if ((fw = fopen(filename, "w")) == NULL){
        printf("ERROR: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fw, "%zu\n", num);
    for (int i = 0; i < num; i++)
        fprintf(fw, "%s\n%.1f\n", lists[i].title, lists[i].rate);

    printf("%zu items have been saved to the file\n\n", num);

    fclose(fw);
}

void search_item(const struct _Movie* lists, size_t num)
{
    char buf[MAX];
    printf("Input title to search and press enter.\n>> ");
    scanf("%[^\n]%*c", buf);
    int flag = 0;
    for(int i = 0; i < num; i++){
        if(strcmp(buf, lists[i].title))
            printf("%d : \"%s\", %.1f\n", i, lists[i].title, lists[i].rate);
            flag++;
    }
    if(flag == 0)
        printf("No movie found : %s\n", buf);    
    printf("\n");
}