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
int cnt = 0;

// src aux des
void TOH(int n, int a, int b, int c)
{
    if (n > 0)
    {
        TOH(n - 1, a, c, b);
        cout << a << " to " << c << nl;
        cnt++;
        TOH(n - 1, b, a, c);
    }
}

int32_t main()
{
    faster;

    TOH(3, 1, 2, 3);
    // disks--from--using--to
    cout << cnt << nl;

    CRACKED;
}
