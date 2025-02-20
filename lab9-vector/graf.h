
#ifndef GRAF_H
#define GRAF_H

typedef struct nod_lista {
    enum{white, gray, black} color;
    int d, f; // timpul de descoperire si timpul de finalizare pentru DFS
    int cheie;
    struct nod_lista *next, *prev;
}t_nod_lista;

typedef struct {
    t_nod_lista *head;
}t_lista;

t_nod_lista *list_search(t_lista L, int key);
void mark_visited(t_lista g[], int n, int key);
void bfs(t_lista g[], int s, int n);
void print_path(t_lista g[], t_nod_lista *s, t_nod_lista *v);
void init_lista(t_lista g[], int n);
void insert_vecini(t_lista g[], int n, int ns);
void print_lista(t_lista g[], int n);
void makenull(t_lista *L);
void list_insert(t_lista *L, t_nod_lista *x);
void dfs(t_lista g[], int n);
void dfs_visit(t_lista g[], t_nod_lista *u, int n, int time);
void dfs_visit_top(t_lista g[],t_nod_lista *u,int time,t_lista topo,int n);
t_lista top_sort(t_lista g[], int n);
void list_print(t_lista L);

#endif //GRAF_H






