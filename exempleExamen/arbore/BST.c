#include <stdlib.h>
#include <stdio.h>
#include "BST.h"
#include <string.h>

t_nod_arb *make_root(t_arbore *A, char nume[], 
    char prenume[], char CNP[]
) {
    A->root = (t_nod_arb*)malloc(sizeof(t_nod_arb));
    strcpy(A->root->nume, nume);
    strcpy(A->root->prenume, prenume);
    strcpy(A->root->CNP, CNP);
    A->root->left =A->root->right =A->root->parent =NULL;
    return A->root;
}
t_nod_arb *create_node(char nume[],char prenume[],char CNP[]){
    t_nod_arb *node = (t_nod_arb*)malloc(sizeof(t_nod_arb));
    strcpy(node->nume, nume);
    strcpy(node->prenume, prenume);
    strcpy(node->CNP, CNP);
    node->left = node->right = node->parent = NULL;
}
void tree_insert(t_arbore *A, t_nod_arb *n) {
    t_nod_arb *x, *y;
    y = NULL;
    x = A->root;

    while (x != NULL) {
        y = x;
        if (strcmp(n->CNP, y->CNP) < 0) 
            x = x->left;
        else
            x = x->right;
    }
    n->parent = y;
    if (y == NULL)
        A->root = n;
    else if (strcmp(n->CNP, y->CNP) < 0)
        y->left = n;
    else
        y->right = n;
}
void preorder_walk(t_nod_arb *root) {
    if (root != NULL) {
        preorder_walk(root->left);
        printf("%s ", root->nume);
        preorder_walk(root->right);
    }
}
t_nod_arb *tree_search(t_nod_arb *n, char CNP[]) {
    if (n == NULL || strcmp(n->CNP, CNP))
        return n;
    else if (strcmp(n->CNP, CNP) < 0)
        return tree_search(n->left, CNP);
    else
        return tree_search(n->right, CNP);
}
