#include<iostream>
#include<queue>
using namespace std;
int maze[4][5]={ 0,1,1,0,2,
                 0,1,1,0,1,
                 0,1,1,0,1,
                 0,0,0,0,1 };

int visited[4][5]={ 0,0,0,0,0,
                    0,0,0,0,0,
                    0,0,0,0,0,
                    0,0,0,0,0 };

void dfs(int row,int col)
{
    if(row<0||row>3||col<0||col>4) return;

    cout<<row<<" "<<col<<endl;
    if(maze[row][col]==2) cout<<"We are in the exit"<<endl;

    visited[row][col]=1;
    if(maze[row][col+1]!=1&&visited[row][col+1]==0)
    {
        dfs(row,col+1);
    }
    if(maze[row][col-1]!=1&&visited[row][col-1]==0)
    {
        dfs(row,col-1);
    }
    if(maze[row+1][col]!=1&&visited[row+1][col]==0)
    {
        dfs(row+1,col);
    }
    if(maze[row-1][col]!=1&&visited[row-1][col]==0)
    {
        dfs(row-1,col);
    }
    visited[row][col]=0;
}

int main()
{
    dfs(3,0);
    return 0;
}
