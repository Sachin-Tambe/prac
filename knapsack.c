#include <stdio.h>

struct Item {
    int weight;
    int value;
    double ratio;
};

int main() {
    int n, capacity;
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    struct Item items[n];
    
    printf("Enter weight and value for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    
    printf("\nEnter knapsack capacity: ");
    scanf("%d", &capacity);
    
    printf("\nValue/Weight Ratios:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: %.2f\n", i + 1, items[i].ratio);
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    
    printf("\nSorted by Ratio (Descending):\n");
    for (int i = 0; i < n; i++) {
        printf("Item: Weight=%d, Value=%d, Ratio=%.2f\n", 
               items[i].weight, items[i].value, items[i].ratio);
    }
    
    double totalValue = 0.0;
    int currentWeight = 0;
    
    printf("\nKnapsack Filling:\n");
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Taking full item: Weight=%d, Value=%d\n", 
                   items[i].weight, items[i].value);
        } else {
            int remaining = capacity - currentWeight;
            if (remaining > 0) {
                double fraction = (double)remaining / items[i].weight;
                totalValue += items[i].value * fraction;
                printf("Taking %.2f%% of item: Weight=%d, Value=%.2f\n", 
                       fraction * 100, remaining, items[i].value * fraction);
                currentWeight = capacity;
            }
            break;
        }
    }
    
    printf("\nMaximum value: %.2f\n", totalValue);
    
    return 0;
}
