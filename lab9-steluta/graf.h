#ifndef GRAF_H
#define GRAF_H

#include <limits.h>

typedef struct t_nod_lista{
    int cheie;
    enum {white, gray, black} color;
    int d; // Distance
    int f; // Finish time (for DFS)
    struct t_nod_lista *prev;
    struct t_nod_lista *next;
} t_nod_lista;

typedef struct {
    t_nod_lista *head;
} t_lista;

void makenull(t_lista *L);
t_nod_lista *list_search(t_lista L, int key);
void mark_visited(t_lista *g, int n, int key);
void list_delete(t_lista *L, t_nod_lista *x);
void print_path(t_lista *g, t_nod_lista *s, t_nod_lista *v);
void init_lista(t_lista *g, int n);
void insert_vecini(t_lista *g, int n, int ns);
void print_graf(t_lista *g, int n);
void bfs(t_lista *g, int s, int n);
void list_print(t_lista L);
void list_insert(t_lista *L, t_nod_lista *x);
void dfs_visit(t_lista *g, t_nod_lista *u, int n, int time);
void dfs(t_lista *g, int n);
void dfs_visit_top(t_lista *g, t_nod_lista *u, int time, t_lista topo, int n);
t_lista top_sort(t_lista *g, int n);

#endif




