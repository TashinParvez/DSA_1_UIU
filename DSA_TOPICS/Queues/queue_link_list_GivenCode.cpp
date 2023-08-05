#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return some invalid value to indicate an error
    }

    int item = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) // If the queue became empty after dequeue
        initializeQueue(q);

    return item;
}

int front(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1; // Return some invalid value to indicate an error
    }

    return q->front->data;
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeue: %d\n", dequeue(&queue)); // Output: 1
    printf("Dequeue: %d\n", dequeue(&queue)); // Output: 2
    printf("Is Empty: %s\n", isEmpty(&queue) ? "true" : "false"); // Output: false
    printf("Dequeue: %d\n", dequeue(&queue)); // Output: 3
    printf("Is Empty: %s\n", isEmpty(&queue) ? "true" : "false"); // Output: true

    return 0;
}
