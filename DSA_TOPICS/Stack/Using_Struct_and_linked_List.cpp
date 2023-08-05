//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

struct SStackk
{
    int value;
    struct SStackk *next = NULL;
};

struct SStackk *top;

int push(int data)
{
    struct SStackk *newNode = (struct SStackk *)malloc(sizeof(struct SStackk));
    newNode->value = data;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (top == NULL)
    {
        cout << "Stack is underFlow" << nl;
        return -1;
    }
    else
    {
        int data = top->value;
        struct SStackk *temp = (struct SStackk *)malloc(sizeof(struct SStackk));
        temp = top;
        top = top->next;
        free(temp);
        return data;
    }
}
void printStackk()
{
    struct SStackk *traveller = (struct SStackk *)malloc(sizeof(struct SStackk));

    traveller = top;
    if (traveller == NULL)
    {
        printf("Stack is empty\n");
    }
    while (traveller != NULL)
    {
        cout << traveller->value << " ";
        traveller = traveller->next;
    }
}
bool isEmpty()
{
    if (top == NULL)
        return true;
    return false;
}

int main()
{
    top = NULL;

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printStackk();

    return 0;
}
