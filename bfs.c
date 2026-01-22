#include <stdio.h>

#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

int dequeue() {
    int value = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;
    }
    return value;
}

int isEmpty() {
    return front == -1;
}

void bfs(int graph[][MAX], int n, int start) {
    int visited[MAX] = {0};
    
    printf("\nBFS Traversal starting from node %d:\n", start);
    printf("%d", start);
    
    visited[start] = 1;
    enqueue(start);
    
    while (!isEmpty()) {
        int current = dequeue();
        
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                printf(" -> %d", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;
    int graph[MAX][MAX];
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("\nEnter adjacency matrix (%d x %d):\n", n, n);
    printf("(Enter 1 if edge exists, 0 otherwise)\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    printf("\nEnter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);
    
    bfs(graph, n, start);
    
    return 0;
}
