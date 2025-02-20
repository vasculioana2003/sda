// main.c
#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

int main() {
    int V;

    // User input for the number of vertices
    printf("Enter the number of nodes (vertices): ");
    scanf("%d", &V);

    // Create the graph based on user input
    GraphList* graph = create_graph(V);

    // Read the graph data (edges and weights)
    read_graph(graph);

    // Print the graph's adjacency list
    printf("Graph (Adjacency List):\n");
    print_graph(graph);

    // Run Bellman-Ford algorithm from node 0
    bellman_ford(graph, NULL, 0);

    // Run Dijkstra algorithm from node 0
    dijkstra(graph, NULL, 0);

    // Free memory
    free(graph->array);
    free(graph);

    return 0;
}
