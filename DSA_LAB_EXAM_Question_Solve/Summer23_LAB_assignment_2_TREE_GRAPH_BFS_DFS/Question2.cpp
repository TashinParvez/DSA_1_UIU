#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

// exmp 1
// int maze[5][5] = {0, 1, 2, 0, 0,
//                   0, 0, 0, 1, 0,
//                   0, 3, 1, 0, 0,
//                   0, 1, 0, 1, 0,
//                   0, 0, 0, 0, 0};

/*
5
0 1 2 0 0 0 0 0 1 0 0 3 1 0 0 0 1 0 1 0 0 0 0 0 0
0 0

*/

// exmp 2
// int maze[5][5] = {0, 1, 0, 0, 2,
//                   0, 0, 0, 1, 0,
//                   0, 3, 1, 0, 0,
//                   0, 1, 0, 1, 0,
//                   0, 0, 0, 0, 0};

/*

5
0 1 0 0 2 0 0 0 1 0 0 3 1 0 0 0 1 0 1 0 0 0 0 0 0
1 0

*/

int N;
int pathLength = -1;

class Path
{
public:
    int x, y;
};

Path path[25];
int shortestPath = 0;

string s;
void findPath()
{
    if (shortestPath == 0 || pathLength < shortestPath)
    {
        s = "";
        shortestPath = pathLength;
    }

    // cout << "____________ RUNNING _____________ " << nl;

    for (int i = 0; i < pathLength; i++)
    {
        string sp = "(" + to_string(path[pathLength].x) + ", " + to_string(path[pathLength].y) + "), ";
        s += (sp);
        cout << "(" << path[i].x << ", " << path[i].y << ") -> ";
        if (i == pathLength - 1)
        {
            // cout<<" last case handle is ok "<<nl;
            cout << "(" << path[pathLength].x << ", " << path[pathLength].y << ") ";
        }
    }
    cout << nl;
}

int visited[100][100] = {0};
bool inHandTreasure = false;

void dfs(int maze[100][100], int row, int col)
{
    // base case
    if (row < 0 || row > N - 1 || col < 0 || col > N - 1)
        return;

    // output
    // cout << "(" << row << " " << col << ")" << endl;

    pathLength++;
    visited[row][col] = 1;
    path[pathLength].x = row;
    path[pathLength].y = col;

    // s[row][col] += "( " + to_string(row) + " " + to_string(col) + " ), ";

    if (maze[row][col] == 3)
        inHandTreasure = true; // found

    if (maze[row][col] == 2)
    {
        if (inHandTreasure == true)
        {
            // cout << "____________________________ yess _____________ " << nl;
            cout << "Path with treasure: ";
            findPath();
        }
    }

    // right
    if (maze[row][col + 1] != 1 && visited[row][col + 1] == 0)
        dfs(maze, row, col + 1);

    // left
    if (maze[row][col - 1] != 1 && visited[row][col - 1] == 0)
        dfs(maze, row, col - 1);

    // up
    if (maze[row + 1][col] != 1 && visited[row + 1][col] == 0)
        dfs(maze, row + 1, col);

    // down
    if (maze[row - 1][col] != 1 && visited[row - 1][col] == 0)
        dfs(maze, row - 1, col);

    if (maze[row][col] == 3)
        inHandTreasure = false;

    pathLength--;
    visited[row][col] = 0;
}

void find_paths_with_treasures(int maze[100][100], int start_row, int start_col)
{
    // string shortestPath;
    dfs(maze, start_row, start_col); // searching
}

int main()
{
    cout << "Give maze size: ";
    cin >> N;
    int maze[100][100];

    cout << "Give maze elements: ";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> maze[i][j];

    cout << "Give starting position [ row and coloum ]: ";
    int start_row, start_col;
    cin >> start_row >> start_col;
    cout << nl;
    find_paths_with_treasures(maze, start_row, start_col);

    if (shortestPath == 0)
    {
        cout << "No path with treasure found!" << nl;
    }
    else
    {
        cout << nl;
        cout << "Shortest path: ";
        cout << s << nl;
        cout << nl;
    }

    CRACKED;
}
