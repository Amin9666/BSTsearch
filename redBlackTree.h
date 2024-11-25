#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

typedef enum { RED, BLACK } Color;

typedef struct Node {
    char *key;            
    char *value;           
    Color color;           
    struct Node *left;    
    struct Node *right;    
    struct Node *parent;   
} Node;

typedef struct RBTree {
    Node *root;            
    Node *nil;             
} RBTree;

RBTree *createRBTree();  
void insertRBTree(RBTree *tree, const char *key, const char *value);
Node *searchRBTree(RBTree *tree, const char *key);
void inOrderTraversal(RBTree *tree, Node *node);
void reverseOrderTraversal(RBTree *tree, Node *node);

#endif