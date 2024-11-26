#include <stdio.h>
#define V 4  // Number of vertices in the graph

// Function to perform DFS
void dfs(int graph[V][V], int reach[V][V], int u) {
    for (int v = 0; v < V; v++) {
        if (graph[u][v] && !reach[u][v]) {
            reach[u][v] = 1;  // Mark reachable
            dfs(graph, reach, v);  // Recur for the next vertex
        }
    }
}

// Function to compute transitive closure
void transitiveClosure(int graph[V][V]) {
    int reach[V][V];
    
    // Initialize the reachability matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            reach[i][j] = graph[i][j];
        }
    }
    
    // Compute transitive closure
    for (int i = 0; i < V; i++) {
        dfs(graph, reach, i);
    }
    
    // Print the transitive closure matrix
    printf("Transitive Closure Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };
    
    transitiveClosure(graph);
    return 0;
}
