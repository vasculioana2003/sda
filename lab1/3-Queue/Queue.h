#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct Queue {
    int head;
    int tail;
    int length;
    /** a pointer to the first elem of the array.*/
    int *data;
} Queue;

/** Initializes the queue */
void initQueue(Queue* queue, int size);
void freeQueue(Queue* queue);
void printQueue(Queue queue);
bool isEmpty(Queue queue);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);

#endif










typedef struct Queue{
    int head;
    int tail;
    int length;
    int* data;
}Queue;


void initQueue(Queue* queue, int size){
    queue->head=0;
    queue->tail=0;
    queue->length=size;
    queue->data = (int*)malloc(size*sizeof(int));
}

void freeQueue(Queue* queue){
    queue->head=-1;
    queue->tail=-1;
    queue->size=0
    free(queue->data);
    queue->data = NULL;
}

bool isEmpty(Queue queue){
    return queue.length == 0;
}

void printQueue(Queue queue){
    if(isEmpty(queue)){
        printf("Queue is empty!\n");
        return;
    }
    for (int i=queue.head; i<queue.tail; i++){
        printf("%d", queue.data[i]);
    }
    printf("\n");
}


void enqueue(Queue* queue, int value){
    queue->data[queue->tail] = value;
    queue->length = queue->length + 1;
    if(queue->tail == queue->length){
        queue->tail=0
    }else{
        queue->tail = queue->tail+1;
    }
}

