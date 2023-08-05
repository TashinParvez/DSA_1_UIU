#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

#define MAX_SIZE 100

typedef struct Queuee
{
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q) 
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

int isFull(Queue *q)
{
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue *q, int item)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(q))
        q->front = 0;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->arr[q->rear] = item;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return some invalid value to indicate an error
    }

    int item = q->arr[q->front];
    if (q->front == q->rear)
        initializeQueue(q);
    else
        q->front = (q->front + 1) % MAX_SIZE;

    return item;
}

int front(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1; // Return some invalid value to indicate an error
    }

    return q->arr[q->front];
}

int main()
{
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeue: %d\n", dequeue(&queue));                     // Output: 1
    printf("Dequeue: %d\n", dequeue(&queue));                     // Output: 2
    printf("Is Empty: %s\n", isEmpty(&queue) ? "true" : "false"); // Output: false
    printf("Dequeue: %d\n", dequeue(&queue));                     // Output: 3
    printf("Is Empty: %s\n", isEmpty(&queue) ? "true" : "false"); // Output: true

    return 0;
}