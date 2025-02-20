#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

// Main function
int main() {
    Tree T;
    T.root = NULL;
    int x;

    printf("Nodul radacina cu cheia x= ");
    scanf("%d", &x);
    Node *r = MAKE_ROOT(&T, x);

    printf("Introduceti x pana la citirea 0\n");
    while (1) {
        printf("x= ");
        scanf("%d", &x);
        if (x == 0) break;
        Node *n = CREATE_NODE(x);
        TREE_INSERT(&T, n);
    }

    printf("IN-order walk:\n");
    INORDER_WALK(T.root);
    printf("\nPre-order walk:\n");
    PREORDER_WALK(T.root);
    printf("\nPost-order walk:\n");
    POSTORDER_WALK(T.root);

    printf("\nRegasire nod cu cheia x= ");
    scanf("%d", &x);
    Node *n = IT_TREE_SEARCH(T.root, x);
    if (n != NULL) printf("Nodul cu cheia %d gasit iterativ la adresa %p\n", 
        n->key, &n->key);
    else printf("Nodul nu a fost gasit iterativ\n");

    n = TREE_SEARCH(T.root, x);
    if (n != NULL) printf("Nodul cu cheia %d gasit recursiv la adresa %p\n", 
        n->key, &n->key);
    else printf("Nodul nu a fost gasit recursiv\n");

    n = TREE_MIN(T.root);
    printf("Tree minimum: %d\n", n->key);
    n = TREE_MAX(T.root);
    printf("Tree maximum: %d\n", n->key);

    printf("Succesorul lui x= ");
    scanf("%d", &x);
    n = TREE_SEARCH(T.root, x);
    Node *s = TREE_SUCCESSOR(n);
    if (s != NULL) printf("Nod successor: %d\n", s->key);
    else printf("NULL\n");

    printf("Stergere nod cu cheia x= /n");
    scanf("%d", &x);
    n = TREE_SEARCH(T.root, x);
    if (n != NULL) {
        TREE_DELETE(&T, n);
        printf("Nod sters\n");
        INORDER_WALK(T.root);
    } else {
        printf("\nNod negasit!\n");
    }

    return 0;
}
