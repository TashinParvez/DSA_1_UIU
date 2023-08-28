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

int popEnd()
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

int poipMagic()
{
    // if ((top+1) % 2 == 0)
    // {
    //     cout << " ËVEN " << nl;
    // }
    // else
    // {
    //     cout << " Odd " << nl;
    // }

    if ((top + 1) % 2 == 0)
    {
        // cout << " ËVEN " << nl;

        int n = (top + 1) / 2;
        vector<int> vec;
        int i;
        for (i = top; i > n; i--)
        {
            vec.push_back(stackk[i]);
            pop();
        }
        int result = stackk[i];

        int len = vec.size() / vec[0];
        int arr[len];
        len--;
        for (auto ii : vec)
        {
            arr[len] = ii;
            len--;
        }
        for (auto ii : arr)
        {
            push(ii);
        }

        return result;
    }
    else
    {
        //     cout << " Odd " << nl;
        int n = (top) / 2; // 1
        vector<int> vec;
        int i;
        for (i = top; i > n; i--)
        {
            vec.push_back(stackk[i]);
            pop();
        }
        int result = stackk[i];

        int len = vec.size() / vec[0];
        int arr[len];
        len--;
        for (auto ii : vec)
        {
            arr[len] = ii;
            len--;
        }
        for (auto ii : arr)
        {
            push(ii);
        }

        return result;
    }
}

int main()
{
    top = -1;
    push(20);
    push(1);
    push(15);

    // cout<<     popEnd();
    printStack();
    cout << nl;
    cout << popEnd();
    cout << nl;
    printStack();
    cout << nl;
    cout << popEnd();
    printStack();
    cout << nl;

    return 0;
}
