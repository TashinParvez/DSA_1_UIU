#include <stdio.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

struct Stack
{
    int top;
    int array[MAXSIZE];
} st;

void initialize()
{
    st.top = -1;
}

int isFull()
{
    if (st.top >= MAXSIZE - 1)
        return TRUE;
    else
        return FALSE;
}
// checking whether the stack is empty or not
int isEmpty()
{
    if (st.top == -1)
        return TRUE;
    else
        return FALSE;
}

// function to push the element into the stack.
void push(int num)
{
    if (isFull())
        printf("Stack is Full...\n");
    else
    {
        st.array[st.top + 1] = num;
        st.top++;
    }
}

// function to pop the element from the stack
int pop()
{
    if (isEmpty())
        printf("Stack is Empty...\n");
    else
    {
        st.top = st.top - 1;
        return st.array[st.top + 1];
    }
}

 void printStack()
{
     if (!isEmpty())
    {
        int temp = pop();
        printStack();
        printf(" %d ", temp);
        push(temp);
    }
}

void insertAtBottom(int item)
{
    if (isEmpty())
    {
        push(item);
    }
    else
    {
        int top = pop();
        insertAtBottom(item);
        push(top);
    }
}

void reverse()
{
    if (!isEmpty())
    {
        int top = pop();
        reverse();
        insertAtBottom(top);
    }
}

int getSize()
{
    return st.top + 1;
}

int main()
{
    // St st;
    initialize(st);
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printf("Original Stack\n");
    printStack();

    reverse();
    printf("\nReversed Stack\n");
    printStack(); // calling printStack() method
    return 0;
}