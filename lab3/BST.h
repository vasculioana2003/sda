#ifndef BST_H
#define BST_H

/** Define the structure for a tree node */
typedef struct Node {
    int key;
    struct Node *left, *right, *parent;
} Node;

/** Define the structure for the tree */
typedef struct Tree {
    Node *root;
} Tree;


/** Function to create a new node */
Node* CREATE_NODE(int key);

/** Function to initialize the tree with a root */
Node* MAKE_ROOT(Tree *T, int key);

/** Insert a node in the tree */
void TREE_INSERT(Tree *T, Node *z);

/** In-order tree walk (Left, Root, Right) */
void INORDER_WALK(Node *root);

/** Pre-order tree walk (Root, Left, Right) */
void PREORDER_WALK(Node *root);

/** Post-order tree walk (Left, Right, Root) */
void POSTORDER_WALK(Node *root);

/** Iterative search */
Node* IT_TREE_SEARCH(Node *root, int key);

/** Recursive search */
Node* TREE_SEARCH(Node *root, int key);

/** Find minimum node */
Node* TREE_MIN(Node *node);

/** Find maximum node */
Node* TREE_MAX(Node *node);

/** Find successor of a node */
Node* TREE_SUCCESSOR(Node *x);

/** Delete a node from the tree */
void TRANSPLANT(Tree *T, Node *u, Node *v);

void TREE_DELETE(Tree *T, Node *z);

#endif