#include "paranteze.h"

// Funcția pentru afișarea parantezelor optime
void print_optimal_parens(int s[][100], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1, j);
        printf(")");
    }
}

// Funcția MATRIX_CHAIN_ORDER
void matrix_chain_order(int p[], int n, int s[][100]) {
    int m[100][100] = {0}; // Matricea M pentru costuri
    int num_matrices = n - 1; // Numărul de matrici

    // Inițializăm diagonala principală a lui m cu 0
    for (int i = 1; i <= num_matrices; i++) {
        m[i][i] = 0;
    }

    // Calculăm costurile pentru toate lungimile de lanț
    for (int t = 2; t <= num_matrices; t++) { // Lungimea lanțului
        for (int i = 1; i <= num_matrices - t + 1; i++) {
            int j = i + t - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Costul minim al înmulțirii: %d\n", m[1][num_matrices]);
}

// Funcția pentru citirea unui array
void read_array(int a[], int n) {
    printf("Introduceți dimensiunile matricilor (array-ul p):\n");
    for (int i = 0; i < n; i++) {
        printf("p[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
