#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

int main() {
    t_arbore A;
    int n;
    printf("Numar persoane: ");
    scanf("%d", &n);
    t_nod_arb *persoana;
    char nume[20], prenume[20], CNP[20];
    printf("Introduceti numele persoanei: ");
    scanf("%s", nume);
    printf("Introduceti prenume persoanei: ");
    scanf("%s", prenume);
    printf("Introduceti CNP-ul persoanei: ");
    scanf("%s", CNP);
    t_nod_arb *r = make_root(&A, nume, prenume, CNP);
    n--;

    while (n--) {
        printf("Introduceti numele persoanei: ");
        scanf("%s", nume);
        printf("Introduceti prenume persoanei: ");
        scanf("%s", prenume);
        printf("Introduceti CNP-ul persoanei: ");
        scanf("%s", CNP);
        persoana = create_node(nume, prenume, CNP);
        tree_insert(&A, persoana);
    }

    printf("\n");
    preorder_walk(r);
   
    printf("\nIntroduceti CNP: ");
    scanf("%s", CNP);
    t_nod_arb *ans = tree_search(r, CNP);
    (ans != NULL 
        ? printf("CNP-ul a fost gasit!\n") 
        : printf("CNP-ul nu a fost gasit!\n")
    );
}