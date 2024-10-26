#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>  // For rand() and srand()
#include <time.h>    // For time()

#define MAX_SIZE 100

// Define the stack structure
struct Stack {
    int arr[MAX_SIZE]; // Array to store stack elements
    int top;           // Index of the top element
};

// Initialize a new stack
void initializeStack(struct Stack* stack) {
    stack->top = -1; // Set top to -1 indicating an empty stack
}

// Check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1; // Return true if top is -1
}

// Check if the stack is full
bool isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1; // Return true if top is at maximum index
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %d\n", value);
        return; // Exit the function if the stack is full
    }
    stack->top++; // Increment top
    stack->arr[stack->top] = value; // Add value to the stack
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1; // Return -1 if the stack is empty
    }
    int value = stack->arr[stack->top]; // Get the top value
    stack->top--; // Decrement top
    return value; // Return the popped value
}

// Peek at the top element of the stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, no top element\n");
        return -1; // Return -1 if the stack is empty
    }
    return stack->arr[stack->top]; // Return the top element
}

// Main function
int main() {
    struct Stack stack;          // Declare a stack
    initializeStack(&stack);      // Initialize the stack

    srand(time(0));               // Seed the random number generator

    // Push random elements onto the stack
    for (int i = 0; i < 3; i++) {
        int randomValue = rand() % 100;  // Generate a random number between 0 and 99
        push(&stack, randomValue);
        printf("Pushed: %d\n", randomValue);
    }

    // Display the top element
    printf("Top element: %d\n", peek(&stack));

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    // Display the top element again
    printf("Top element: %d\n", peek(&stack));

    return 0; // Return success
}
