#include <stdio.h>
#include <stdlib.h>

#define MIN_DEGREE 2  // Minimum degree (t)

// Structure to represent a B+ Tree node
typedef struct BPlusTreeNode {
    int keys[2 * MIN_DEGREE - 1];  // Array to hold keys
    struct BPlusTreeNode* children[2 * MIN_DEGREE];  // Array to hold children
    struct BPlusTreeNode* next;  // Pointer to the next leaf node
    int numKeys;  // Current number of keys
    int isLeaf;   // True if leaf node
} BPlusTreeNode;

// Function to create a new B+ Tree node
BPlusTreeNode* createBPlusNode(int isLeaf) {
    BPlusTreeNode* newNode = (BPlusTreeNode*)malloc(sizeof(BPlusTreeNode));
    newNode->isLeaf = isLeaf;
    newNode->numKeys = 0;
    newNode->next = NULL;  // Initialize next pointer
    return newNode;
}

// Function to insert a key into a non-full node
void insertNonFull(BPlusTreeNode* node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        // Find the location to insert the new key
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        // Find the child to insert the new key
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++;

        // If the child is full, split it
        if (node->children[i]->numKeys == (2 * MIN_DEGREE - 1)) {
            // Split the child
            BPlusTreeNode* child = node->children[i];
            BPlusTreeNode* newChild = createBPlusNode(child->isLeaf);
            node->children[i + 1] = newChild;
            node->keys[i] = child->keys[MIN_DEGREE - 1];  // Move the middle key up

            // Move keys and children to the new child
            newChild->numKeys = MIN_DEGREE - 1;
            child->numKeys = MIN_DEGREE - 1;

            for (int j = 0; j < MIN_DEGREE - 1; j++) {
                newChild->keys[j] = child->keys[j + MIN_DEGREE];
            }
            if (!child->isLeaf) {
                for (int j = 0; j < MIN_DEGREE; j++) {
                    newChild->children[j] = child->children[j + MIN_DEGREE];
                }
            }

            // Recur to insert the key in the appropriate child
            insertNonFull(node, key);
        } else {
            insertNonFull(node->children[i], key);
        }
    }
}

// Function to insert a key into the B+ Tree
void insertBPlus(BPlusTreeNode** root, int key) {
    BPlusTreeNode* r = *root;

    // If the root node is full, create a new root
    if (r->numKeys == (2 * MIN_DEGREE - 1)) {
        BPlusTreeNode* newNode = createBPlusNode(0);
        newNode->children[0] = r;
        insertNonFull(newNode, key);
        *root = newNode;  // Update root
    } else {
        insertNonFull(r, key);
    }
}

// Function to traverse the B+ Tree
void traverseBPlus(BPlusTreeNode* node) {
    if (node->isLeaf) {
        for (int i = 0; i < node->numKeys; i++) {
            printf("%d ", node->keys[i]);
        }
    } else {
        for (int i = 0; i < node->numKeys; i++) {
            traverseBPlus(node->children[i]);
        }
        traverseBPlus(node->children[node->numKeys]);  // Traverse last child
    }
}

// Main function to test B+ Tree
int main() {
    BPlusTreeNode* root = createBPlusNode(1);  // Create root as leaf node
    insertBPlus(&root, 10);
    insertBPlus(&root, 20);
    insertBPlus(&root, 5);

    printf("B+ Tree traversal: ");
    traverseBPlus(root);
    printf("\n");  // Newline for clarity
    return 0;
}
