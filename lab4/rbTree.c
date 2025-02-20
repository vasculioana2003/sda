#include <stdlib.h>
#include <stdio.h>
#include "rbTree.h"

t_rb_node* MAKE_ROOT(t_rb_arbore *T, int key) {
    T->root = (t_rb_node*)malloc(sizeof(t_rb_node));
    if (T->root == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    T->root->key = key;
    T->root->left = NULL;
    T->root->right = NULL;
    T->root->parent = NULL;
    T->root->color = BLACK;
    return T->root;
}

t_rb_node* CREATE_NODE(int key) {
    t_rb_node* newNode = (t_rb_node*)malloc(sizeof(t_rb_node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->color = RED; 
    return newNode;
}

void INORDER_WALK(t_rb_node *root) {
    if (root != NULL) {
        INORDER_WALK(root->left);
        printf("%d %c\n", root->key,(root->color==BLACK)?'b':'r');
        INORDER_WALK(root->right);
    }
}

t_rb_node* TREE_SEARCH(t_rb_node *root, int key) {
    if (root == NULL || key == root->key) return root;
    if (key < root->key) return TREE_SEARCH(root->left, key);
    else return TREE_SEARCH(root->right, key);
}

void LEFT_ROTATE(t_rb_arbore *a, t_rb_node *x) {
    t_rb_node *y = x->right;
    x->right = y->left;
    if (y->left != NULL) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) a->root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void RIGHT_ROTATE(t_rb_arbore *a, t_rb_node *x) {
    t_rb_node *y = x->left;
    x->left = y->right;
    if (y->right != NULL) y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) a->root = y;
    else if (x == x->parent->right) x->parent->right = y;
    else x->parent->left = y;
    y->right = x;
    x->parent = y;
}

void RB_INSERT_FIXUP(t_rb_arbore *a, t_rb_node *z) {
    while (z->parent != NULL && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            t_rb_node *y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    LEFT_ROTATE(a, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                RIGHT_ROTATE(a, z->parent->parent);
            }
        } else {
            t_rb_node *y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    RIGHT_ROTATE(a, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                LEFT_ROTATE(a, z->parent->parent);
            }
        }
    }
    a->root->color = BLACK;
}

void RB_INSERT(t_rb_arbore *a, t_rb_node *z) {
    t_rb_node *y = NULL;
    t_rb_node *x = a->root;
    while (x != NULL) {
        y = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if (y == NULL) a->root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;
    z->left = NULL;
    z->right = NULL;
    z->color = RED;
    RB_INSERT_FIXUP(a, z);
}
