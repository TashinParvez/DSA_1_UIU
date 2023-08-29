#include <stdio.h>

#define ROWS 5
#define COLS 5

int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0},
    {0, 0, 0, 1, 2},
    {0, 3, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}};

int visited[ROWS][COLS] = {0};

int shortest_path[ROWS * COLS];    // 25
int shortest_length = ROWS * COLS; // 25

void print_path(int path[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("(%d, %d)", path[i] / COLS, path[i] % COLS);
        if (i < length - 1)
        {
            printf(" -> ");
        }
    }
    printf("\n");
}

void dfs(int row, int col, int path[], int length)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || visited[row][col] || maze[row][col] == 1)
    {
        return;
    }

    path[length] = row * COLS + col;
    visited[row][col] = 1;

    if (maze[row][col] == 2) // Exit found
    {
        int treasure_found = 0;
        for (int i = 0; i <= length; i++)
        {
            if (maze[path[i] / COLS][path[i] % COLS] == 3)
            {
                treasure_found = 1;
                break;
            }
        }
        if (treasure_found)
        {
            printf("Path with treasure: ");
            print_path(path, length + 1);

            if (length + 1 < shortest_length)
            {
                shortest_length = length + 1;
                for (int i = 0; i <= length; i++)
                {
                    shortest_path[i] = path[i];
                }
            }
        }
    }

    dfs(row + 1, col, path, length + 1);
    dfs(row - 1, col, path, length + 1);
    dfs(row, col + 1, path, length + 1);
    dfs(row, col - 1, path, length + 1);

    visited[row][col] = 0; // Backtrack
}

void find_paths_with_treasures(int start_row, int start_col)
{
    int path[ROWS * COLS]; // 25

    dfs(start_row, start_col, path, 0);

    if (shortest_length != ROWS * COLS)
    {
        printf("\nShortest path with treasure: ");
        print_path(shortest_path, shortest_length);
    }
    else
    {
        printf("\nNo path with treasure found.\n");
    }
}

int main()
{
    // int start_row = 1;
    // int start_col = 0;
    find_paths_with_treasures(1, 0);
    return 0;
}
