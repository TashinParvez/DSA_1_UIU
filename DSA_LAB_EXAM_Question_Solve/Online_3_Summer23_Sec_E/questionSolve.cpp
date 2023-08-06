//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <iostream>
#define nl endl;
using namespace std;

struct SStackk
{
    char value;
    struct SStackk *next = NULL;
};

struct SStackk *top;

void push(char data)
{
    struct SStackk *newNode = (struct SStackk *)malloc(sizeof(struct SStackk));
    newNode->value = data;
    newNode->next = top;
    top = newNode;
}

char pop()
{
    if (top == NULL)
    {
        cout << "Stack is underFlow" << nl;
        return -1;
    }
    else
    {
        char data = top->value;
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

bool palindromeCheck(string s2)
{
    top = NULL;
    bool flag = true;
    int len2 = s2.size();
    //([(2*2)])
    // (((2+3)*4))
    //([2++]*2)
    //[]
    //({(9)-{3+9}})

    string s;
    int cnt = 0;
    for (int i = 0; i < len2; i++)
    {
        if (s2[i] >= '0' && s2[i] <= '9')
        {
            cnt++;
            s += s2[i];
        }
    }
    int len = s.size();
    if (len == cnt)
    {
        // cout << "correct len " << nl;
    }


    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (i == len / 2)
            {
                if (len % 2 == 0)
                {
                    char k = pop();
                    if (s[i] != k)
                    {
                        // cout << "Not a Palindrome" << endl;
                        return false;
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
                    // cout << "Not a Palindrome" << endl;
                    return false;
                }
            }
        }
    }

    // cout << "Palindrome" << endl;
    return true;
}

void valid_parentheses(string s)
{
    if (!palindromeCheck(s))
    {
        cout << "Invalid " << nl;
        cout << "From Palindrom " << nl;
        return;
    }

    top = NULL;
    bool flag = false;
    bool findOparator = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            flag = false;

            push(s[i]);
        }
        else if (s[i] == ')' && pop() == '(')
        {
            if (!flag || findOparator)
            {
                push(s[i]);
                // cout << "Check 1 " << nl;
                break;
            }
            continue;
        }
        else if (s[i] == '}' && pop() == '{')
        {
            if (!flag || findOparator)
            {
                push(s[i]);
                // cout << "Check 2 " << nl;
                break;
            }
            continue;
        }
        else if (s[i] == ']' && pop() == '[')
        {
            if (!flag || findOparator)
            {
                push(s[i]);
                // cout << "Check 3 " << nl;
                break;
            }

            continue;
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            findOparator = true;
            continue;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            findOparator = false;
            flag = true;
        }
        else
        {
            push(s[i]);
            // cout << "Check 5 " << nl;
            break;
        }
    }
    // ((4++1)*4)

    if (isEmpty())
    {
        cout << "Valid  " << nl;
    }
    else
    {
        cout << "Invalid  " << nl;
    }
}

int main()
{
    string s;
    while (cin >> s)
        valid_parentheses(s);

    return 0;
}