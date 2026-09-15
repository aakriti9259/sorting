#include <stdio.h>
int getMax(int arr[], int size) {
    int max = arr[0];
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void countingSort(int arr[], int size, int exp) {
    int output[100];
    int count[10] = {0}; 
    int i;
    for (i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int size) {
    int max = getMax(arr, size);
    int exp;

    for (exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, size, exp);
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

    radixSort(arr, size);
    printf("\nSorted array in ascending order:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
