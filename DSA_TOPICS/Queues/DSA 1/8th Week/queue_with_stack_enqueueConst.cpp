#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() { top=-1; }

    void push(int x) {
        if (top == MAX_SIZE - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            std::cout << "Stack Underflow\n";
            return -1; // Return some invalid value to indicate an error
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

class QueueUsingStacks {
private:
    Stack stack_enqueue;
    Stack stack_dequeue;

public:
    void enqueue(int x) {
        stack_enqueue.push(x);
    }

    int dequeue() {
        if (stack_dequeue.isEmpty()) {
            // Move all elements from the enqueue stack to the dequeue stack
            while (!stack_enqueue.isEmpty()) {
                stack_dequeue.push(stack_enqueue.pop());
            }
        }

        if (stack_dequeue.isEmpty()) {
            std::cout << "Queue is empty, cannot dequeue.\n";
            return -1; // Return some invalid value to indicate an error
        }

        return stack_dequeue.pop();
    }

    bool isEmpty() {
        return stack_enqueue.isEmpty() && stack_dequeue.isEmpty();
    }
};

int main() {
    QueueUsingStacks queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Dequeue: " << queue.dequeue() << std::endl; // Output: 1
    std::cout << "Dequeue: " << queue.dequeue() << std::endl; // Output: 2
    std::cout << "Is Empty: " << (queue.isEmpty() ? "true" : "false") << std::endl; // Output: false
    std::cout << "Dequeue: " << queue.dequeue() << std::endl; // Output: 3
    std::cout << "Is Empty: " << (queue.isEmpty() ? "true" : "false") << std::endl; // Output: true

    return 0;
}
