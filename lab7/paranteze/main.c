#include <stdio.h>
#include "paranteze.h"

int main() {
    int n;
    printf("Introduceți numărul de dimensiuni (lungimea array-ului): ");
    scanf("%d", &n);

    int p[n];
    read_array(p, n);

    int s[100][100] = {0}; // Matricea S pentru punctele de tăiere
    matrix_chain_order(p, n, s);

    printf("Ordinea optimă de parantezare:\n");
    print_optimal_parens(s, 1, n - 1);
    printf("\n");

    return 0;
}
