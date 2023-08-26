#include <iostream>
#include <queue>
#define null NULL
#define nl endl
using namespace std;
// exmp 1
// int maze[5][5] = {0, 1, 2, 0, 0,
//                   0, 0, 0, 1, 0,
//                   0, 3, 1, 0, 0,
//                   0, 1, 0, 1, 0,
//                   0, 0, 0, 0, 0};

// exmp 2
int maze[5][5] = {0, 1, 0, 0, 2,
                  0, 0, 0, 1, 0,
                  0, 3, 1, 0, 0,
                  0, 1, 0, 1, 0,
                  0, 0, 0, 0, 0};

int visited[5][5] = {0};
string s[5][5];

void dfs(int row, int col) // (3,0) call
{
    // base case
    if (row < 0 || row > 4 || col < 0 || col > 4)
        return;

    if (maze[row][col] == 3)
    {

        // cout << nl;
        // for (int i = 0; i < 5; i++)
        // {
        //     for (int j = 0; j < 5; j++)
        //     {
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << nl;
        // }

        s[row][col] = "y" + s[row][col];
    }

    // output

    cout << "(" << row << " " << col << ")" << endl;

    // s[row][col] += "(" + to_string(row) + " , " + to_string(col) + "), ";

    if (maze[row][col] == 2)
    {
        // string str = s[row][col];
        // if (str[0] == 'y')
        // {
        //     // str.erase(0, 1);
        //     cout << "String  " << str << nl;
        // }

        // cout << s[row][col] << endl; // print string
        cout << "We are in the exit" << endl;
    }

    // clouring
    visited[row][col] = 1;

    if (maze[row][col + 1] != 1 && visited[row][col + 1] == 0)
    {
        s[row][col + 1] = s[row][col];
        dfs(row, col + 1);
    }

    if (maze[row][col - 1] != 1 && visited[row][col - 1] == 0)
    {
        s[row][col - 1] = s[row][col];
        dfs(row, col - 1);
    }

    if (maze[row + 1][col] != 1 && visited[row + 1][col] == 0)
    {
        s[row + 1][col] = s[row][col];
        dfs(row + 1, col);
    }

    if (maze[row - 1][col] != 1 && visited[row - 1][col] == 0)
    {
        s[row - 1][col] = s[row][col];
        dfs(row - 1, col);
    }

    visited[row][col] = 0;
    // s[row][col] = "";
}

int32_t main()
{
    // for (int i = 0; i < 25; i++)
    //     cout << arr[i] << nl;

    // exmp 1
    // dfs(0, 0);
    // exmp 2

    dfs(1, 0);
    return 0;
}
