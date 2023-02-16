#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

struct person
{
    char name[MAX];
    int age;
    float height;
};

int main()
{
    int flag;

    struct person genie;

    strcpy(genie.name, "Will Smith");

    genie.age = 1000;

    flag = scanf("%f", &genie.height);
    printf("%f\n", genie.height);

    struct person princess = { "Naomi  Scott", 18, 160.0f };

    struct person princess2 = {
        "Naomi Scott",
        18,
        160.0f
    };

    strcpy(princess.name, "Naomi Scott");
    princess.age = 18;
    princess.height = 160.0f;

    struct person beauty = {
        .age = 19,
        .name = "Bell",
        .height = 150.0f
    };

    struct person* someone;

    someone = &genie;

    someone->age = 1001;
    printf("%s %d\n", someone->name, (*someone).age);

    struct book
    {
        char title[MAX];
        float price;
    };

    struct {
        char farm[MAX];
        float price;
    } apple, apple2;

    strcpy(apple.farm, "Tarde Joe");
    apple.price = 1.2f;
    
    strcpy(apple2.farm, "Safeway");
    apple2.price = 5.6f;

    typedef struct person my_person;

    my_person p3;

    typedef struct person person;

    person p4;

    typedef struct {

    } friend;

    friend p5;
    
    return 0;    
}