//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define CRACKED return 0;
#define nl endl; // NewLine

#define output(x) cout << x << nl // out
#define printarray(arr, len)      \
    for (int i = 0; i < len; i++) \
    {                             \
        cout << arr[i] << " ";    \
        if (i + 1 == len)         \
            cout << endl;         \
    } // array print
using namespace std;

void handleExpressions(stack<char> &expressions, char c)
{
    if (expressions.empty())
    {
        expressions.push(c);
    }
    else
    {
        if (c == '+' || c == '-')
        {
            while (expressions.empty() != 1)
            {
                cout << expressions.top();
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
                while (expressions.top() != '+' || expressions.top() != '-')
                {
                    cout << expressions.top();
                    expressions.pop();
                }
                expressions.push(c);
            }
        }
    }
}

int32_t main()
{
    faster;
    cout << "Enter Your expression" << nl;
    string s;
    cin >> s;

    stack<char> expressions;
    cout << "tashin " << s.length() << nl; // 1 = true
                                           // 9+2-5*6/3+2*3/4
    for (int i = 0; i < s.length(); i++)
    {
        // cout <<"tashin "<<nl; // 1 = true
        if (s[i] >= '0' && s[i] <= '9')
            cout << s[i];
        else
        {
            handleExpressions(expressions, s[i]);
        }
    }
    while (expressions.empty() != 1)
    {
        cout << expressions.top();
        expressions.pop();
    }

    CRACKED;
}
