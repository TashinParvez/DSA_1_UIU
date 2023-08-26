#include <iostream>
#include <queue>
#define null NULL
#define nl endl
using namespace std;
//                 0  1  2  3  4
int graph[5][5] = {0, 1, 1, 1, 0,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 1, 0,
                   1, 0, 1, 0, 1,
                   0, 1, 0, 1, 0};
             //    0, 0, 0, 0, 0}; // not work

void bfs(int source)
{
    int color[5] = {0}; // not visited
    int d[5];           // distance
    int p[5] = {-1};    // parent

    /*
    color:
           0 = white  // not visited
           1 = Gray   // visited [in queue]
           2 = Black  // printed
    */

    color[source] = 1; // visited [in queue]
    d[source] = 0;

    queue<int> Q;
    Q.push(source);

    while (!Q.empty())
    {

        int s = Q.front();
        Q.pop();

        cout << s << " "; // ans <vector in babar>

        for (int i = 0; i < 5; i++) // traverse that particular row
        {
            if (graph[s][i] == 1 && color[i] == 0)
            // graph = 1   means connected
            // color = 0   means not in queue
            {
                Q.push(i);
                color[i] = 1;    // visited [in queue]
                d[i] = d[s] + 1; // perticular node distance [kinda level]
                p[i] = s;        // giving parent [  int s = Q.front() ]
            }
        }
        color[s] = 2; // parent color black
    }

    cout << endl;

    for (int i = 0; i < 5; i++) // printing all nodes distance from root
    {
        cout << "distance = " << i << " is = " << d[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < 5; i++) // printing all nodes parent
    {
        cout << "parent = " << i << " is = " << p[i] << endl;
    }

    cout << endl;
}
int main()
{
    cout << nl;
    bfs(4); // sending one node as a root
    return 0;
}
