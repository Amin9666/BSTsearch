#include <stdio.h>
#include <stdlib.h>
#include "redBlackTree.h"
#include <string.h>

int isRed(Node* node) {
if (node == NULL) return 0;
return node->color == RED;
}
Node* rotateLeft(Node* h) {
Node* x = h->right;
h->right = x->left;
x->left = h;
x->color = h->color;
h->color = RED;
return x;
}
Node* rotateRight(Node* h) {
Node* x = h->left;
h->left = x->right;
x->right = h;
x->color = h->color;
h->color = RED;
return x;
}
void flipColors(Node* h) {
h->color = RED;
h->left->color = BLACK;
h->right->color = BLACK;
}
Node *createNode(const char *key, const char *value, Color color, Node *nil) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = strdup(key);     
    newNode->value = strdup(value);  
    newNode->color = color;
    newNode->left = nil;
    newNode->right = nil;
    newNode->parent = nil;
    return newNode;
}

Node *insertNode(Node *h, const char *key, const char *value, RBTree *tree) {
    if (h == tree->nil) {
        return createNode(key, value, RED, tree->nil);  // Create a new node
    }

    if (strcmp(key, h->key) < 0) {
        h->left = insertNode(h->left, key, value, tree);
        h->left->parent = h;
    } else if (strcmp(key, h->key) > 0) {
        h->right = insertNode(h->right, key, value, tree);
        h->right->parent = h;
    } else {
        // Duplicate key: update the value
        free(h->value);
        h->value = strdup(value);
    }

    return h;
}

void inOrderTraversal(RBTree *tree, Node *root) {
    if (root != tree->nil) {
        inOrderTraversal(tree, root->left);
        printf("%s: %s\n", root->key, root->value);
        inOrderTraversal(tree, root->right);
    }
}
Node* fixUpRoot(Node* root) {
if (root != NULL) root->color = BLACK;
return root;
}
void inOrder(Node* root) {
if (root == NULL) return;
inOrder(root->left);
printf("%s ", root->key);
inOrder(root->right);
}
void insertRBTree(RBTree *tree, const char *key, const char *value) {
    tree->root = insertNode(tree->root, key, value, tree);
}

Node *searchRBTree(RBTree *tree, const char *key) {
    Node *current = tree->root;
    while (current != tree->nil && strcmp(key, current->key) != 0) {
        if (strcmp(key, current->key) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}

void reverseOrderTraversal(RBTree *tree, Node *root) {
    if (root != tree->nil) {
        reverseOrderTraversal(tree, root->right);
        printf("%s: %s\n", root->key, root->value);
        reverseOrderTraversal(tree, root->left);
    }
}
RBTree *createRBTree() {
    RBTree *tree = (RBTree *)malloc(sizeof(RBTree));
    tree->nil = (Node *)malloc(sizeof(Node));
    tree->nil->color = BLACK;
    tree->nil->left = tree->nil->right = tree->nil->parent = NULL;
    tree->root = tree->nil;
    return tree;
}