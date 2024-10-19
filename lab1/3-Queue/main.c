#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main() {
    Queue myQ;
    int size = 20;
    initQueue(&myQ, size);
    int e = -1;
    while (e != 0) {
        printf("Enter a node: ");
        scanf("%d", &e);
        enqueue(&myQ, e);
        printQueue(myQ);
    }
    while (!isEmpty(myQ)) {
        dequeue(&myQ);
        printQueue(myQ);
    }
    freeQueue(&myQ);
    printQueue(myQ);
    return 0;
}