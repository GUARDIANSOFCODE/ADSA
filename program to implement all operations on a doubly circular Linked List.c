#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For seeding the random number generator

// Define the structure for a node
struct Node {
    int data;               // Data field to store the value
    struct Node* prev;      // Pointer to the previous node
    struct Node* next;      // Pointer to the next node
};

// Function to insert a new node at the end of the doubly circular linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    newNode->data = data;

    // If the list is empty
    if (head == NULL) {
        newNode->prev = newNode; // Point prev to itself
        newNode->next = newNode; // Point next to itself
        return newNode;          // New node is the only node in the list
    }

    // Otherwise, insert the new node at the end
    struct Node* last = head->prev; // Get the last node
    newNode->next = head;           // Point newNode's next to head
    newNode->prev = last;           // Point newNode's prev to last

    last->next = newNode;           // Link the last node to the new node
    head->prev = newNode;           // Link head to the new node

    return head;                    // Return the unchanged head pointer
}

// Function to display the doubly circular linked list in both forward and backward directions
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;

    // Display the list in forward direction
    printf("Forward: ");
    do {
        printf("%d ", current->data);
        current = current->next;  // Move to the next node
    } while (current != head);    // Stop when we reach back to the head
    printf("...\n");

    // Display the list in backward direction
    current = head->prev;         // Start from the last node
    printf("Backward: ");
    do {
        printf("%d ", current->data);
        current = current->prev;  // Move to the previous node
    } while (current != head->prev); // Stop when we reach back to the last node
    printf("...\n");
}

// Main function
int main() {
    struct Node* head = NULL; // Initialize the head to NULL
    srand(time(0));           // Seed the random number generator with the current time

    // Insert random elements at the end of the doubly circular linked list
    for (int i = 0; i < 5; i++) {
        int randomValue = rand() % 100;  // Generate a random number between 0 and 99
        head = insertEnd(head, randomValue);
    }

    printf("Doubly Circular Linked List with Random Values:\n");
    displayList(head); // Display the doubly circular linked list

    return 0; // Return statement for main
}
