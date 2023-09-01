#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;
int maze[5][5] = {0, 1, 0, 0, 2,
                  0, 0, 0, 1, 0,
                  0, 3, 1, 0, 0,
                  0, 1, 0, 1, 0,
                  0, 0, 0, 0, 0};
// int visited[5][5] = {0};
int solution[5][5] = {0};
int n = 5;
bool isSafe(int r, int c)
{
    if (r < n && c << n && maze[r][c] == 0)
    {
        return true;
    }
    else
        return false;
}
bool ratinMaze(int row, int col)
{
    if (maze[row][col] == 2)
    {
        solution[row][col] = 1;
        return true;
    }

    if (isSafe(row, col))
    {
        solution[row][col] = 1;
        if (ratinMaze(row + 1, col))
        {
            return true;
        }
        if (ratinMaze(row, col + 1))
        {
            return true;
        }
        solution[row][col] = 0;
        return false;
    }
    return false;
}

int32_t main()
{

    if (ratinMaze(1, 0))
    {
        cout << "YES" << nl;
    }
    else
        cout << "No" << nl;
    CRACKED;
}
 