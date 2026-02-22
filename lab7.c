#include <stdio.h>
int binarySearch(int arr[], int key, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid + 1;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];

        int pos = binarySearch(arr, key, 0, i - 1);

    
        int j = i - 1;
        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }

        
        arr[pos] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 4, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    binaryInsertionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}