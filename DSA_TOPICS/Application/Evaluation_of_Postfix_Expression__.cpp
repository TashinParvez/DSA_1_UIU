//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl
using namespace std;

int32_t main()
{
    cout << "Enter Your postfix expression : ";
    string s;
    cin >> s;

    // in:   8*(5^4+2)-6^2/(9*3)
    // post: 854^2+*62^93*/-

    // in:   9+2-5*6/3+2^3/4
    // post: 92+56*3/-23^4/+

    // in:   1+3^2+(5*6-4)*7
    // post: 132^+56*4-7*+

    stack<int> operand;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            operand.push(s[i] - '0');
        }
        else
        {
            int b = operand.top();
            operand.pop();
            int a = operand.top();
            operand.pop();

            if (s[i] == '+')
            {
                operand.push(a + b);
            }
            else if (s[i] == '-')
            {
                operand.push(a - b);
            }
            else if (s[i] == '*')
            {
                operand.push(a * b);
            }
            else if (s[i] == '/')
            {
                operand.push(a / b);
            }
            else if (s[i] == '^')
            {
                operand.push(pow(a, b));
            }
        }
    }
    cout << "Ans " << operand.top() << nl;

    CRACKED;
}
