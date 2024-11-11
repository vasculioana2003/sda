#include <stdio.h>
#include <stdlib.h>
#include "rbTree.h"

int main() {
    t_rb_arbore T;
    T.root = NULL;

    int x;
    printf("ROOT=");
    scanf("%d", &x);
    MAKE_ROOT(&T, x);

    printf("Introduceti x pana la citirea 0\n");
    printf("x= ");
    scanf("%d", &x);
    while (x != 0) {
        t_rb_node *n = CREATE_NODE(x);
        RB_INSERT(&T, n);
        printf("x= ");
        scanf("%d", &x);
    }

    printf("In-order walk:\n");
    INORDER_WALK(T.root);
    printf("\n");

    printf("Cauta nod cu cheia x= ");
    scanf("%d", &x);
    t_rb_node *n = TREE_SEARCH(T.root, x);
    if (n != NULL) {
        printf("Nodul cu cheia %d gasit la adresa %p\n", n->key, n);
    } else {
        printf("Nodul nu a fost gasit\n");
    }

    return 0;
}





