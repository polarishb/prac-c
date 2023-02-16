#include <stdio.h>
#include <string.h>

void swap(char** xp, char** yp);
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);
void selectionSortR(char* arr[], int n);

int main() {

    char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
    int n = sizeof(arr) / sizeof(arr[0]);

    printStringArray(arr, n);

    selectionSort(arr, n);  // ascending order

    printStringArray(arr, n);

    return 0;
}

void swap(char** xp, char** yp){
    char* temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printStringArray(char* arr[], int size){
   int i;
   for (i = 0; i < size; i++){
      printf("%s ", arr[i]);
   }
   printf("\n");
}

void selectionSort(char* arr[], int n){
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++){
        min_idx = i;
        for(j = i + 1; j < n; j++){ 
            if(strcmp(arr[min_idx], arr[j]) > 0){
                min_idx = j;
            }         
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void selectionSortR(char* arr[], int n){
   int i, j, max_idx;

   for (i = 0; i < n - 1; i++){
      max_idx = i;
      for(j = i + 1; j < n; j++){
         if(arr[max_idx] < arr[j]){
            max_idx = j;
         }         
      }
      swap(&arr[i], &arr[max_idx]);
   }
}