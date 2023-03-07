#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SimpleList2.h"

bool read_an_item_func(FILE* file, Item* new_item);
void print_an_item(Item item);
bool name_starts_with(Item a, Item b);
bool joined_in(Item a, Item b);
unsigned int ReadFromFile(List* plist, const char* filename,  bool (*read_an_item_func)(FILE* file, Item* item));

int main()
{
    List avengers;

    InitializeList(&avengers);

    const int n_items = ReadFromFile(&avengers, "avengers",  &read_an_item_func);
    printf("%d avengers joind.\n", n_items);

    printf("\nPrint all members\n");
    PrintAllItems(&avengers, &print_an_item);

    printf("\nPrint all members whose names start with \"Black\":\n");
    Item item_to_find;
    strcpy(item_to_find.name, "Black");
    FindAndRun(&avengers, item_to_find, &name_starts_with, &print_an_item);

    printf("\nPrint all members who joined in 1965:\n");
    item_to_find.year = 1965;
    FindAndRun(&avengers, item_to_find, &joined_in, &print_an_item);

    return 0;
}

bool read_an_item_func(FILE* file, Item* new_item)
{
    if (fscanf(file, "%[^\n]%*c", new_item->name) != 1 ||
         fscanf(file, "%d%*c", &new_item->year) != 1){
            return false;
    }
    else return true;
}

void print_an_item(Item item)
{
    printf("\"%s\" joined in %d\n", item.name, item.year);
}

bool name_starts_with(Item a, Item b)
{
    return strncmp(b.name, a.name, strlen(b.name)) == 0;
}

bool joined_in(Item a, Item b)
{
    return a.year == b.year;
}