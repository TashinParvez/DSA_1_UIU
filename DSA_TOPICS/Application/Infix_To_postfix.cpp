//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl
using namespace std;

string s2 = "";

void handleExpressions(stack<char> &expressions, char c)
{
    if (expressions.empty() || c == '(' || c == '^')
    {
        expressions.push(c);
    }
    else
    {
        if (c == ')')
        {
            while (expressions.top() != '(')
            {
                // if (expressions.empty())
                //     break;
                s2 += expressions.top();
                // cout << s2 << nl;
                // cout << expressions.top();
                expressions.pop();
            }
            expressions.pop();
        }
        else if (c == '+' || c == '-')
        {
            while (expressions.empty() != 1) // pop all elements from the stack
            {
                if (expressions.top() == '(')
                    break;
                s2 += expressions.top();
                // cout << s2 << nl;
                // cout << expressions.top();
                expressions.pop();
            }
            expressions.push(c);
        }
        else
        {
            if (expressions.top() == '+' || expressions.top() == '-')
            {
                expressions.push(c);
            }
            else
            {
                while (expressions.top() == '*' || expressions.top() == '/' || expressions.top() == '^')
                {
                    if (expressions.empty() || expressions.top() == '(')
                        break;
                    s2 += expressions.top();
                    // cout << s2 << nl;
                    // cout << expressions.top();
                    expressions.pop();
                }
                // cout << "Working for " << c << nl;
                expressions.push(c);
            }
        }
    }
}

int32_t main()
{
    cout << "Enter Your infix expression : ";
    string s;
    cin >> s;

    // in:   8*(5^4+2)-6^2/(9*3)
    // post: 854^2+*62^93*/-

    // in:   9+2-5*6/3+2^3/4
    // post: 92+56*3/-23^4/+
    // ans 3

    // in:   1+3^2+(5*6-4)*7
    // post: 132^+56*4-7*+

    stack<char> expressions;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            // cout << "INPUT  " << s[i] << nl;
            s2 += s[i];
            // cout << s2 << nl;
            // cout << s[i];
        }
        else
        {
            // cout << "INPUT  " << s[i] << nl;
            handleExpressions(expressions, s[i]);
        }
    }
    while (expressions.empty() != 1)
    {
        s2 += expressions.top();
        // cout << s2 << nl;
        // cout << expressions.top();
        expressions.pop();
    }

    cout << nl << "Your postfix expression : " << s2 << nl << nl;

    CRACKED;
}
