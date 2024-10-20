#include <iostream>
using namespace std;
bool isSafe(bool board[], int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row * n + i])
            return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i * n + j])
            return false;
    for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
        if (board[i * n + j])
            return false;

    return true;
}
bool solveNQueens(bool board[], int col, int n) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i * n + col] = true;
            if (solveNQueens(board, col + 1, n))
                return true;
            board[i * n + col] = false;
        }
    }
    return false;
}
void printBoard(bool board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i * n + j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    cout << "Enter the size of the board (N): ";
    cin >> n;
    bool board[n*n] = {false};
    if (solveNQueens(board, 0, n)) {
        cout << "One possible solution is:" << endl;
        printBoard(board, n);
    } else {
        cout << "No solution exists" << endl;
    }
    return 0;
}
