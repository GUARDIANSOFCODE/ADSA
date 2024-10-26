#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For seeding the random number generator

// Define the structure for a node
struct Node {
    int data;            // Data field to store the value
    struct Node* prev;   // Pointer to the previous node
    struct Node* next;   // Pointer to the next node
};

// Function to insert a new node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    newNode->data = data;       // Set the data for the new node
    newNode->next = NULL;       // New node will be the last node, so next is NULL

    if (*head == NULL) {        // If the list is empty
        newNode->prev = NULL;   // The new node will be the head, so prev is NULL
        *head = newNode;        // Update head to point to the new node
        return;                 // Exit the function
    }

    struct Node* current = *head; // Start from the head
    while (current->next != NULL) { // Traverse to the last node
        current = current->next; // Move to the next node
    }
    
    current->next = newNode;    // Point the last node to the new node
    newNode->prev = current;    // Link the new node back to the last node
}

// Function to display the doubly linked list in both forward and backward directions
void displayList(struct Node* head) {
    struct Node* current = head; // Start from the head
    struct Node* last = NULL;    // This will hold the last node for backward traversal

    printf("Forward: ");
    while (current != NULL) { // Traverse the list in the forward direction
        printf("%d ", current->data); // Print the data of the current node
        last = current; // Mark the last node encountered
        current = current->next; // Move to the next node
    }
    printf("NULL\n");

    printf("Backward: ");
    current = last; // Start from the last node (backward traversal)
    while (current != NULL) { // Traverse the list in the backward direction
        printf("%d ", current->data); // Print the data of the current node
        current = current->prev; // Move to the previous node
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL; // Initialize the head to NULL
    srand(time(0)); // Seed the random number generator with current time

    // Insert random values into the list
    for (int i = 0; i < 5; i++) {
        int randomValue = rand() % 100; // Generate a random number between 0 and 99
        insertEnd(&head, randomValue); // Insert the random value at the end of the list
    }

    printf("Doubly Linked List with Random Values:\n");
    displayList(head); // Display the doubly linked list

    return 0; // Return statement for main
}
