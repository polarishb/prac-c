#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

struct _Movie {
    char title[MAX];
    float rate;
};

void open_file(char* filename, int* num);
void print_menu(int* num);
int select_menu(int input);
void read_file();
struct _Movie* read_list(const char* filename, int* n);
void print_list(const struct _Movie* lists, int num);

int main()
{
    char tmp[MAX];
    int num = 0;
    int input = 0;
    


    printf("Please input filename to read and press Enter\n>> ");
    scanf("%[^\n]%*c", tmp);

    char* filename = (char*)malloc(strlen(tmp) + 1);
    strcpy(filename, tmp);

    open_file(filename, &num);

    struct _Movie* my_lists = (struct _Movie*)malloc(sizeof(struct _Movie) * num);

    if (!my_lists) {
        printf("Malloc Failed\n");
        exit(EXIT_FAILURE);
    }

    while(1){
        print_menu(&num);
        
        switch (select_menu(input))
        {
        case 1:
            read_list(filename, &num);
            print_list(my_lists, num);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        }

            

    }

    return 0;
}

void open_file(char* filename, int* num)
{
    FILE* fr;

    if ((fr = fopen(filename, "r")) == NULL){
        printf("ERROR: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    int flag = fscanf(fr, "%d%*c", num);

    if (flag != 1){
        printf("ERROR: Read failed.\n");
        exit(EXIT_FAILURE);
    }
    fclose(fr);
}

void print_menu(int* num)
{
    printf("%d items have been read from the file.\n\n", *num);
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
        printf("EORROR: Out of range.\n");
        exit(EXIT_FAILURE);
    }
    else if(input == 10){
        printf("Goodbye.\n");
        exit(EXIT_SUCCESS);
    }

    return input;
}

struct _Movie* read_list(const char* filename, int* n)
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

    struct _Movie* my_lists = (struct _Movie*)malloc(sizeof(struct _Movie) * (*n));
    
    if(!my_lists){
        printf("Malloc() failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *n; i++) {
        flag = fscanf(fr, "%[^\n]%*c%[^\n]%*c", my_lists[i].title, my_lists[i].rate);

        if (flag != 2){
            printf("File read failed\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fr);

    return my_lists;
}

void print_list(const struct _Movie* lists, int num)
{
    for (int i = 0; i < num; i++)
        printf("%d : \"%s\". %d\n", i, lists[i].title, lists[i].rate);
}
