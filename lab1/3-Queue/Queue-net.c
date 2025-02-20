#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int head;
    int tail;
    int length;
    int max_size;
    int* data;
} Queue;

int isFull(Queue queue){
    return (queue.tail + 1) % queue.max_size == queue.head; //daca tail+1 este egal cu head inseamna ca e plin
}

int isEmpty(Queue queue){
    return queue.head == -1; //este -1 deoaarece head si tail sunt initializate cu -1
}

void initQueue(Queue* queue, int size){
    queue->head = -1;
    queue->tail = -1;
    queue->length = 0;
    queue->data = (int*)malloc(size * sizeof(int));
    queue->max_size = size;
}

void freeQueue(Queue* queue){
    queue->head = -1;
    queue->tail = -1;
    queue->length = 0;
    free(queue->data);
    queue->data = NULL;
}

//adauga un element in tail-ul cozii
void enqueue(Queue *queue, int element){
    if (isFull(*queue)) {
        printf("!! Queue e plina\n");
        return;
    }
    if (queue->head == -1) {
        queue->head = 0;
    }
    queue->tail = (queue->tail + 1) % queue->max_size;
    queue->data[queue->tail] = element;
    printf("- Element %d inserted\n", element);
}

//sterge un element din head-ul cozii
int dequeue(Queue *queue){
    if (isEmpty(*queue)) {
        printf("queue e goala\n");
        return -1;
    }
    int element = queue->data[queue->head];
    if (queue->head == queue->tail) { //daca head si tail sunt egale inseamna ca e un singur element in coada
        queue->head = queue->tail = -1;
    }
    else {
        queue->head = (queue->head + 1) % queue->max_size;
    }
    return element;
}

void printQueue(Queue queue){
    if (isEmpty(queue)) {
        printf("- Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue.head;
    while (i != queue.tail) {
        printf("%d ", queue.data[i]);
        i = (i + 1) % queue.max_size;
    }
    printf("%d\n", queue.data[queue.tail]);
}

// Main function
int main(){
    // init queue
    Queue queue;
    int size;

    printf("Enter the max size of the queue: ");
    scanf("%d", &size);

    initQueue(&queue, size);

    int choice, element;
    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. printQueue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                break;
            case 2:
                element = dequeue(&queue);
                if (element != -1) {
                    printf("Element %d deleted\n", element);
                }
                break;
            case 3:
                printQueue(queue);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}




