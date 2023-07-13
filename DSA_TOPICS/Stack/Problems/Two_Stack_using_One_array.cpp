//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    13-07-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
using namespace std;

class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;

    TwoStack(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int data)
    {
        if (top2 - top1 > 0)
        {
            top1++;
            arr[top1] = data;
        }
        else
        {
            cout << "This stack is overFlow" << nl;
        }
    }
    void push2(int data)
    {
        if (top2 - top1 > 0)
        {
            top2--;
            arr[top2] = data;
        }
        else
        {
            cout << "This stack is overFlow" << nl;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            cout << "This Stack is UnderFlow" << nl;
        }
        return -1;
    }
    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            cout << "This Stack is UnderFlow" << nl;
        }
        return -1;
    }
};
int main()
{

    CRACKED;
}