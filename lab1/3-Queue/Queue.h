#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct Queue {
    int head;
    int tail;
    int length;
    /**
     * The data is a pointer to the first element of the array.
     */
    int *data;
} Queue;

/** Initializes the queue */
void initQueue(Queue* queue, int size);

/** Makes the queue empty */
void freeQueue(Queue* queue);

void printQueue(Queue queue);

bool isEmpty(Queue queue);

void enqueue(Queue* queue, int value);

int dequeue(Queue* queue);

#endif
