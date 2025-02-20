#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "prim.h"

//v=nr de noduri
GraphList* INIT_LISTA(int V) {
    GraphList* graph = (GraphList*)malloc(sizeof(GraphList));
    graph->V = V;
    graph->array = (AdjList*)malloc((V + 1) * sizeof(AdjList)); //plus 1 pentru ca nodurile incep de la 1
    for (int i = 1; i <= V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void INSERT_VECIN(GraphList* graph,int src,int dest,int weight) {
    AdjNode* newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = graph->array[src].head;//inserarea se face la inceputul listei
    graph->array[src].head = newNode;//noul nod devine capul listei
}

//printeaza graful sub forma de lista de adiacenta
void PRINT_LISTA(GraphList* graph) {
    for (int i = 1; i <= graph->V; i++) { // incepem de la 1 pentru ca nodurile incep de la 1
        AdjNode* pCrawl = graph->array[i].head;
        printf("Nod %d: ", i);
        while (pCrawl) {
            printf("-> (%d, %d)", pCrawl->dest, pCrawl->weight);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void freeGraph(GraphList* graph) {
    for (int i = 1; i <= graph->V; i++) {
        AdjNode* current = graph->array[i].head;
        while (current) {
            AdjNode* aux = current->next;
            free(current);
            current = aux;
        }
    }
    //le face separat deoarece array e un vector dinamic si nu stie cat de mare e
    free(graph->array); // elibereaza vectorul de liste de adiacenta
    free(graph); // elibereaza graful
}



// Prim's Algorithm implementation
void primMST(GraphList* graph, int start) {
    int V = graph->V;
    int* mstParent = (int*)malloc((V + 1) * sizeof(int));
    int* minWeight = (int*)malloc((V + 1) * sizeof(int));
    int* inMST = (int*)malloc((V + 1) * sizeof(int)); // pentru a verifica daca un nod este deja in MST

    // initializam minWeight si mstParent pentru toate nodurile
    for (int i = 1; i <= V; i++) {
        minWeight[i] = INT_MAX; // initializam toate greutatile cu infinit pentru a gasi minimul
        mstParent[i] = -1;
        inMST[i] = 0;
    }
    minWeight[start] = 0; // Start with the given node

    // itereaza pana cand toate nodurile sunt incluse in MST
    for (int count = 1; count < V; count++) {
        int mindest = INT_MAX, u = -1; //mindest = greutatea minima, u = nodul cu greutatea minima
        for (int v = 1; v <= V; v++) {//cautam nodul cu greutatea minima
            if (!inMST[v] && minWeight[v] < mindest) {  //v nu e in MST si greutatea lui e mai mica decat minimul
                mindest = minWeight[v];
                u = v;
            }
        }

        // Include the selected vertex in MST
        inMST[u] = 1;

        // actualizeaza minWeight si mstParent pentru nodurile adiacente ale nodului selectat
        AdjNode* pCrawl = graph->array[u].head;
        while (pCrawl) {
            int v = pCrawl->dest; // dest reprezinta nodul adiacent, adica vecinul
            if (!inMST[v] && pCrawl->weight < minWeight[v]) {
                minWeight[v] = pCrawl->weight;
                mstParent[v] = u;
            }
            pCrawl = pCrawl->next;
        }
    }

    // Print the MST
    printf("Prim MST edges:\n");
    for (int i = 1; i <= V; i++) {
        if (mstParent[i] != -1) {
            printf("%d -- %d == %d\n", mstParent[i], i, minWeight[i]);
        }
    }

    // Free the allocated memory
    free(mstParent);
    free(minWeight);
    free(inMST);
}