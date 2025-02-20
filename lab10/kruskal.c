#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "kruskal.h"




Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}


void sortEdges(Edge* edges, int E) { //* pentru ca este un vector
    for (int i = 0; i < E - 1; i++) { //i este nodul curent
        for (int j = i + 1; j < E; j++) {//j este nodul cu care comparam
            if (edges[i].weight > edges[j].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

// cauta setul in care se afla nodul i
int findSet(int *parents, int i) {//parents este vectorul de parinti, i este nodul
    if (parents[i] != i)
        parents[i] = findSet(parents, parents[i]);
    return parents[i];
}

void unionSets(int* parents, int* ranks, int x, int y) {
    int xroot = findSet(parents, x);
    int yroot = findSet(parents, y);

    if (xroot != yroot) {
        //se ordoneaza muchiile dupa cost si se incepe pe costul minim sa se faca un MST. cand se intalnesc 2 seturi cu parinte de rank egal devin un set si un parinte isi incrementeaza rankul
        if (ranks[xroot] < ranks[yroot])//se face cand xroot este mai mic decat yroot adica xroot este frunza
            parents[xroot] = yroot;
        else if (ranks[xroot] > ranks[yroot])//se face cand xroot este mai mare decat yroot adica yroot este frunza
            parents[yroot] = xroot;
        else {//se face cand xroot si yroot au aceeasi inaltime
            parents[yroot] = xroot;
            ranks[xroot]++;
        }
    }
}

void kruskalMST(Graph* graph) {
    int V = graph->V;
    Edge* edges = graph->edges;
    int* parents = (int*)malloc((V + 1) * sizeof(int));
    int* ranks = (int*)malloc((V + 1) * sizeof(int)); //rank reprezinta inaltimea arborelui //rank ii vectorul de inaltimi // incepe de la 1 pt ca nodurile incep de la 1

    // Sort edges by weight
    sortEdges(edges, graph->E);

    // un vector de parinti si un vector de rankuri
    for (int i = 1; i <= V; i++) { // incepe de la 1 pt ca nodurile incep de la 1
        parents[i] = i;
        ranks[i] = 0;
    }

    // Process edges
    printf("Edges in the MST:\n");
    for (int i = 0; i < graph->E; i++) { //incepe de la 0 pt ca vectorul de muchii incepe de la 0
        int x = findSet(parents, edges[i].src);
        int y = findSet(parents, edges[i].dest);

        if (x != y) { 
            printf(
                "%d -- %d == %d\n", 
                edges[i].src, 
                edges[i].dest, 
                edges[i].weight
            );
            unionSets(parents, ranks, x, y);
        }
    }

    free(parents);
    free(ranks);
}
