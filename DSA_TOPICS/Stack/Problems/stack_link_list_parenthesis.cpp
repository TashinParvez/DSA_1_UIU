#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

struct Node *top;

void push(int data)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = data;
    temp->next = top;
    top = temp;
}

int pop()
{
    struct Node *temp;
    int data;
    if (top == NULL)
    {
        return 0;
    }
    else
    {
        data = top->value;
        temp = top;
        top = top->next;
        free(temp);
        return data;
    }
}

int main()
{
    string s;
    cout << "Enter a string : ";
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(s[i]);
        }
        else
        {
            if (s[i] == ')' && pop() != '(')
            {
                cout << "Invalid" << endl;
                return 0;
            }
            if (s[i] == '}' && pop() != '{')
            {
                cout << "Invalid" << endl;
                return 0;
            }
            if (s[i] == ']' && pop() != '[')
            {
                cout << "Invalid" << endl;
                return 0;
            }
        }
    }

    cout << "Valid" << endl;

    return 0;
}
