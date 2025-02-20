#include <stdio.h>
#include <stdlib.h>
#include "backtracking.h"

int main(){
    int x[100]; 

    int n;
    printf("Introduceti numarul de dame: ");
    scanf("%d", &n);

    printf("\nSolutii iterativ:\n");
    dame_iterativ(n);
    print_nr_sol();

    printf("\nSolutii recursiv:\n");
    reset_nr_sol();
    dame_recursiv(x, n, 1);
    print_nr_sol();

    return 0;
}