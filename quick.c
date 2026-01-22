#include <stdio.h>

int pass_count = 0;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        pass_count++;
        printf("\nPass %d (Pivot: %d at position %d)\n", pass_count, arr[pi], pi);
        printf("Array: ");
        printArray(arr, n);
        
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

int main() {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal Array: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1, n);
    
    printf("\nFinal Sorted Array: ");
    printArray(arr, n);
    printf("Total Partitions: %d\n", pass_count);
    
    return 0;
}
