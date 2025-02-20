// dijkstra.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dijkstra.h"

GraphList* create_graph(int V) {
    GraphList* graph = (GraphList*)malloc(sizeof(GraphList));
    graph->V = V;
    graph->array = (AdjList*)malloc((V + 1) * sizeof(AdjList));

    for (int i = 1; i <= V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}


// Add an edge to the graph
void add_edge(GraphList* graph, int src, int dest, int weight) {
    AdjNode* new_node = (AdjNode*)malloc(sizeof(AdjNode));
    new_node->dest = dest;
    new_node->weight = weight;
    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;
}

// Function to read the graph from user input
void read_graph(GraphList* graph) {
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        add_edge(graph, src, dest, weight);
    }
}

// Function to print the graph (adjacency list)
void print_graph(GraphList* graph) {
    for (int i = 1; i <= graph->V; i++) { //incepe de la 0 pentru ca array-ul de liste de adiacenta incepe de la 0
        printf("Node %d: ", i);
        AdjNode* pCrawl = graph->array[i].head;
        while (pCrawl) {
            printf(" -> %d (weight %d)", pCrawl->dest, pCrawl->weight);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Initialize all nodes' distances and predecessors
void init_single_source(GraphList* graph, Node* nodes, int s) { // s = source node
    int V = graph->V;
    for (int i = 1; i <= V; i++) {
        nodes[i].d = INT_MAX;
        nodes[i].prev_index = -1;
    }
    nodes[s].d = 0;  // Set source node distance to 0
}

// Relaxation function (used in both Bellman-Ford and Dijkstra)
void relax(Node* src, Node* dest, int weight, int vIndex) {
    if (dest->d > src->d + weight) {
        dest->d = src->d + weight;
        dest->prev_index = vIndex; // Store the index of the predecessor node directly
    }
}

void dijkstra(GraphList* graph, int* weights, int s) {
    int V = graph->V;
    Node* nodes = (Node*)malloc((V + 1) * sizeof(Node));
    int* visited = (int*)malloc((V + 1) * sizeof(int));

    init_single_source(graph, nodes, s);

    // Initialize visited array
    for (int i = 1; i <= V; i++) visited[i] = 0;

    while (1) {
        // Extract the vertex with the smallest distance
        int minDist = INT_MAX, u = -1;
        for (int i = 1; i <= V; i++) {
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
    for (int i = 1; i <= V; i++) {
        printf("Node %d: Distance = %d, Predecessor = %d\n", i, nodes[i].d, nodes[i].prev_index);
    }
}
