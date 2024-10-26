#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Recursive function for BFS
void BFSRecursive(int adjacencyMatrix[MAX_NODES][MAX_NODES], int visited[MAX_NODES], int queue[MAX_NODES], int front, int rear) {
    if (front > rear) {
        return;
    }

    int currentNode = queue[front];
    printf("%d ", currentNode);
    front++;

    for (int i = 0; i < MAX_NODES; i++) {
        if (adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
            visited[i] = 1;
            queue[++rear] = i;
        }
    }

    BFSRecursive(adjacencyMatrix, visited, queue, front, rear);
}

// Function to start BFS traversal
void BFS(int adjacencyMatrix[MAX_NODES][MAX_NODES], int nodes, int startNode) {
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES];
    int front = 0, rear = -1;

    printf("BFS traversal starting from node %d: ", startNode);
    visited[startNode] = 1;
    queue[++rear] = startNode;

    BFSRecursive(adjacencyMatrix, visited, queue, front, rear);
    printf("\n");
}

// Recursive function for DFS
void DFSRecursive(int adjacencyMatrix[MAX_NODES][MAX_NODES], int visited[MAX_NODES], int currentNode) {
    visited[currentNode] = 1;
    printf("%d ", currentNode);

    for (int i = 0; i < MAX_NODES; i++) {
        if (adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
            DFSRecursive(adjacencyMatrix, visited, i);
        }
    }
}

// Function to start DFS traversal
void DFS(int adjacencyMatrix[MAX_NODES][MAX_NODES], int nodes, int startNode) {
    int visited[MAX_NODES] = {0};
    printf("DFS traversal starting from node %d: ", startNode);
    DFSRecursive(adjacencyMatrix, visited, startNode);
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

    int startNode = 0; // Starting node for BFS and DFS
    printf("Enter the starting node for BFS and DFS: ");
    scanf("%d", &startNode);

    BFS(adjacencyMatrix, nodes, startNode);
    DFS(adjacencyMatrix, nodes, startNode);

    return 0;
}
