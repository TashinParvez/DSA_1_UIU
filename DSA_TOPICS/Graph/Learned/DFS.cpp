#include <iostream>
#include <queue>
#define null NULL
#define nl endl
using namespace std;

int visited[4] = {0};
int nodes = 4;
int adjMatrix[4][4] = {1, 0, 0, 1,
                       0, 1, 1, 0,
                       0, 1, 1, 0,
                       1, 0, 0, 1};

void dfs(int start) // comming 2
{
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < nodes; i++)
    {
        if (adjMatrix[start][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int start = 2;

    printf("\nDFS Traversal: ");
    dfs(start);
    for (start = 0; start < nodes; start++)
        dfs(start);

    return 0;
}