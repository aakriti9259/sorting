#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 
    int j;

    for (j = low; j < high; j++) {
      
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); 
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[100]; 
    int size, i;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter %d numbers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, size - 1);

    printf("\nSorted array in ascending order:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
