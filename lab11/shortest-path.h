// shortest-path.h
#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H


typedef struct Node {
    int d;      // Distance from the source node
    int prev_index;     // Predecessor (index of predecessor node)
} Node;

// Struct to represent adjacency list node (for each edge)
typedef struct AdjNode {
    int dest;   // Destination node index
    int weight; // Weight of the edge
    struct AdjNode* next;
} AdjNode;

// Struct to represent an adjacency list
typedef struct {
    AdjNode* head; // Head of the adjacency list for a particular node 
} AdjList;

// Struct to represent the graph
typedef struct {
    int V;        // Number of vertices
    AdjList* array; // Array of adjacency lists
} GraphList;

// Function declarations
void init_single_source(GraphList* graph, Node* nodes, int s);
void relax(Node* u, Node* v, int weight, int vIndex);
void bellman_ford(GraphList* graph, int* weights, int s);
void dijkstra(GraphList* graph, int* weights, int s);
void print_result(Node* nodes, int V);

#endif
