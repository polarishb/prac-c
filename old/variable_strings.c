#include <stdio.h>
#include <string.h>

void fit_str(char*, unsigned int);
void my_strcat(char*, char*);
char* my_strcat2(char*, char*);
int my_strcmp(char*, char*);
int my_strcmp2(char*, char*);

int main(){
    // char msg[] = "Just,"" do it!";
    // puts(msg);
    // printf("Length %ld\n", strlen(msg));
    // fit_str(msg, 4);
    // puts(msg);
    // printf("Length %ld\n", strlen(msg));

    /* 
        strcat() and strncat() : string concatenation
    */

    // char str1[100] = "First string";
    // char str2[] = "Second string";
    
    // my_strcat2(str1, ", ");
    // my_strcat2(str1, str2);
    // // strncat(str1, str2, 2); // Append 2 characters
    // puts(str1);

    //TODO: implement my_strcat() function;

    /*
        strcmp() and strncmp() : compare strings (not characters)
    */

    printf("%d\n", my_strcmp("A", "A"));
    printf("%d\n", my_strcmp("A", "B"));
    printf("%d\n", my_strcmp("B", "A"));
    printf("%d\n", my_strcmp("Hello", "Bye"));
    printf("%d\n", my_strcmp("Banana", "Bananas"));
    printf("%d\n", my_strcmp("Bananas", "Banana"));
    printf("%d\n", strncmp("Bananas", "Banana", 6));
    //TODO: implement strcmp()

    /*
        strcpy() and strncpy()
    */

    // char dest[100] = "";    // make sure memory is enough
    // char source[] = "Start programming!";
    // //dest = source;    // Error
    // //dest = "Start something!";    // Error
    // strcpy(dest, source);
    // strncpy(dest, source, 5);   // '\0' is NOT added
    // strcpy(dest, source + 6);
    // strcpy(dest, source);
    // strcpy(dest + 6, "coding!");
    // puts(dest);

    /*
        sprintf()
    */
    
    // char str[100] = "";
    // int i = 123;
    // double d= 3.14;
    // sprintf(str, "%05d.png %f", i, d);
    // puts(str);

    /*
        and more...
    */

    // printf("%s\n", strchr("Hello, World", 'W'));

    // printf("%s\n", strpbrk("Hello, World", "ABCDE"));
    // printf("%s\n", strpbrk("Hello, World", "abcde"));

    // printf("%s\n", strrchr("Hello, World, Hello, World", 'l'));  // last occurrence

    // printf("%s\n", strstr("Hello, World", "wor"));
    // printf("%s\n", strstr("Hello, World", "Wor"));

    return 0; 
}

void fit_str(char* str, unsigned int size){
    // for(int i = 0; i < sizeof(str); i++){
    //     if(i >= size){
    //         str[i] = '\0';
    //     }
    // }

    if(strlen(str) > size)  // After '\0' terminate
        str[size] = '\0';
}

void my_strcat(char* str1, char* str2){    
    int count = 0;
    for(int i = 0; i < strlen(str1); i++){
        if( str1[i] == '\0'){
            break;
        }
        count++;
    }

    for(int i = 0; i < strlen(str1); i++){
        str1[i+count] = str2[i];
    }
}

char* my_strcat2(char* str1, char* str2){
    char* ptr = str1 + strlen(str1);
    while(*str2){
        *ptr++ = *str2++;
    }

    *ptr = '\0';

    return str1;
}

int my_strcmp(char* str1, char* str2){
    while(*str1 || *str2){
        if(*str1 > *str2){
            return 1;
        }            
        else if(*str1 < *str2){
            return -1;
        }
        str1++;
        str2++;            
    }

    return 0;
}

int my_strcmp2(char* str1, char* str2){
    while(*str1){
        if(*str1 != *str2)
            break;
        *str1++;
        *str2++;      
    }

    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}