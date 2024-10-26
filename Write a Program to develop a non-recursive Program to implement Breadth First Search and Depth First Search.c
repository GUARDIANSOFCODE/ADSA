#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Function to perform BFS non-recursively
void BFS(int adjacencyMatrix[MAX_NODES][MAX_NODES], int nodes, int startNode) {
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES];
    int front = 0, rear = -1;

    printf("BFS traversal starting from node %d: ", startNode);
    visited[startNode] = 1;
    queue[++rear] = startNode;

    while (front <= rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        for (int i = 0; i < nodes; i++) {
            if (adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

// Function to perform DFS non-recursively
void DFS(int adjacencyMatrix[MAX_NODES][MAX_NODES], int nodes, int startNode) {
    int visited[MAX_NODES] = {0};
    int stack[MAX_NODES];
    int top = -1;

    printf("DFS traversal starting from node %d: ", startNode);
    stack[++top] = startNode;

    while (top >= 0) {
        int currentNode = stack[top--];

        if (!visited[currentNode]) {
            printf("%d ", currentNode);
            visited[currentNode] = 1;
        }

        for (int i = nodes - 1; i >= 0; i--) {
            if (adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
                stack[++top] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int nodes = 6; // Random number of nodes
    int edges = 7; // Random number of edges

    // Initialize the adjacency matrix
    int adjacencyMatrix[MAX_NODES][MAX_NODES] = {{0}};

    // Random edges for the graph
    int randomEdges[7][2] = {
        {0, 1},
        {0, 3},
        {1, 2},
        {1, 4},
        {3, 4},
        {2, 5},
        {4, 5}
    };

    // Setting up the edges
    for (int i = 0; i < edges; i++) {
        int node1 = randomEdges[i][0];
        int node2 = randomEdges[i][1];
        adjacencyMatrix[node1][node2] = 1;
        adjacencyMatrix[node2][node1] = 1; // For undirected graph
    }

    int startNode;
    printf("Enter the starting node for BFS and DFS: ");
    scanf("%d", &startNode);

    BFS(adjacencyMatrix, nodes, startNode);
    DFS(adjacencyMatrix, nodes, startNode);

    return 0;
}
