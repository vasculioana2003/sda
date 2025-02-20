#ifndef CUT_ROD_H
#define CUT_ROD_H

#include <stdio.h>
#include <limits.h>

// Declarații funcții
int cut_rod(int p[], int n);
int memoized_cut_rod(int p[], int n);
int memoized_cut_rod_aux(int p[], int n, int r[]);
int bottom_up_cut_rod(int p[], int n);

void read_prices(int p[], int n);
void print_array(int arr[], int n);
int max(int a, int b);

#endif
