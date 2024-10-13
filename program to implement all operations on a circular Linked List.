#include <stdio.h>
#include <stdlib.h>
// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Point to itself
    return newNode;
}

// Function to insert an element at the end of the circular linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode; // Link the last node to the new node
    }
    newNode->next = *head; // Make the new node point to head
}

// Function to display the elements of the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next; // Move to the next node
    } while (temp != head);
    printf("\n");
}

// Function to delete an element from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = *head, *prev = NULL;

    // If the node to be deleted is the head node
    if (temp->data == key) {
        // Find the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        if (*head == (*head)->next) {
            free(*head);
            *head = NULL; // List is now empty
        } else {
            temp->next = (*head)->next; // Last node points to the second node
            free(*head); // Free the old head
            *head = temp->next; // Update head to the next node
        }
        return;
    }

    // Traverse the list to find the node to be deleted
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->data != key);

    // If the key was not found
    if (temp == *head) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    prev->next = temp->next; // Unlink the node from the list
    free(temp); // Free the memory
}

// Function to search for an element in the circular linked list
int searchElement(struct Node* head, int key) {
    if (head == NULL) {
        return -1; // List is empty
    }
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            return 1; // Element found
        }
        temp = temp->next; // Move to the next node
    } while (temp != head);
    return -1; // Element not found
}

// Function to update an element in the circular linked list
void updateElement(struct Node* head, int oldValue, int newValue) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty. Cannot update.\n");
        return;
    }
    do {
        if (temp->data == oldValue) {
            temp->data = newValue; // Update the value
            return;
        }
        temp = temp->next; // Move to the next node
    } while (temp != head);
    printf("Element %d not found in the list. Cannot update.\n", oldValue);
}

int main() {
    struct Node* head = NULL; // Initialize head of the circular linked list

    // Insert elements into the circular linked list with random values
    insertEnd(&head, 15);
    insertEnd(&head, 25);
    insertEnd(&head, 35);
    
    printf("After insertion:\n");
    displayList(head);

    // Delete an element
    deleteNode(&head, 25);
    printf("After deletion:\n");
    displayList(head);

    // Search for an element
    int searchResult = searchElement(head, 35);
    if (searchResult != -1) {
        printf("Element 35 found in the list.\n");
    } else {
        printf("Element 35 not found in the list.\n");
    }
     // Update an element
    updateElement(head, 15, 45);
    printf("After updating:\n");
    displayList(head);

    return 0;
