#include <stdio.h>
#define N 8   // change this to solve for any N (e.g., 4, 5, 6, 8)
// Function to print the board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
int isSafe(int board[N][N], int row, int col) {

    // Check the same row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1)
            return 0;
    }
    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    // Check lower-left diagonal
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == 1)
            return 0;
    }
    return 1; // safe
}
// Backtracking function
int solveNQ(int board[N][N], int col) {

    // Base case: All queens placed
    if (col >= N)
        return 1;

    // Try placing queen in each row
    for (int row = 0; row < N; row++) {

        if (isSafe(board, row, col)) {
            board[row][col] = 1; // place queen

            if (solveNQ(board, col + 1))
                return 1;        // solution found

            board[row][col] = 0; // backtrack
        }
    }

    return 0; // no place to put queen
}
int main() {
    int board[N][N] = {0};

    if (solveNQ(board, 0) == 0) {
        printf("No solution exists\n");
    } else {
        printf("Solution:\n");
        printBoard(board);
    }

    return 0;
}
