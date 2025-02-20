#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

Node* CREATE_NODE(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}


Node* MAKE_ROOT(Tree *T, int key) {
    T->root = CREATE_NODE(key);
    return T->root;
}


void TREE_INSERT(Tree *T, Node *z) {
    Node *y = NULL; 
    Node *x = T->root; 
    while (x != NULL) {
        y = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->parent = y; 
    if (y == NULL) T->root = z; 
    else if (z->key < y->key) y->left = z;
    else y->right = z;
}


void INORDER_WALK(Node *root) {
    if (root != NULL) {
        INORDER_WALK(root->left);
        printf("%d ", root->key);
        INORDER_WALK(root->right);
    }
}


void PREORDER_WALK(Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        PREORDER_WALK(root->left);
        PREORDER_WALK(root->right);
    }
}


void POSTORDER_WALK(Node *root) {
    if (root != NULL) {
        POSTORDER_WALK(root->left);
        POSTORDER_WALK(root->right);
        printf("%d ", root->key);
    }
}


//cautare iterativa
Node* IT_TREE_SEARCH(Node *root, int key) {
    while (root != NULL && key != root->key) {
        if (key < root->key) root = root->left;
        else root = root->right;
    }
    return root;
}

//cautare recursiva
Node* TREE_SEARCH(Node *root, int key) {
    if (root == NULL || key == root->key) return root;
    if (key < root->key) return TREE_SEARCH(root->left, key);
    else return TREE_SEARCH(root->right, key);
}


Node* TREE_MIN(Node *node) { 
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}


Node* TREE_MAX(Node *node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}


Node* TREE_SUCCESSOR(Node *x) {
    if (x->right != NULL) return TREE_MIN(x->right);
    else {
        Node *y = x->parent;
        while (y != NULL && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }
}

//inlocuirea subarborelui u cu subarborele v
void TRANSPLANT(Tree *T, Node *u, Node *v) {
    if (u->parent == NULL) T->root = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    if (v != NULL) v->parent = u->parent;
}



void TREE_DELETE(Tree *T, Node *z) {
    if (z->left == NULL) TRANSPLANT(T, z, z->right);
    else if (z->right == NULL) TRANSPLANT(T, z, z->left);
    else {
        Node *y = TREE_MIN(z->right);
        if (y->parent != z) {
            TRANSPLANT(T, y, y->right);
            y->right = z->right; 
            y->right->parent = y;
        }
        TRANSPLANT(T, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    free(z);
}