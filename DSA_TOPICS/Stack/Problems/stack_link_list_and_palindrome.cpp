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
        printf("\n Stack Underflow");
        exit(1);
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

    // getline(cin, s);

    bool flag = true;
    int len = s.size();

    // string sp;  // line
    // for (int i = 0; i < len; i++)
    // {
    //     if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
    //     {
    //         if ((s[i] >= 'A' && s[i] <= 'Z'))
    //         {
    //             s[i] = tolower(s[i]);
    //             // cout << s[i] << nl;
    //         }
    //         sp += s[i];
    //     }
    // }
    // s = sp;

    len = s.size();

    for (int i = 0; i < len; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            if ((s[i] >= 'A' && s[i] <= 'Z'))
            {
                s[i] = tolower(s[i]);
            }
            if (i == len / 2)
            {
                if (len % 2 == 0)
                {
                    char k = pop();
                    if (s[i] != k)
                    {
                        // cout << "s and k " << s[i] << " " << k << endl;
                        cout << "Not a Palindrome" << endl;
                        return 0;
                    }
                }
                flag = false;
            }
            else if (flag)
            {
                push(s[i]);
            }
            else
            {
                if (s[i] != pop())
                {
                    cout << "Not a Palindrome" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Palindrome" << endl;

    return 0;
}
