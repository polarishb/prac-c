#include <stdio.h>
#include <string.h>

void fit_str(char*, unsigned int);
void my_strcat(char*, char*);
int my_strcmp(char*, char*);
int my_strncmp(char*, char*, int);

int main()
{
    // char msg[] = "Just,"" do it!";
    // puts(msg);
    // printf("Length %ld\n", strlen(msg));
    // fit_str(msg, 4);
    // puts(msg);
    // printf("Length %ld\n", strlen(msg));

    // char str1[100] = "First string";
    // char str2[] = "Second string";

    // my_strcat(str1, ", ");
    // my_strcat(str1, str2);
    // puts(str1);

    // printf("%d\n", my_strcmp("A", "A"));
    // printf("%d\n", my_strcmp("A", "B"));
    // printf("%d\n", my_strcmp("B", "A"));
    // printf("%d\n", my_strcmp("Hello", "Hello"));
    // printf("%d\n", my_strcmp("Banana", "Bananas"));
    // printf("%d\n", my_strcmp("Bananas", "Banana"));
    // printf("%d\n", my_strncmp("Bananas", "Banana", 6));

    char dest[100] = "";
    char source[] = "Start programming!";
    // dest = source; // Error
    // dest = "Start something"; // Error
    strcpy(dest, source);
    strncpy(dest, source, 5); // '\0' is NOT added
    strcpy(dest, source + 6);
    strcpy(dest, source);
    strcpy(dest + 6, "coding!");
    puts(dest);

    return 0;
}

void fit_str(char* str, unsigned int size)
{
    // while(*str)
    //     *(str++ + size) = '\0';

    if (strlen(str) > size)
        str[size] = '\0';
}

void my_strcat(char* str1, char* str2)
{
    // char* ptr = str1 + strlen(str1);

    // while(*str2)
    //     *ptr++ = *str2++;

    for(int i = 0; i < strlen(str2); i++){
        str1[strlen(str1)] = str2[i];
    }

    // while(*str2)
    //     *(str1 + strlen(str1)) = *str2++;
}

int my_strcmp(char* str1, char* str2)
{
    while(*str1 != '\0' || *str2 != '\0'){
        if(*str1 > *str2)
            return 1;
        else if (*str1 < *str2)
            return -1;

        str1++;
        str2++;
    }

    return 0;    
}

int my_strncmp(char* str1, char* str2, int size)
{
        for(int i = 0; i < size; i++){
            if(*str1 > *str2)
                return 1;
            else if (*str1 < *str2)
                return -1;

        str1++;
        str2++;
        }

    return 0;    
}