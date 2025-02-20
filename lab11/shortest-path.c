// shortest-path.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shortest-path.h"

#define INF INT_MAX
#define NIL -1

// Initialize all nodes' distances and predecessors
void init_single_source(GraphList* graph, Node* nodes, int s) {
    int V = graph->V;
    for (int i = 0; i < V; i++) {
        nodes[i].d = INF;
        nodes[i].prev_index = NIL; // NIL represented by -1
    }
    nodes[s].d = 0;  // Set source node distance to 0
}

// Relaxation function (used in both Bellman-Ford and Dijkstra)
void relax(Node* u, Node* v, int weight, int vIndex) {
    if (v->d > u->d + weight) {
        v->d = u->d + weight;
        v->prev_index = vIndex; // Store the index of the predecessor node directly
    }
}

void bellman_ford(GraphList* graph, int* weights, int s) {
    int V = graph->V;
    Node* nodes = (Node*)malloc(V * sizeof(Node));

    init_single_source(graph, nodes, s);

    // Relax edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int u = 0; u < V; u++) {
            AdjNode* pCrawl = graph->array[u].head;
            while (pCrawl) {
                relax(&nodes[u], &nodes[pCrawl->dest], pCrawl->weight, u); // Pass u as vIndex
                pCrawl = pCrawl->next;
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; u++) {
        AdjNode* pCrawl = graph->array[u].head;
        while (pCrawl) {
            if (nodes[pCrawl->dest].d > nodes[u].d + pCrawl->weight) {
                printf("Graph contains a negative weight cycle\n");
                free(nodes);
                return;
            }
            pCrawl = pCrawl->next;
        }
    }

    // Print the results
    printf("Bellman-Ford shortest distances from node %d:\n", s);
    print_result(nodes, V);

    free(nodes);
}

void dijkstra(GraphList* graph, int* weights, int s) {
    int V = graph->V;
    Node* nodes = (Node*)malloc(V * sizeof(Node));
    int* visited = (int*)malloc(V * sizeof(int));

    init_single_source(graph, nodes, s);

    // Initialize visited array
    for (int i = 0; i < V; i++) visited[i] = 0;

    while (1) {
        // Extract the vertex with the smallest distance
        int minDist = INF, u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && nodes[i].d < minDist) {
                minDist = nodes[i].d;
                u = i;
            }
        }

        if (u == -1) break; // All nodes processed

        visited[u] = 1;

        // Relax all neighbors of u
        AdjNode* pCrawl = graph->array[u].head;
        while (pCrawl) {
            relax(&nodes[u], &nodes[pCrawl->dest], pCrawl->weight, u); // Pass u as vIndex
            pCrawl = pCrawl->next;
        }
    }

    // Print the results
    printf("Dijkstra shortest distances from node %d:\n", s);
    print_result(nodes, V);

    free(nodes);
    free(visited);
}

// Print the shortest path results (distances and predecessors)
void print_result(Node* nodes, int V) {
    for (int i = 0; i < V; i++) {
        printf("Node %d: Distance = %d, Predecessor = %d\n", i, nodes[i].d, nodes[i].prev_index);
    }
}
