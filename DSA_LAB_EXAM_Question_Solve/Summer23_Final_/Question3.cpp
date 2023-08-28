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

int visited[5][5] = {0};

string s[5][5];

void dfs(int row, int col, int search, int length) // 1 0  0
{
    length++;
    // base case
    if (row < 0 || row > 4 || col < 0 || col > 4)
        return;

    // output
    // cout << "(" << row << " " << col << ")" << endl;

    s[row][col] += "( " + to_string(row) + " " + to_string(col) + " ), ";

    if (maze[row][col] == 3)
    {
        if (length <= 3)
        {
            s[row][col] = 'y' + s[row][col];
        }
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
            // cout << "Path with treasure: ";
            // cout << s[row][col] << nl;

            string ss = s[row][col];
            if (ss[0] == 'y')
            {
                cout << " Eureka and Can reach End " << nl;
            }
            else
            {
                cout << " Treasure hunt boring and Can reach End " << nl;
            }
        }
    }

    visited[row][col] = 1;

    // right
    if (maze[row][col + 1] != 1 && visited[row][col + 1] == 0)
    {
        s[row][col + 1] = s[row][col];
        dfs(row, col + 1, search, length);
    }
    // left
    if (maze[row][col - 1] != 1 && visited[row][col - 1] == 0)
    {
        s[row][col - 1] = s[row][col];
        dfs(row, col - 1, search, length);
    }
    // up
    if (maze[row + 1][col] != 1 && visited[row + 1][col] == 0)
    {
        s[row + 1][col] = s[row][col];
        dfs(row + 1, col, search, length);
    }

    // down
    if (maze[row - 1][col] != 1 && visited[row - 1][col] == 0)
    {
        s[row - 1][col] = s[row][col];
        dfs(row - 1, col, search, length);
    }

    visited[row][col] = 0;
}


int main()
{

    // row col search length
    dfs(1, 0, 0, 0);
    CRACKED;
}
