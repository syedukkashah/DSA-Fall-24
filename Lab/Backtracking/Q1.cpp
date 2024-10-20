#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
#define MAX_PATHS 1000
#define MAX_LEN 100
bool isSafe(int x, int y, int mat[MAX][MAX], bool visited[MAX][MAX], int n)
{
    return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1 && visited[x][y] == false);
}

void findPaths(int x, int y, int mat[MAX][MAX], int n, char paths[MAX_PATHS][MAX_LEN],
     char path[MAX_LEN], int pathIdx, bool visited[MAX][MAX], int &count)
{

    if (x == n - 1 && y == n - 1)
    {
        path[pathIdx] = '\0'; 
        strcpy(paths[count++], path);
        return;
    }

    visited[x][y] = true; 

    if (isSafe(x + 1, y, mat, visited, n))
    {
        path[pathIdx] = 'D';
        findPaths(x + 1, y, mat, n, paths, path, pathIdx + 1, visited, count);
    }

    if (isSafe(x, y + 1, mat, visited, n))
    {
        path[pathIdx] = 'R';
        findPaths(x, y + 1, mat, n, paths, path, pathIdx + 1, visited, count);
    }
    if (isSafe(x - 1, y, mat, visited, n))
    {
        path[pathIdx] = 'U';
        findPaths(x - 1, y, mat, n, paths, path, pathIdx + 1, visited, count);
    }

    if (isSafe(x, y - 1, mat, visited, n))
    {
        path[pathIdx] = 'L';
        findPaths(x, y - 1, mat, n, paths, path, pathIdx + 1, visited, count);
    }

    visited[x][y] = false; 
}
void ratInMaze(int mat[MAX][MAX], int n)
{
    bool visited[MAX][MAX] = {false};
    char paths[MAX_PATHS][MAX_LEN], path[MAX_LEN];
    int pathIdx = 0, count = 0;
    if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
    {
        cout << "No paths found" << endl;
        return;
    }
    findPaths(0, 0, mat, n, paths, path, pathIdx, visited, count);
    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            cout << paths[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No paths found" << endl;
    }
}

int main()
{
    int mat[MAX][MAX] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    int n = 4;
    ratInMaze(mat, n);
    return 0;
}