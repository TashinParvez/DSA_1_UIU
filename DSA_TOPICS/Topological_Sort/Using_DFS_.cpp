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
int cnt = 1;

void dfs(int source)
{
    visited[source] = 1;

    for (int i = 0; i < graph[source].size(); i++)
    {
        if (visited[graph[source][i]] == 0)
        {
            dfs(graph[source][i]);
        }
    }

    // all nodes are vsiited

    cout << "PUSH " << cnt << "  " << source << nl; // debug
    // pushing when doing backtracking
    result.push(source);
    cnt++;
}
/*

---------------  Logic of TopSort  -----------------
if  from 1 no edge i can go o 4, 5 ,7 edges
then 1 should be come first then these edges in sorting order

*/
int32_t main()
{
    int nodes, edges;
    cout << "Enter nodes and edge number: ";
    cin >> nodes >> edges;

    // input edges
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter edges from u to v: ";
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= nodes; i++)
    {
        // calling DFS
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
  6 7

  1 2
  2 4
  1 3
  3 4
  4 6
  4 5
   5 6

*/

/*

5 4

3 2
1 2
2 4
2 5


*/