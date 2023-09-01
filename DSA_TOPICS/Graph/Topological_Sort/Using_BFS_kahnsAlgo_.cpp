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
    }

    /*
         Rules is :
           push only if  its indegree is zero
           after every push decrease its child indegree and check its degree becomes 0 or not
    */

    void topSort()
    {
        queue<int> q;
        vector<int> indegree(V); // we are taking nodes values from 0 to n.
        vector<int> result;
        int visitedCount = 0; // is to check there is any circle or not

        // Calculate indegree
        for (auto p : adjList)
        {
            // int u = p.first; // comming from u
            for (auto v : p.second)
            {
                indegree[v]++;
            }
        }

        // insert vertices with 0 indegree in queue
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        // BFS
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            visitedCount++;
            result.push_back(x);

            // Reduce indegree of x's child
            for (auto dest : adjList[x])
            {
                indegree[dest]--;
                if (indegree[dest] == 0) // checking any of child have 0 indegree or not
                    q.push(dest);
            }
        }

        if (visitedCount != V)
        {
            cout << "There exists a cycle in the graph";
            return;
        }
        else
        {

            for (int x : result)
            {
                cout << x << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topSort();
    return 0;
}