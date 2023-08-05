#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

float scanNum(char ch)
{
    int value;
    value = ch;
    return float(value - '0');
}
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return true;
    return false;
}

int isOperand(char ch)
{
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}

float operation(int a, int b, char op)
{
    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
        return b / a;
    else if (op == '^')
        return pow(b, a);
    else
        return INT_MIN;
}

float postfixEval(string postfix)
{
    int a, b;
    stack<float> stk;
    int len = postfix.length();

    for (int i = 0; i < len; i++)
    {
        if (isOperator(postfix[i]))
        {
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            stk.push(operation(a, b, postfix[i]));
        }
        else if (isOperand(postfix[i]))
        {
            stk.push(scanNum(postfix[i]));
        }
    }
    return stk.top();
}
int main()
{
    string post = "21+3*";
    // cin >> post;
    cout << postfixEval(post) << nl;
    return 0;
}