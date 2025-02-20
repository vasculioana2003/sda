#include "cut_rod.h"

int max(int a, int b) { return (a > b) ? a : b; }

void read_prices(int p[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("Preț pentru lungimea %d: ", i);
        if (scanf("%d", &p[i]) != 1) {
            printf("Input invalid.\n");
            p[i] = 0;
        }
    }
}
void print_array(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("r[%d] = %d\n", i, arr[i]); 
    }
}
int cut_rod(int p[], int n) {
    if (n == 0){~
        return 0;
    }
    int q = INT_MIN;
    for (int i = 1; i <= n; i++) {
        q = max(q, p[i] + cut_rod(p, n - i));
    }
    return q;
}
int bottom_up_cut_rod(int p[], int n) {
    int r[n + 1];
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++) {
            q = max(q, p[i] + r[j - i]);
        }
        r[j] = q;
    }
    return r[n];
}
int memoized_cut_rod_aux(int p[], int n, int r[]) {
    if (r[n] >= 0){ return r[n]; }
    int q;
    if (n == 0){ q = 0; }
    else {
        q = INT_MIN;
        for (int i = 1; i <= n; i++) {
            q = max(q, p[i] + memoized_cut_rod_aux(p, n - i, r));
        }
    }
    r[n] = q;
    return q;
}
int memoized_cut_rod(int p[], int n) {
    int r[n + 1];
    for (int i = 0; i <= n; i++) { r[i] = INT_MIN; }
    int result = memoized_cut_rod_aux(p, n, r);
    printf("Subproblemele rezolvate (memorare):\n");
    print_array(r, n);
    return result;
}



