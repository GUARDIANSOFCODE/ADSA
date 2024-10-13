#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>  // For srand() and rand()

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Define the stack structure
struct Stack {
    struct Node* top;
};

// Initialize a new stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL; // Empty stack
}

// Check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == NULL; // Corrected comparison
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode; // Move the top to the new node
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp); // Free the memory of the popped node

    return value;
}

// Peek at the top element of the stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, no top element\n");
        return -1;
    }
    return stack->top->data;
}

// Display the elements in the stack
void displayStack(struct Stack* stack) {
    struct Node* current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Stack stack;
    initializeStack(&stack);

    srand(time(0));  // Seed the random number generator

    // Push random values onto the stack
    for (int i = 0; i < 3; i++) {
        int randomValue = rand() % 100;  // Generate a random number between 0 and 99
        push(&stack, randomValue);
        printf("Pushed: %d\n", randomValue);
    }
    // Display the stack
    displayStack(&stack);
    // Peek at the top element
    printf("Top element: %d\n", peek(&stack));

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
   // Display the stack again after popping
    displayStack(&stack);
return 0;
}
