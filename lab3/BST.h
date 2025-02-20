#ifndef BST_H
#define BST_H

typedef struct Node {
    int key;
    struct Node *left, *right, *parent;
} Node;

typedef struct Tree {
    Node *root;
} Tree;

Node* CREATE_NODE(int key);

Node* MAKE_ROOT(Tree *T, int key);

void TREE_INSERT(Tree *T, Node *z);

void INORDER_WALK(Node *root);

void PREORDER_WALK(Node *root);

void POSTORDER_WALK(Node *root);

Node* IT_TREE_SEARCH(Node *root, int key);

Node* TREE_SEARCH(Node *root, int key);

Node* TREE_MIN(Node *node);

Node* TREE_MAX(Node *node);

Node* TREE_SUCCESSOR(Node *x);

void TRANSPLANT(Tree *T, Node *u, Node *v);

void TREE_DELETE(Tree *T, Node *z);

#endif




