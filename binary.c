#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        printf("Searching [%d, %d], mid=%d, value=%d\n", left, right, mid, arr[mid]);
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] > target) {
            printf("Searching left half\n");
            return binarySearch(arr, left, mid - 1, target);
        }
        
        printf("Searching right half\n");
        return binarySearch(arr, mid + 1, right, target);
    }
    
    return -1;
}

int main() {
    int n, target;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements in SORTED order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nArray: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("\nEnter element to search: ");
    scanf("%d", &target);
    
    printf("\nSearch Process:\n");
    int result = binarySearch(arr, 0, n - 1, target);
    
    printf("\nResult:\n");
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found\n", target);
    }
    
    return 0;
}
