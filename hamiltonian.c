#include <stdio.h>

#define V 5     // number of vertices in graph

int graph[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int path[V];

int isSafe(int v, int pos) {
    // Check if v is adjacent to previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    // Check if v is already taken
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return 0;
    }

    return 1;
}

int hamCycleUtil(int pos) {

    // Base case: if all vertices are in path
    if (pos == V) {
        // Check if last vertex connects to the first
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }

    // Try all vertices except 0 (start fixed)
    for (int v = 1; v < V; v++) {

        if (isSafe(v, pos)) {
            path[pos] = v;

            if (hamCycleUtil(pos + 1))
                return 1;

            path[pos] = -1;   // backtrack
        }
    }

    return 0;
}

void printSolution() {
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);    // complete the cycle
}

void hamCycle() {

    // Initialize path
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start from vertex 0
    path[0] = 0;

    if (hamCycleUtil(1) == 0) {
        printf("No Hamiltonian cycle exists\n");
        return;
    }

    printSolution();
}

int main() {
    hamCycle();
    return 0;
}
