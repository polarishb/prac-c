#include "SimpleList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(List* plist)
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

    for (int n = 0; n < num; n++){
        
        Item new_item;

        if (fscanf(file, "%[^\n]%*c", new_item.title) != 1 ||
             fscanf(file, "%f%*c", &new_item.rate) != 1){
                printf("ERROR: Wrong file format.\n");
                exit(EXIT_FAILURE);
        }

        AddItem(new_item, plist);
    }

    fclose(file);
    printf("%d items have been read from the file.\n", num);
}

unsigned int count_items(const List* const plist)
{
    return CountItems(plist);
}

void write_an_item(FILE* const file, const Item item)
{
    fprintf(file, "%s\n", item.title);
    fprintf(file, "%.1f\n", item.rate);
}

void write_file(const List* const plist)
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

    unsigned int num = CountItems(plist);

    fprintf(file, "%d\n", num);

    unsigned int count = WriteAllItems(plist, file, &write_an_item);

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

void print_an_item(Item item)
{
    printf("\"%s\", %.1f\n", item.title, item.rate);
}

void print_all(const List* plist)
{
    PrintAllItems(plist, print_an_item);
}

void find_and_print_an_item(const List* const plist)
{
    printf("Input the index of item to print.\n");
    int index = input_int();

    Item *pitem;
    const int flag = FindItemByIndex(plist, index, &pitem);

    if (flag == true){
        printf("%d : ", index);
        print_an_item(*pitem);
    }
    else
        printf("Inavlid item.\n");
}

void edit_an_item(List* plist)
{
    printf("Input the index of item to print.\n");
    int index = input_int();

    Item* pitem;
    const bool flag = FindItemByIndex(plist, index, &pitem);

    if (flag == true){
        Item new_item;
        printf("Input new title and press enter.\n>> ");
        int f = scanf("%[^\n]%*c", new_item.title);
        printf("Input new rating and press enter.\n>> ");
        f = scanf("%f%*c", &new_item.rate);

        *pitem = new_item;
    }
    else
        printf("Inavlid item.\n");
}

void add_an_item(List* plist)
{
    printf("Input title and press enter.\n>> ");

    Item new_item;

    printf("Input new title and press enter.\n>> ");
    int f = scanf("%[^\n]%*c", new_item.title);
    printf("Input new rating and press enter.\n>> ");
    f = scanf("%f%*c", &new_item.rate);

    AddItem(new_item, plist);

    printf("%d : \"%s\", %.1f\n", CountItems(plist) - 1, new_item.title, new_item.rate);
}

void insert_item(List* plist)
{
    printf("Input the index of item to insert.\n");
    int index = input_int();

    Item* pitem;
    const bool flag = FindItemByIndex(plist, index, &pitem);

    if (flag == false){
        printf("Wrong index\n");
        return;
    }

    Item new_item;

    printf("Input new title and press enter.\n>> ");
    int f = scanf("%[^\n]%*c", new_item.title);
    printf("Input new rating and press enter.\n>> ");
    f = scanf("%f%*c", &new_item.rate);

    InsertbyIndex(new_item, plist, index);
}

void delete_an_item(List* plist)
{
    printf("Input the index of item to delete.\n");
    int index = input_int();

    Item* pitem;
    const bool flag = FindItemByIndex(plist, index, &pitem);

    if (flag == false){
        printf("Wrong index\n");
        return;
    }

    RemoveByIndex(plist, index);
}

void delete_all_items(List* plist)
{
    ClearList(plist);
}

bool compare_items(Item a, Item b)
{
    if (strcmp(a.title, b.title) == 0)
        return true;
    else  
        return false;
}

void search_by_name(const List* plist)
{
    printf("Input title to search and press enter.\n>> ");

    Item item_to_find;
    char title[MAX] = { 0, };
    if (scanf("%[^\n]%*c", item_to_find.title) != 1)
    {
        printf("Wrong input.\n");
        return;
    }

    Item item_found;
    int index;
    if (Find(plist, item_to_find, &index, &item_found, compare_items) == 1){
        printf("No movie found : %s", item_to_find.title);
        return;
    }
    else
        printf("%d : \"%s\", %.1f\n", index, item_found.title, item_found.rate);
}

int main()
{
    List movie_list;

    InitializeList(&movie_list);

    read_file(&movie_list);

    while(1)
    {
        printf("\n");

        switch (input_menu())
        {
        case 1:
            print_all(&movie_list);
            break;
        case 2:
            find_and_print_an_item(&movie_list);
            break;
        case 3:
            edit_an_item(&movie_list);
            break;
        case 4:
            add_an_item(&movie_list);
            break;
        case 5:
            insert_item(&movie_list);
            break;
        case 6:
            delete_an_item(&movie_list);
            break;
        case 7:
            delete_all_items(&movie_list);
            break;
        case 8:
            write_file(&movie_list);
            break;
        case 9:
            search_by_name(&movie_list);
            break;
        case 10:
            printf("Goodbye\n");
            delete_all_items(&movie_list);
            return 0;
        }
    }

    return 0;
}