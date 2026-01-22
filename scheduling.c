#include <stdio.h>

void sortTasksByServiceTime(int service[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (service[j] > service[j + 1]) {
                int temp = service[j];
                service[j] = service[j + 1];
                service[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    
    int service[n], waiting[n], turnaround[n];
    
    printf("Enter service time for each task:\n");
    for (int i = 0; i < n; i++) {
        printf("Task %d: ", i + 1);
        scanf("%d", &service[i]);
    }
    
    printf("\nOriginal Service Times: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", service[i]);
    }
    
    sortTasksByServiceTime(service, n);
    
    printf("\nSorted Service Times (Shortest Job First): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", service[i]);
    }
    
    waiting[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + service[i - 1];
    }
    
    for (int i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + service[i];
    }
    
    printf("\n\nTask\tService Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, service[i], waiting[i], turnaround[i]);
    }
    
    int totalWaiting = 0, totalTurnaround = 0;
    for (int i = 0; i < n; i++) {
        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];
    }
    
    printf("\nTotal Waiting Time: %d\n", totalWaiting);
    printf("Average Waiting Time: %.2f\n", (float)totalWaiting / n);
    printf("Total Turnaround Time: %d\n", totalTurnaround);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaround / n);
    
    return 0;
}
