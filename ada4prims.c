#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int n) {
    int total = 0;
    printf("\nEdges in the MST:\n");
    printf("Edge\tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total cost of MST = %d\n", total);
}

void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    // Step 1: Initialize all keys as infinite
    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Step 2: Always include first vertex in MST
    key[0] = 0;
    parent[0] = -1;

    // Step 3: Find MST for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;

        // Update key values for neighbors
        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, graph, n);
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph, n);

    return 0;
}
