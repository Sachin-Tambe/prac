#include <stdio.h>

#define MAX 20

int visited[MAX];

void dfs(int graph[][MAX], int n, int node) {
    printf("%d ", node);
    visited[node] = 1;
    
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            printf("-> ");
            dfs(graph, n, i);
        }
    }
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
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    printf("\nEnter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);
    
    printf("\nDFS Traversal starting from node %d:\n", start);
    dfs(graph, n, start);
    printf("\n");
    
    return 0;
}
