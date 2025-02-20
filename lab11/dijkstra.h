#ifndef DIJKSTRA_H
#define DIJKSTRA_H

typedef struct Node {
    int d;      // Distance from the source node
    int prev_index;     // Predecessor (index of predecessor node)
};

// Struct to represent adjacency list node (for each edge)
typedef struct AdjNode {
    int dest;   // Destination node index
    int weight; // Weight of the edge
    struct AdjNode* next;
};

// Struct to represent an adjacency list
typedef struct AdjList{
    AdjNode* head; // Head of the adjacency list for a particular node 
};

// Struct to represent the graph
typedef struct GraphList {
    int V;        // Number of vertices
    AdjList* array; // Array of adjacency lists
};

// Function declarations
GraphList* create_graph(int V);
void add_edge(GraphList* graph, int src, int dest, int weight);
void read_graph(GraphList* graph);
void print_graph(GraphList* graph);
void init_single_source(GraphList* graph, Node* nodes, int s);
void relax(Node* u, Node* v, int weight, int vIndex);
void dijkstra(GraphList* graph, int* weights, int s);
void print_result(Node* nodes, int V);

#endif
