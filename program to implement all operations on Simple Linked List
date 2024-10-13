#include <stdio.h>
// Function to display the elements of the array
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a given position
int insertElement(int arr[], int size, int element, int position) {
    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return size;
    }
    // Shift elements to the right to create space
    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
    return size + 1;
}

// Function to delete an element from a given position
int deleteElement(int arr[], int size, int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position for deletion.\n");
        return size;
    }
    // Shift elements to the left to fill the gap
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

// Function to search for an element and return its index
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// Function to update an element at a given position
void updateElement(int arr[], int size, int position, int newValue) {
    if (position >= 0 && position < size) {
        arr[position] = newValue;
    } else {
        printf("Invalid position for updating.\n");
    }
}

int main() {
    int arr[100];  // Declare an array of size 100
    int size = 0;  // Initialize size to 0

    // Insert elements into the array with random values
    size = insertElement(arr, size, 7, 0);
    size = insertElement(arr, size, 13, 1);
    size = insertElement(arr, size, 26, 2);
    printf("After insertion:\n");
    displayArray(arr, size);

    // Delete an element at position 1
    size = deleteElement(arr, size, 1);
    printf("After deletion:\n");
    displayArray(arr, size);

    // Search for element 26
    int searchElementIndex = searchElement(arr, size, 26);
    if (searchElementIndex != -1) {
        printf("Element 26 found at index %d\n", searchElementIndex);
    } else {
        printf("Element 26 not found.\n");
    }

    // Update the element at position 1
    updateElement(arr, size, 1, 35);
    printf("After updating:\n");
    displayArray(arr, size);

    return 0;
}

