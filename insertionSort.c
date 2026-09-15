#include <stdio.h>

int main() {
    int arr[100]; 
    int size, key, j;
    int i; 

    printf("Enter number of elements: ");
    scanf("%d", &size);
    printf("Enter %d numbers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < size; i++) {
        key = arr[i]; 
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j = j - 1;          
        }
        arr[j + 1] = key; 
    }

    // 4. Print the sorted array
    printf("\nSorted array in ascending order:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
