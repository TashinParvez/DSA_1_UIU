#include <iostream>
#define nl endl;
using namespace std;
int arr[4][5] = {
    0, 1, 1, 0, 2,
    0, 1, 1, 0, 1,
    0, 1, 1, 0, 1,
    0, 0, 0, 0, 1};

int visited[4][5] = {0};
string str = "(3 , 0), ";
void dfs(int row, int col)
{

    if (row < 0 || row > 3 || col < 0 || col > 4)
    {
        str = "(3 , 0), ";
        return;
    }

    if (visited[row][col] == 0)
    {
        visited[row][col] = 1;
        cout << "Row " << row << " column " << col << nl;
        str += "( " + to_string(row) + " , " + to_string(col) + " ), ";
    }
    else
    {
        str = "(3 , 0), ";
        return;
    }
    if (arr[row][col] == 2)
        cout << str << nl;

    if (arr[row + 1][col] != 1 && visited[row + 1][col] == 0)
    {
        dfs(row + 1, col);
    }

    if (arr[row - 1][col] != 1 && visited[row - 1][col] == 0)
    {
        dfs(row - 1, col);
    }

    if (arr[row][col + 1] != 1 && visited[row][col + 1] == 0)
    {
        dfs(row, col + 1);
    }

    if (arr[row][col - 1] != 1 && visited[row][col - 1] == 0)
    {
        dfs(row, col - 1);
    }

    visited[row][col] == 0;
    // str = "(3 , 0), ";
}

int main()
{
    dfs(3, 0);
    return 0;
}