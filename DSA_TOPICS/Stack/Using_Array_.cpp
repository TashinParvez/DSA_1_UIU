#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

int stackk[100]; // LIFO
int top;

void push(int value)
{
    if (top >= 99)
    {
        cout << "STACK over flow" << nl;
    }
    else
    {
        top++;
        stackk[top] = value;
    }
}

int pop()
{
    int value;
    if (top < 0)
    {
        cout << "Stack under flow" << nl;
        return -1;
    }
    else
    {
        value = stackk[top];
        top--;
        return value;
    }
}

void printStack()
{
    for (int i = 0; i <= top; i++)
    {
        cout << stackk[i] << " ";
    }
}

int main()
{
    top = -1;
    push(20);
    push(1);
    push(15);

    pop();
    pop();
    pop();
    pop();

    return 0;
}
