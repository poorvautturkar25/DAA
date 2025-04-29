#include <stdio.h>

#define N 9 // Standard Sudoku grid size

// Function to check if placing num at grid[row][col] is valid
int isValid(int grid[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0; // Number already exists in row or column
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return 0; // Number already exists in subgrid
            }
        }
    }

    return 1; // Number can be placed
}

// Function to solve Sudoku using Backtracking
int solveSudoku(int grid[N][N]) {
    int row, col;
    int emptyFound = 0;

    // Find the first empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                emptyFound = 1;
                break;
            }
        }
        if (emptyFound) break;
    }

    // If no empty cell is found, puzzle is solved
    if (!emptyFound) return 1;

    // Try placing numbers 1-9
    for (int num = 1; num <= N; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively try solving the rest of the puzzle
            if (solveSudoku(grid)) return 1;

            // Backtrack if solution is not possible
            grid[row][col] = 0;
        }
    }

    return 0; // No valid solution found
}

// Function to print Sudoku grid
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[N][N];

    // Take input from user
    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Solve Sudoku
    if (solveSudoku(grid)) {
        printf("\nSolved Sudoku:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}
