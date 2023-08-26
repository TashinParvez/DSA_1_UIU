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
void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component)
{
    component.push_back(node);
    visited[node] = 1;

    for (auto i : adjList[node])
    {
        if (!visited[i])
            dfs(i, visited, adjList, component);
    }
}

vector<int> DFS(int vertex, int e, vector<pair<int, int>> edge)
{
    unordered_map<int, list<int>> adjList; // make adj list
    prepareAdjList(adjList, edge);

    vector<vector<int>> ans; // store dfs

    unordered_map<int, bool> visited; // coloring
    
    // for all nodes
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
}

int32_t main()
{
    CRACKED;
}
