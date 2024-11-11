#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the Splay Tree
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Utility function to create a new node
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Right rotation
Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay operation
Node* splay(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    // Key lies in left subtree
    if (key < root->key) {
        if (root->left == NULL) return root;

        // Zig-Zig (Left Left)
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
        return (root->left == NULL) ? root : rightRotate(root);
    } else {  // Key lies in right subtree
        if (root->right == NULL) return root;

        // Zag-Zig (Right Left)
        if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Insert a new key
Node* insert(Node* root, int key) {
    if (root == NULL) return newNode(key);

    root = splay(root, key);

    if (root->key == key) return root;

    Node* newnode = newNode(key);

    if (key < root->key) {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    } else {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }
    return newnode;
}

// Delete a node
Node* deleteKey(Node* root, int key) {
    if (root == NULL) return NULL;

    root = splay(root, key);

    if (root->key != key) return root;

    Node* temp;
    if (root->left == NULL) {
        temp = root->right;
    } else {
        temp = splay(root->left, key);
        temp->right = root->right;
    }
    free(root);
    return temp;
}

// Search for a key
Node* search(Node* root, int key) {
    return splay(root, key);
}

// In-order traversal
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Main function to demonstrate the operations
int main() {
    Node* root = NULL;

    // Insert elements into the splay tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("In-order traversal of the splay tree: ");
    inOrder(root);
    printf("\n");

    // Search for an element
    root = search(root, 20);
    printf("After splaying 20 to the root, in-order traversal: ");
    inOrder(root);
    printf("\n");

    // Delete an element
    root = deleteKey(root, 30);
    printf("After deleting 30, in-order traversal: ");
    inOrder(root);
    printf("\n");

    return 0;
}
