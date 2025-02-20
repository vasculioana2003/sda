#include "greedy.h"
#include <stdio.h>

int main() {
    int n;
    printf("Introduceți numărul de activități: ");
    scanf("%d", &n);

    int s[n], f[n], sol_recursive[n], sol_iterative[n];

    printf("Introduceți timpii de început: ");
    read_array(s, n);

    printf("Introduceți timpii de final: ");
    read_array(f, n);

    int na_recursive = recursive_activity_selector(s, f, -1, n, sol_recursive);
    printf("Soluție recursivă: ");
    print_array(sol_recursive, na_recursive);

    int na_iterative = greedy_activity_selector(s, f, n, sol_iterative);
    printf("Soluție iterativă: ");
    print_array(sol_iterative, na_iterative);

    return 0;
}
