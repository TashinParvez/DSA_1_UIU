//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

vector<int> graph[100];
int visited[100] = {0};
stack<int> result;

void dfs(int source)
{
    visited[source] = 1;
    for (int i = 0; i < graph[source].size(); i++)
    {
        if (visited[graph[source][i]] == 0)
        {
            dfs(visited[graph[source][i]]);
        }
    }
    // all nodes are vsiited
    result.push(source);
}

int32_t main()
{
    int nodes, edges;
    cout << "Enter nodes and edge number: ";
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter edges from u to v: ";
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= nodes; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }

    cout << nl << "Topological Order: ";
    while (!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
    }
    cout << nl;
    CRACKED;
}

/*

5 4

3 2
1 2
2 4
2 5


*/