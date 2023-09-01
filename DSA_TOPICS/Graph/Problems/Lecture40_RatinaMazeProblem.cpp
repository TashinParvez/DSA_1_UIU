//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

bool isSafe(int row, int col, int n, vector<vector<int>> &visited, vector<vector<int>> &m)
{
    if (row >= 0 && col < n && col >= 0 && col < n && visited[row][col] == 0 && m[row][col == 0])
    {
        return true;
    }
    else
        return false;
}

void solve(vector<vector<int>> &m, int n, vector<string> &ans, int row, int col, vector<vector<int>> &visited, string path)
{
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[row][col] = 1;

    if (isSafe(row - 1, col, n, visited, m))
    {
        path.push_back('U');
        solve(m, n, ans, row - 1, col, visited, path);
        path.pop_back();
    }

    if (isSafe(row + 1, col, n, visited, m))
    {
        path.push_back('D');
        solve(m, n, ans, row + 1, col, visited, path);
        path.pop_back();
    }

    if (isSafe(row, col + 1, n, visited, m))
    {
        path.push_back('R');
        solve(m, n, ans, row, col + 1, visited, path);
        path.pop_back();
    }
    if (isSafe(row, col - 1, n, visited, m))
    {
        path.push_back('L');
        solve(m, n, ans, row, col - 1, visited, path);
        path.pop_back();
    }

    visited[row][col] = 0;
}

vector<string> findpath(vector<vector<int>> &m, int row, int col, int n)
{
    vector<string> ans;
    if (m[row][col] == 0)
    {
        return ans;
    }
    vector<vector<int>> visited;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    string path = "";
    solve(m, n, ans, row, col, visited, path);
}

int32_t main()
{

    CRACKED;
}
