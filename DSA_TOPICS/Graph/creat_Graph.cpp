//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, int direction)
    {
        // dirrection == 1  -> directed
        // dirrection == 0  -> Undirected
        adj[u].push_back(v);
        if (direction)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << nl;
        }
    }
};

int32_t main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;
    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating undirected egde
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    CRACKED;
}
