#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
int horizontal[] = {-1, 1, 0, 0};
int vertical[] = {0, 0, -1, 1};
bool isSafe(int x, int y, int n, int m, char field[MAX][MAX], bool visited[MAX][MAX])
{
    if (x >= 0 && x < n && y >= 0 && y < m && field[x][y] == 'T' && !visited[x][y])
    {
        return true;
    }
    else
    {
        return false;
    }
}
int calcSize(int x, int y, int n, int m, char field[MAX][MAX], bool visited[MAX][MAX])
{
    visited[x][y] = true; 
    int size = 1;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + horizontal[i];
        int newY = y + vertical[i];
        if (isSafe(newX, newY, n, m, field, visited))
        {
            size += calcSize(newX, newY, n, m, field, visited); 
        }
    }
    return size;
}
int findLargest(int n, int m, char field[MAX][MAX])
{
    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited)); 
    int largestForest = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (field[i][j] == 'T' && !visited[i][j])
            {
                int currentForestSize = calcSize(i, j, n, m, field, visited);
                largestForest = max(largestForest, currentForestSize);
            }
        }
    }

    return largestForest;
}
int main()
{
    char field[MAX][MAX] = {
        {'T', 'T', 'T', 'W', 'W'},
        {'T', 'W', 'W', 'T', 'T'},
        {'T', 'W', 'W', 'T', 'T'},
        {'T', 'W', 'T', 'T', 'T'},
        {'W', 'W', 'T', 'T', 'T'}};
    int n = 5;
    int m = 5;
    int largestForest = findLargest(n, m, field);
    cout << largestForest << endl;
    return 0;
}