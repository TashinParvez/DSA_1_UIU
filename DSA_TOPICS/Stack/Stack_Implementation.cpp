//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "This stack us Overflow" << nl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "This Stack is UnderFlow" << nl;
        }
    }
    int peek()
    {
        if (top < 0)
        {
            cout << "This stack is empty" << nl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        if (top < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s(5);
    s.push(12);
    s.push(24);

    cout << s.peek() << nl;
    s.pop();
    cout << s.peek() << nl;
    cout << s.empty() << nl;
    s.empty() == 0 ? cout << "False" << nl : cout << "True" << nl;

    CRACKED;
}
