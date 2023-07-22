#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int binarySearch(int arr[], int n, int target);
void swap(int* a, int*b);
void insertionSort(int arr[], int n);

int main(){
    int n; // Size of the array
    int max_value; // Maximum possible element in the array
    int x;

    printf("Enter the size of the array:");
    scanf("%d", &n);

    printf("Enter the maximum possible element in the array:");
    scanf("%d", &max_value);

    // Set the seed for the rand() function based on the current time
    srand(time(0));

    // Create and generate random integers for the array
    int array[n];
    for (int i = 0; i < n; i++) {
        array[i] = rand() % max_value; // Generate a random number in the range [0, max_value-1]
    }

    printf("Random integer array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    insertionSort(array, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Enter the number you want to search for in the array:");
    scanf("%d", &x);

    int index = binarySearch(array, n, x);

    if (index != -1) {
        printf("The element %d is found at position %d.\n", x, index + 1);
    } else {
        printf("The element %d is not found in the array.\n", x);
    }


    return 0;
}

int binarySearch(int arr[], int n, int target){
    int left = 1;
    int right = n;
    int i;
    while (left <= right){
        i = (left + right)/2;
        if (target == arr[i]) {
            return i;
        }else if (target < arr[i]){
            right = i - 1;
        } else{
            left = i + 1;
        }
    }
    return -1;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int *arr, int n){
    for (int i = 1; i < n; i++) {
        int newElement = arr[i];
        int location = i - 1;
        while ((location >= 0) && (arr[location] > newElement)){
            swap(&arr[location], &arr[location + 1]);
            location -= 1;
        }
    }
}