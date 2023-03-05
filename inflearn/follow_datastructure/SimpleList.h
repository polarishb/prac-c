#pragma once

#include <stdbool.h>
#include <stdio.h>

#define MAX 100

struct movie
{
    char title[MAX];
    float rate;
};

typedef struct movie Item;

typedef struct node
{
    Item item;
    struct node* next;
} Node;

typedef struct list
{
    Node* head;
    int size;
} List;

void InitializeList(List* plist);
bool IsEmpty(const List* plist);
bool IsFull(const List* plist);
bool AddItem(Item item, List* plist);
void InsertbyIndex(Item item, List* plist, int index);
void RemoveByIndex(List* plist, int index);
bool InsertItemFront(Item item, List* plist);
bool Find(const List* plist, Item item_to_find, int* index, Item* item_found, bool (*compare_func)(Item a, Item b));

unsigned int CountItems(const List* plist);
unsigned int PrintAllItems(const List* plist, void (*print_an_item_func)(Item item));
unsigned int WriteAllItems(const List* plist, FILE* file, void (*write_an_item_func)(FILE* file, Item item));

void Traverse(const List* plist, void (*pfun)(Item item));
void ClearList(List* plist);

bool FindItemByIndex(const List* plist, const int index, Item ** item);
void RemoveFirstItem(List* plist);