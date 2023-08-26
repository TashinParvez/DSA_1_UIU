#include <iostream>
#include <stack>

using namespace std;

// int maze[5][5] = {
//     {0, 1, 2, 1, 0},
//     {0, 0, 0, 1, 0},
//     {0, 3, 1, 0, 0},
//     {0, 1, 0, 1, 0},
//     {0, 0, 0, 0, 0}};

int maze[5][5] = {0, 1, 0, 0, 2,
                  0, 0, 0, 1, 0,
                  0, 3, 1, 0, 0,
                  0, 1, 0, 1, 0,
                  0, 0, 0, 0, 0};

int visited[5][5] = {0};

bool dfs(int row, int col, int sKey, stack<pair<int, int>> &pathStack)
{
    if (row < 0 || row > 4 || col < 0 || col > 4 || visited[row][col] == 1)
    {
        return false;
    }

    pathStack.push({row, col});
    visited[row][col] = 1;

    // last case [ find the out gate ]
    if (maze[row][col] == 2 && sKey == 2)
    {
        return true;
    }

    // get 1st treasure
    if (maze[row][col] == 3)
    {
        sKey = 2;
    }

    if (maze[row][col + 1] != 1 && dfs(row, col + 1, sKey, pathStack))
    {
        return true;
    }
    if (maze[row + 1][col] != 1 && dfs(row + 1, col, sKey, pathStack))
    {
        return true;
    }
    if (maze[row][col - 1] != 1 && dfs(row, col - 1, sKey, pathStack))
    {
        return true;
    }
    if (maze[row - 1][col] != 1 && dfs(row - 1, col, sKey, pathStack))
    {
        return true;
    }

    visited[row][col] = 0;
    pathStack.pop();
    return false;
}

int main()
{
    stack<pair<int, int>> pathStack;
    int row, col;
    cout << "Enter your starting point : ";
    cin >> row >> col;

    if (dfs(row, col, 0, pathStack))
    {
        cout << "Path with treasure and exit:";
        while (!pathStack.empty())
        {
            cout << " (" << pathStack.top().first << "," << pathStack.top().second << ")<--";
            pathStack.pop();
        }
        cout << "Starting point(i,j)";
        cout << endl;
    }
    else
    {
        cout << "No path with treasure found." << endl;
    }

    return 0;
}
