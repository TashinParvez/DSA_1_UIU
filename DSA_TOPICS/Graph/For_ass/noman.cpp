#include <bits/stdc++.h>
using namespace std;

typedef struct Coordinate
{
    int row = -1;
    int column = -1;
} coordinate;

#define mazeSize 5

/*
int maze[mazeSize][mazeSize] = {0, 1, 2, 0, 0,
                                0, 0, 0, 1, 0,
                                0, 3, 1, 0, 0,
                                0, 1, 0, 1, 0,
                                0, 0, 0, 0, 0
                               };
*/

int maze[mazeSize][mazeSize] = {0, 1, 0, 0, 2,
                                0, 0, 0, 1, 0,
                                0, 3, 1, 0, 0,
                                0, 1, 0, 1, 0,
                                0, 0, 0, 0, 0};

coordinate path[25];
enum Color
{
    white,
    black
};
Color visited[mazeSize][mazeSize] = {white}; // array


int pathIndex = 0;
coordinate shortestPath[25];
int shortestPathIndex = 0;

bool treasureFound = false;
bool treasureNotFound = true;

void printThePath()
{
    for (int i = 0; i < pathIndex; i++)
    {
        if (i == pathIndex - 1)
            cout << "(" << path[i].row << ", " << path[i].column << ")" << endl;
        else
            cout << "(" << path[i].row << ", " << path[i].column << ") -> ";

        if (treasureNotFound)
        {
            shortestPath[i].row = path[i].row;
            shortestPath[i].column = path[i].column;
        }
        else
        {
            if (shortestPathIndex > pathIndex)
            {
                shortestPath[i].row = path[i].row;
                shortestPath[i].column = path[i].column;
            }
        }
    }

    if (treasureNotFound)
        shortestPathIndex = pathIndex;
    else if (shortestPathIndex > pathIndex)
        shortestPathIndex = pathIndex;

    treasureNotFound = false;

    return;
}

void find_paths_with_treasures(int maze[mazeSize][mazeSize], int row, int col)
{
    if (row < 0 || col < 0 || row > mazeSize - 1 || col > mazeSize - 1)
        return;

    if (maze[row][col] == 3)
        treasureFound = true; // 3

    visited[row][col] = black;

    path[pathIndex].row = row;
    path[pathIndex].column = col;
    pathIndex++;

    if (maze[row][col] == 2 && treasureFound)
    {
        printThePath();

        visited[row][col] = white;

        path[pathIndex].row = -1;
        path[pathIndex].column = -1;
        pathIndex--;

        return;
    }

    if (maze[row - 1][col] != 1 && visited[row - 1][col] == white)
        find_paths_with_treasures(maze, row - 1, col);
    if (maze[row + 1][col] != 1 && visited[row + 1][col] == white)
        find_paths_with_treasures(maze, row + 1, col);
    if (maze[row][col - 1] != 1 && visited[row][col - 1] == white)
        find_paths_with_treasures(maze, row, col - 1);
    if (maze[row][col + 1] != 1 && visited[row][col + 1] == white)
        find_paths_with_treasures(maze, row, col + 1);


    visited[row][col] = white;
    
    if (maze[row][col] == 3)
        treasureFound = false;

    // path[pathIndex].row = -1;
    // path[pathIndex].column = -1;
    pathIndex--;

    return;
}

int main()
{
    // find_paths_with_treasures(maze, 0, 0);
    find_paths_with_treasures(maze, 1, 0);

    // for shortest path

    if (treasureNotFound)
        cout << "No path with treasure found!" << endl;
    else
    {
        for (int i = 0; i < shortestPathIndex; i++)
        {
            if (i == shortestPathIndex - 1)
                cout << "(" << shortestPath[i].row << ", " << shortestPath[i].column << ")" << endl;
            else
                cout << "(" << shortestPath[i].row << ", " << shortestPath[i].column << ") -> ";
        }
    }

    return 0;
}