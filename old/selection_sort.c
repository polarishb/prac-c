#include <stdio.h>

/*
    64 25 12 22 11 (min_idx = 0)
       64          (min_idx = 0)
       25          (min_idx = 1)
          25       (min_idx = 1)
          12       (min_idx = 2)
             12    (min_idx = 2)
                12 (min_idx = 2)
                11 (min_idx = 4)
    11 25 12 22 64 (swap arr[0] and arr[4])

    11 25 12 22 64
          25       (min_idx = 1)
          12       (min_idx = 2)
             12    (min_idx = 2)
                12 (min_idx = 2)
    11 12 25 22 64 (swap arr[1] and arr[2])

    11 12 26 22 64 (min_idx = 2)
    ...
    11 12 22 25 64 (min_idx = 3)
    ...
*/

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);
void selectionSortR(int arr[], int n);

int main() {

   int arr[] = { 64, 25, 12, 22, 11 };
   int n = sizeof(arr) / sizeof(arr[0]);

   selectionSort(arr, n);  // ascending order

   printArray(arr, n);

    return 0;
}

void swap(int* xp, int* yp){
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}

void printArray(int arr[], int size){
   int i;
   for (i = 0; i < size; i++){
      printf("%d ", arr[i]);
   }
   printf("\n");
}

void selectionSort(int arr[], int n){
   int i, j, min_idx;

   // One by one move boundary of unsorted subarray
   for (i = 0; i < n - 1; i++){
      // Find the minimum elemnt in unsorted array
      // TODO: fill blank(s)
      min_idx = i;
      for(j = i + 1; j < n; j++){ // Note i + 1
         //TODO: fill blank(s)
         if(arr[min_idx] > arr[j]){
            min_idx = j;
         }         
      }
      //Swap the found minimum element with the first element
      // TODO: fill blank(s)
      swap(&arr[i], &arr[min_idx]);
   }
}

void selectionSortR(int arr[], int n){
   int i, j, max_idx;

   // One by one move boundary of unsorted subarray
   for (i = 0; i < n - 1; i++){
      // Find the minimum elemnt in unsorted array
      // TODO: fill blank(s)
      max_idx = i;
      for(j = i + 1; j < n; j++){ // Note i + 1
         //TODO: fill blank(s)
         if(arr[max_idx] < arr[j]){
            max_idx = j;
         }         
      }
      //Swap the found minimum element with the first element
      // TODO: fill blank(s)
      swap(&arr[i], &arr[max_idx]);
   }
}