//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

class Graph
{
    int V;                                   // vertices
    unordered_map<int, vector<int>> adjList; // adj.List

public:
    Graph(int vertices) // constructor
    {
        this->V = vertices;
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void findShortestPath(int source, int dest)
    {
        int parent[V];
        parent[source] = -1;
        bool visited[V] = {0};
        queue<int> q;
        q.push(source);
        visited[source] = 1;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto i : adjList[x])
            {
                if (!visited[i])
                {
                    visited[i] = 1;
                    parent[i] = x;
                    q.push(i);
                }
            }
        }
        // finding the shortest path
        int currentNode = dest;
        // we will go from dest to source
        int cnt = 0;
        stack<int> s;
        s.push(currentNode);
        while (currentNode != source)
        {
            currentNode = parent[currentNode];
            s.push(currentNode);
            cnt++;
        }
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << nl;
    }
};

int main()
{
    cout << "Enter number of vertices: ";
    int vertices, edges;
    cin >> vertices;
    cout << "Enter number of edges   : ";
    cin >> edges;

    Graph g(vertices);
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter edges from (u to v): ";
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "enter source and destination " << nl;
    int s, d;
    cin >> s >> d;
    g.findShortestPath(s, d);

    return 0;
}
// question 2
/*
6 8

0 1
0 5
1 2
2 3
2 6
3 4
4 6
5 6



*/

// question 1
/*

5 4

0 2
2 4
0 1
1 3

*/