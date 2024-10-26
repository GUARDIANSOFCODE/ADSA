#include <stdio.h>

// Function to display array elements
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specified position
int insertElement(int arr[], int size, int element, int position) {
    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return size; // Return the current size if position is invalid
    }
    // Shift elements to the right to create space for the new element
    for (int i = size - 1; i > position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = element; // Insert the new element
    return size + 1; // Return the new size
}

// Function to delete an element at a specified position
int deleteElement(int arr[], int size, int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position for deletion.\n");
        return size; // Return the current size if position is invalid
    }
    // Shift elements to the left to fill the gap created by deletion
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1; // Return the new size
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return the index if element is found
        }
    }
    return -1; // Return -1 if element is not found
}

// Function to update an element at a specified position
void updateElement(int arr[], int size, int position, int newValue) {
    if (position >= 0 && position < size) {
        arr[position] = newValue; // Update the value at the position
    } else {
        printf("Invalid position for updating.\n");
    }
}

// Main function
int main() {
    int arr[100]; // Array declaration
    int size = 0; // Initialize size to 0

    // Inserting elements into the array with random values
    size = insertElement(arr, size, 5, 0);
    size = insertElement(arr, size, 15, 1);
    size = insertElement(arr, size, 25, 2);
    size = insertElement(arr, size, 35, 3);
    size = insertElement(arr, size, 45, 4);

    printf("After insertion:\n");
    displayArray(arr, size); // Display array after insertion

    size = deleteElement(arr, size, 2); // Deleting an element at position 2
    printf("After deletion:\n");
    displayArray(arr, size); // Display array after deletion

    // Searching for an element
    int searchElementIndex = searchElement(arr, size, 45);
    if (searchElementIndex != -1) {
        printf("Element 45 found at index %d\n", searchElementIndex);
    } else {
        printf("Element 45 not found.\n");
    }

    // Updating an element
    updateElement(arr, size, 2, 50);
    printf("After updating:\n");
    displayArray(arr, size); // Display array after updating

    return 0; // Return statement for main
}
