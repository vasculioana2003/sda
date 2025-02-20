#include <stdio.h>
#include <stdlib.h>
#include "prim.h"
#include "kruskal.h"

int main() {
    Graph* kruskalGraph;
    GraphList* primGraph;

    int n = 9; // Number of nodes (1 to 9)
    int edges[][3] = {
        {1, 8, 8}, {1, 2, 4}, 
        {2, 3, 8}, {2, 8, 4}, 
        {3, 4, 7}, {3, 6, 4}, {3, 9, 2}, {3, 2, 8}, 
        {4, 5, 9}, {4, 6, 14}, {4, 3, 7}, 
        {5, 6, 10}, {5, 4, 9},
        {6, 7, 2}, {6, 3, 4}, {6, 4, 14}, {6, 5, 10}, 
        {7, 8, 1}, {7, 9, 6}, {7, 6, 2},
        {8, 1, 8}, {8, 2, 4}, {8, 9, 7}, {8, 7, 1}, 
        {9, 8, 7}, {9, 3, 2}, {9, 7, 6}
    };
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    primGraph = INIT_LISTA(n);
    kruskalGraph = createGraph(n, 0);

    // Add edges to both graphs
    for (int i = 0; i < edgeCount; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        int weight = edges[i][2];

        // Add edge to Prim's adjacency list
        INSERT_VECIN(primGraph, from, to, weight);

        // Add edge to Kruskal's edge list
        kruskalGraph->edges = realloc(
            kruskalGraph->edges, 
            (kruskalGraph->E + 1) * sizeof(Edge)
        );
        kruskalGraph->edges[kruskalGraph->E++] = (Edge){
            from, to, weight
        };
    }

    printf("Lista adiacenta:\n");
    PRINT_LISTA(primGraph);

    printf("Kruskal:\n");
    kruskalMST(kruskalGraph);

    printf("Prim:\n");
    primMST(primGraph, 1);
    
    return 0;
}
