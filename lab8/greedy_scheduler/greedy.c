#include "greedy.h"
#include <stdio.h>
#include <stdlib.h>

//solutia recursiva pe baza algortimului de backtracking
int recursive_activity_selector(int s[], int f[], int k, int n, int sol[]) {
    int m = k + 1; //k este activitatea curenta si m este urmatoarea activitate

    // Căutăm prima activitate care începe după ce s-a terminat activitatea k
    while (m < n && s[m] < f[k]) { 
        m++;
    }

    // Dacă am găsit o activitate validă
    if (m < n) {
        sol[0] = m; // Adăugăm activitatea curentă în soluție
        return 1 + recursive_activity_selector(s, f, m, n, sol + 1);
    }

    return 0; // Dacă nu mai există activități valide
}

// solutia iterativa
int greedy_activity_selector(int s[], int f[], int n, int sol[]) {
    int na = 0;  // numărul de activități selectate
    int k = 0;   // ultima activitate selectată (prima activitate este 
    
    sol[na] = k;  // Adăugăm prima activitate
    na++;         // Incrementăm numărul de activități selectate

    for (int i = 1; i < n; i++) { // Iterăm de la a doua activitate
        if (s[i] >= f[k]) { // Verificăm dacă activitatea poate fi selectată
            sol[na] = i;  // Adăugăm activitatea curentă
            na++;         // Incrementăm numărul de activități selectate
            k = i;        // Actualizăm ultima activitate selectată
        }
    }
    return na; // returnăm numărul de activități selectate
}

void read_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}