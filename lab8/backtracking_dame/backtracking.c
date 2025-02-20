#include <stdio.h>
#include <stdlib.h>
#include "backtracking.h"
int nr_sol = 0;
int se_ataca(int x[], int pos) {
    for (int i = 1; i < pos; i++) {
        if (x[i]==x[pos]|| abs(x[i]-x[pos])==abs(i-pos)){
            return 1;
    }}
    return 0;
}
void tipareste_solutie(int x[], int n) {
    printf("\nSolutia %d este:\n", nr_sol);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j) { printf("R\t"); } 
            else { printf(".\t"); }
        }
        printf("\n");
    }
}   
void dame_iterativ(int n) {
    nr_sol = 0;
    int x[n + 1];
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
    int k = 1;
    while (k > 0) {
        if (k > n) {
            nr_sol++; k--;
            tipareste_solutie(x, n);
        } else {
            x[k]++;
            if (x[k] <= n) { 
                if (!se_ataca(x, k)) { k++; }
            } else { x[k] = 0; k--; }
        }
    }
}
void reset_nr_sol() { nr_sol = 0; }
void print_nr_sol() {printf("Nr solutii: %d\n", nr_sol);}

void dame_recursiv(int x[], int n, int k) {
    if (k > n) {
        nr_sol++;
        tipareste_solutie(x, n);
    } else {
        for (int i = 1; i <= n; i++) {
            x[k] = i;
            if (!se_ataca(x, k)) {
                dame_recursiv(x, n, k + 1);
            }
        }
    }
}