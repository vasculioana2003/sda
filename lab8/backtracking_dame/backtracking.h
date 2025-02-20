#ifndef BACKTRACKING_H
#define BACKTRACKING_H

// Funcții principale
void dame_iterativ(int n);
void dame_recursiv(int x[], int n, int k);

// Funcții auxiliare
int se_ataca(int x[], int pos);
void tipareste_solutie(int x[], int n);
void reset_nr_sol();
void print_nr_sol();

extern int nr_sol; 

#endif