#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
} CircularQueue;

void initializeQueue(CircularQueue *cq) {
    cq->front = -1;
    cq->rear = -1;
    cq->size = 0;
}

int isEmpty(CircularQueue *cq) {
    return cq->size == 0;
}

int isFull(CircularQueue *cq) {
    return cq->size == MAX_SIZE;
}

void enqueue(CircularQueue *cq, int item) {
    if (isFull(cq)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(cq)) {
        cq->front = 0;
        cq->rear = 0;
    } else {
        cq->rear = (cq->rear + 1) % MAX_SIZE;
    }
    cq->arr[cq->rear] = item;
    cq->size++;
}

int dequeue(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return some invalid value to indicate an error
    }

    int item = cq->arr[cq->front];
    if (cq->front == cq->rear) {
        initializeQueue(cq);
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }
    cq->size--;

    return item;
}

int front(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return -1; // Return some invalid value to indicate an error
    }

    return cq->arr[cq->front];
}

int main() {
    CircularQueue cq;
    initializeQueue(&cq);

    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);

    printf("Dequeue: %d\n", dequeue(&cq)); // Output: 1
    printf("Dequeue: %d\n", dequeue(&cq)); // Output: 2
    printf("Is Empty: %s\n", isEmpty(&cq) ? "true" : "false"); // Output: false
    printf("Dequeue: %d\n", dequeue(&cq)); // Output: 3
    printf("%s\n", isEmpty(&cq) ? "true" : "false"); // Output: true

    return 0;
}

