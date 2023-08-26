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

// exmp 2
// int maze[5][5] = {0, 1, 0, 0, 2,
//                   0, 0, 0, 1, 0,
//                   0, 3, 1, 0, 0,
//                   0, 1, 0, 1, 0,
//                   0, 0, 0, 0, 0};

int visited[5][5] = {0};

string s[5][5];

void dfs(int row, int col, int search) // 1 0  0
{
    // base case
    if (row < 0 || row > 4 || col < 0 || col > 4)
        return;

    // output
    // cout << "(" << row << " " << col << ")" << endl;

    s[row][col] += "( " + to_string(row) + " " + to_string(col) + " ), ";

    if (maze[row][col] == 3)
    {
        search = 3;

        // s[row][col] = "y" + s[row][col]; // type 2

        // cout << "TASDJSHDAHS        " << s[row][col] << nl;
        // cout << "TASDJSHDAHS" << nl;
        // cout << "TASDJSHDAHS        " << s[row][col] << nl;
    }

    if (maze[row][col] == 2)
    {
        // cout << "TASDJSHDAHS        " << s[row][col] << nl;
        // string str = s[row][col];
        // if (str[0] == 'y')
        // {
        //     cout << str << nl;
        //     cout << "TASDJSHDAHS" << nl;
        // }

        if (search == 3)
        {
            cout << "Path with treasure: ";
            cout << s[row][col] << nl;
        }
    }

    visited[row][col] = 1;

    // right
    if (maze[row][col + 1] != 1 && visited[row][col + 1] == 0)
    {
        s[row][col + 1] = s[row][col];
        dfs(row, col + 1, search);
    }
    // left
    if (maze[row][col - 1] != 1 && visited[row][col - 1] == 0)
    {
        s[row][col - 1] = s[row][col];
        dfs(row, col - 1, search);
    }
    // up
    if (maze[row + 1][col] != 1 && visited[row + 1][col] == 0)
    {
        s[row + 1][col] = s[row][col];
        dfs(row + 1, col, search);
    }

    // down
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
    CRACKED;
}
