#ifndef KRUSKAL_H
#define KRUSKAL_H

// structura pentru nodurile grafului


// Structure for edges in Kruskal's algorithm
typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V, E; // nr de noduri, nr de muchii
    Edge* edges;
} Graph;


// Function declarations for Kruskal's algorithm
Graph* createGraph(int V, int E);
void kruskalMST(Graph* graph);
void sortEdges(Edge* edges, int E);
int findSet(int* parents, int i);
void unionSets(int* parent, int* rank, int x, int y);



#endif // KRUSKAL_PRIM_H
