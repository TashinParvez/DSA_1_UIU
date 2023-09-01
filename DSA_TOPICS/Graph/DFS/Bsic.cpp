//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

vector<int> graph[100];
int visited[100];
 
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
}

int32_t main()
{
    int nodes, edges;
    cout << "Enter nodes and edge number: ";
    cin >> nodes >> edges;

    cout << "Enter edges from u to v: ";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 0; i <= nodes; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
    }

    CRACKED;
}
