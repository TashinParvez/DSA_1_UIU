//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

int parent[100];

// find function
int find(int a)
{
    if (parent[a] == a)
        return a;
    else
        return find(parent[a]);
}

// Union Function

void unionSet(int a, int b)
{
    int u = parent[a];
    int v = parent[b];
    if (u == v)
        cout << "they are in sem set" << nl;
    else
        parent[b] = a;
}



int32_t main()
{ 
}
