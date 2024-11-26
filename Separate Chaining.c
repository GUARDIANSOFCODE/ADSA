#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Hash table size
#define TABLE_SIZE 10

// Hash table array
Node* hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Insert a key into the hash table
void insert(int key) {
    int index = hashFunction(key);

    // Create a new node
    Node* newNode = createNode(key);

    // Insert at the beginning of the linked list at index
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

// Search for a key in the hash table
int search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    // Traverse the linked list at that index
    while (temp != NULL) {
        if (temp->key == key) {
            return 1; // Key found
        }
        temp = temp->next;
    }
    return 0; // Key not found
}

// Delete a key from the hash table
void delete(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    // Traverse the linked list to find the key
    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    // Key not found
    if (temp == NULL) {
        printf("Key %d not found.\n", key);
        return;
    }

    // Key found, delete the node
    if (prev == NULL) {
        hashTable[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Key %d deleted.\n", key);
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    // Initialize the hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert keys
    insert(15);
    insert(25);
    insert(35);
    insert(20);
    insert(30);

    // Display the hash table
    printf("Hash table:\n");
    display();

    // Search for a key
    printf("\nSearching for key 25: %s\n", search(25) ? "Found" : "Not Found");
    printf("Searching for key 40: %s\n", search(40) ? "Found" : "Not Found");

    // Delete a key
    delete(25);
    printf("\nHash table after deletion:\n");
    display();

    return 0;
}
