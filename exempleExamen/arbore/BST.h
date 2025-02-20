#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod_arb {
    char nume[20];
    char prenume[20];
    char CNP[13];
    struct nod_arb *left, *right, *parent;
} t_nod_arb;

typedef struct {
    t_nod_arb *root;
} t_arbore;






arbore