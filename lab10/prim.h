#ifndef PRIM_H
#define PRIM_H


typedef struct AdjNode {
    int dest, weight; //  weight = costul muchiei
    struct AdjNode* next;
} AdjNode;

typedef struct AdjList {
    AdjNode* head;
} AdjList;

typedef struct GraphList {
    int V; // Number of vertices
    AdjList* array;
} GraphList;




GraphList* INIT_LISTA(int V);
void INSERT_VECIN(GraphList* graph, int src, int dest, int weight);
void PRINT_LISTA(GraphList* graph);
void freeGraph(GraphList* graph);
void primMST(GraphList* graph, int start);







#endif 

