#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, i, j;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int min, u, v;
    int totalWeight = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX; // No edge
        }
    }

    visited[0] = 1; // Start from vertex 0
    printf("Edges in the Minimum Spanning Tree:\n");

    for (int edges = 0; edges < n - 1; edges++) {
        min = INT_MAX;

        // Find the minimum weight edge from visited to unvisited vertex
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -- %d  (weight %d)\n", u, v, cost[u][v]);
        totalWeight += cost[u][v];
        visited[v] = 1;
    }

    printf("Total weight of MST: %d\n", totalWeight);

    return 0;
}