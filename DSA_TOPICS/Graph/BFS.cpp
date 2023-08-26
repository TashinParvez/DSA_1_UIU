//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;
void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edge)
{
    for (auto i : edge)
    {
        adjList[i.first].push_back(i.second);
        adjList[i.second].push_back(i.first);
    }
}
void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int frontNode = q.front();
        // store ans
        ans.push_back(frontNode);
        q.pop();
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edge)
{
    unordered_map<int, list<int>> adjList; // make adj list
    vector<int> ans;                       // store bfs
    unordered_map<int, bool> visited;      // coloring
    prepareAdjList(adjList, edge);
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }
}

int32_t main()
{
    CRACKED;
}
