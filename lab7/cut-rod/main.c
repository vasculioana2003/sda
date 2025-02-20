#include "cut_rod.h"
#include <stdio.h>

int main() {
    int n;

    printf("Introduceți lungimea barei: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input invalid. Introduceți un număr pozitiv.\n");
        return 1;
    }

    int prices[n + 1];
    prices[0] = 0; // Ensure the first index is initialized
    printf("Introduceți prețurile pentru fiecare lungime:\n");
    read_prices(prices, n);

    printf("\nRezultatele utilizând metodele:\n");

    // Metoda recursivă
    int max_value = cut_rod(prices, n);
    printf("Valoarea maximă (recursiv): %d\n", max_value);

    // Metoda top-down cu memorare
    max_value = memoized_cut_rod(prices, n);
    printf("Valoarea maximă (top-down cu memorare): %d\n", max_value);

    // Metoda bottom-up
    max_value = bottom_up_cut_rod(prices, n);
    printf("Valoarea maximă (bottom-up): %d\n", max_value);

    return 0;
}

