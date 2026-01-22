#include <stdio.h>

int main() {
    int n, comparisons = 0, swaps = 0;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
    
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("\nTotal Comparisons: %d\n", comparisons);
    printf("Total Swaps: %d\n", swaps);
    
    return 0;
}
