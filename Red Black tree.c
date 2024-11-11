#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

// Define structure of a Red-Black Tree node
typedef struct Node {
    int data;
    enum Color color;
    struct Node *left, *right, *parent;
} Node;

Node *root = NULL;

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED;  // New nodes are always red initially
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Left rotation
void rotateLeft(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// Right rotation
void rotateRight(Node *x) {
    Node *y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->right = x;
    x->parent = y;
}

// Function to maintain Red-Black Tree properties after insertion
void fixInsertion(Node *node) {
    Node *parent = NULL;
    Node *grandparent = NULL;

    while (node != root && node->color != BLACK && node->parent->color == RED) {
        parent = node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;

            // Case 1: Uncle is red, recolor
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                // Case 2: Node is right child, left-rotate
                if (node == parent->right) {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }

                // Case 3: Node is left child, right-rotate
                rotateRight(grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                node = parent;
            }
        } else {
            Node *uncle = grandparent->left;

            // Mirror Case 1: Uncle is red, recolor
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                // Mirror Case 2: Node is left child, right-rotate
                if (node == parent->left) {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }

                // Mirror Case 3: Node is right child, left-rotate
                rotateLeft(grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                node = parent;
            }
        }
    }
    root->color = BLACK;
}

// Function to insert a new node into the Red-Black Tree
void insert(int data) {
    Node *newNode = createNode(data);

    if (root == NULL) {
        newNode->color = BLACK;
        root = newNode;
    } else {
        Node *current = root;
        Node *parent = NULL;

        while (current != NULL) {
            parent = current;
            if (data < current->data)
                current = current->left;
            else if (data > current->data)
                current = current->right;
            else
                return;  // Duplicate keys not allowed
        }

        newNode->parent = parent;
        if (data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        fixInsertion(newNode);
    }
}

// In-order traversal to print the tree
void inOrderTraversal(Node *node) {
    if (node == NULL)
        return;
    inOrderTraversal(node->left);
    printf("%d(%s) ", node->data, node->color == RED ? "R" : "B");
    inOrderTraversal(node->right);
}

// Main function to test the Red-Black Tree implementation
int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(15);
    insert(25);
    insert(5);
    insert(1);

    printf("In-order traversal of the Red-Black Tree:\n");
    inOrderTraversal(root);

    return 0;
}
