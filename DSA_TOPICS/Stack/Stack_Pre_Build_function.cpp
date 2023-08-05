//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>

#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

int32_t main()
{
    stack<int> s;

    s.push(10);
    s.push(100);
    s.pop();
    s.push(1000);

    cout << s.empty() << nl;
    cout << s.top() << nl;
    cout << s.size() << nl;

    CRACKED;
}
