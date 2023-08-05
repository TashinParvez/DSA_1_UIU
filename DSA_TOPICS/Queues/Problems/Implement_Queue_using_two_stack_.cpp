#include <iostream>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

/*

implement enqueue and dequeue using only two stacks

STEP 1 − We have two stacks, one for enqueueing and one for dequeueing.

STEP 2 − We enqueue by pushing onto the enqueue stack.

STEP 3 − We dequeue by popping from the dequeue stack.

STEP 4 − If the dequeue stack is empty, we pop everything from the enqueue stack and push it onto the dequeue stack.

STEP 5 − This reverses the order so that the oldest item is now at the top of the dequeue stack.


*/

class Stack // normal stack
{
private:
    static const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return -1; // Return some invalid value to indicate an error
        }
        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class QueueUsingStacks
{
private:
    Stack stack_enqueue;
    Stack stack_dequeue;

public:
    void enqueue(int x)
    {
        stack_enqueue.push(x);
    }

    int dequeue()
    {
        if (stack_dequeue.isEmpty())
        {
            // Move all elements from the enqueue stack to the dequeue stack
            while (!stack_enqueue.isEmpty())
            {
                stack_dequeue.push(stack_enqueue.pop());
            }
        }

        if (stack_dequeue.isEmpty())
        {
            cout << "Queue is empty, cannot dequeue.\n";
            return -1; // Return some invalid value to indicate an error
        }

        return stack_dequeue.pop();
    }

    bool isEmpty()
    {
        return stack_enqueue.isEmpty() && stack_dequeue.isEmpty();
    }
};

int main()
{
    QueueUsingStacks queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Dequeue: " << queue.dequeue() << endl;                       // Output: 1
    cout << "Dequeue: " << queue.dequeue() << endl;                       // Output: 2
    cout << "Is Empty: " << (queue.isEmpty() ? "true" : "false") << endl; // Output: false
    cout << "Dequeue: " << queue.dequeue() << endl;                       // Output: 3
    cout << "Is Empty: " << (queue.isEmpty() ? "true" : "false") << endl; // Output: true

    return 0;
}
