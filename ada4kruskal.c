#include <stdio.h>

#define MAX 100
struct Edge {
    int u, v, w;
};
int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}
void unionSets(int parent[], int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);
    parent[rootY] = rootX;
}
void kruskal(struct Edge edges[], int n, int e) {
    int parent[MAX];
    int totalCost = 0;
    int i, j, count = 0;

    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    // Pick the smallest edges and build MST
    for (i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);
        //no cycle formed
        if (parentU != parentV) {
            printf("%d - %d : %d\n", u, v, w);
            totalCost += w;
            unionSets(parent, parentU, parentV);
            count++;
        }
    }

    printf("\nTotal cost of MST = %d\n", totalCost);
}

int main() {
    struct Edge edges[MAX];
    int n, e, i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v w):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal(edges, n, e); 
    return 0;
}
