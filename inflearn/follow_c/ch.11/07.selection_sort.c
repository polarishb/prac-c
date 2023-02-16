#include <stdio.h>

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main()
{
    int num_arr[] = { 64, 25, 12, 22, 11};
    int n = sizeof(num_arr) / sizeof(num_arr[0]);

    printArray(num_arr, n);
    selectionSort(num_arr, n);
    printArray(num_arr, n);
    
    return 0;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int arr[], int n)
{
    // while(*arr)
    // {
    //     int min_idx = 0;
    //     for(int i = 0; i < n; i++){
    //         if(arr[min_idx] > arr[i])
    //             min_idx = i;
    //     }
    //     swap(&arr[0], &arr[min_idx]);
    //     arr++;
    //     n--;
    // }

    for(int j = 0; j < n; arr++ && n--)
    {
        int min_idx = 0;
        for(int i = 0; i < n; i++){
            if(arr[min_idx] > arr[i])
                min_idx = i;
        }
        swap(&arr[0], &arr[min_idx]);
    }

    // for (int i = 0; i < n - 1; i++){
    //     int min_idx = i;
    //     for (int j = i + 1; j < n; j++){
    //         if(arr[j] < arr[min_idx])
    //             min_idx = j;
    //     }
    //     swap(&arr[min_idx], &arr[i]);
    // }
}