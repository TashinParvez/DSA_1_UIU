#include <iostream>
#include <string>
using namespace std;

int maze[5][5] = {
    {0, 1, 0, 0, 2},
    {0, 0, 0, 1, 0},
    {0, 3, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}};

int visited[5][5] = {0};
string s[5][5];

void dfs(int row, int col, int search)
{
    if (row < 0 || row > 4 || col < 0 || col > 4)
        return;

    s[row][col] += "( " + to_string(row) + " " + to_string(col) + " ), ";

    if (maze[row][col] == 3)
        search = 3;

    if (maze[row][col] == 2 && search == 3)
    {
        cout << "Path with treasure: ";
        cout << s[row][col] << endl;
    }

    visited[row][col] = 1;

    if (maze[row][col + 1] != 1 && visited[row][col + 1] == 0)
    {
        s[row][col + 1] = s[row][col];
        dfs(row, col + 1, search);
    }
    if (maze[row][col - 1] != 1 && visited[row][col - 1] == 0)
    {
        s[row][col - 1] = s[row][col];
        dfs(row, col - 1, search);
    }
    if (maze[row + 1][col] != 1 && visited[row + 1][col] == 0)
    {
        s[row + 1][col] = s[row][col];
        dfs(row + 1, col, search);
    }
    if (maze[row - 1][col] != 1 && visited[row - 1][col] == 0)
    {
        s[row - 1][col] = s[row][col];
        dfs(row - 1, col, search);
    }

    visited[row][col] = 0;
}

int main()
{
    dfs(1, 0, 0);
    return 0;
}