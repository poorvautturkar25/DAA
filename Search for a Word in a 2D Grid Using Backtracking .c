#include <stdio.h>
#include <string.h>

#define MAX 100 // Maximum grid size

// Directions for moving in the grid (Up, Down, Left, Right)
int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};

// Function to check if a word exists in the grid
int searchWord(char grid[MAX][MAX], int rows, int cols, char *word, int x, int y, int index, int visited[MAX][MAX]) {
    // Base Case: If we reached the end of the word
    if (index == strlen(word)) return 1;

    // Check boundary conditions and if the character matches
    if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != word[index] || visited[x][y])
        return 0;

    // Mark the cell as visited
    visited[x][y] = 1;

    // Recursively search in all 4 directions
    for (int i = 0; i < 4; i++) {
        if (searchWord(grid, rows, cols, word, x + rowDir[i], y + colDir[i], index + 1, visited))
            return 1; // Word found, return success
    }

    // Backtrack: Unmark the cell
    visited[x][y] = 0;
    return 0; // Word not found from this path
}

// Function to find the word in the grid
int findWord(char grid[MAX][MAX], int rows, int cols, char *word) {
    int visited[MAX][MAX] = {0}; // Initialize the visited array

    // Start searching from each cell
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == word[0]) { // Start search from matching first letter
                if (searchWord(grid, rows, cols, word, i, j, 0, visited))
                    return 1; // Word found
            }
        }
    }
    return 0; // Word not found
}

int main() {
    int rows, cols;
    char grid[MAX][MAX], word[MAX];

    // Take grid input from user
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter grid characters row by row:\n");
    for (int i = 0; i < rows; i++) {
        scanf("%s", grid[i]); // Reading row-wise input
    }

    // Take word input from user
    printf("Enter the word to search: ");
    scanf("%s", word);

    // Call function to find the word
    if (findWord(grid, rows, cols, word)) {
        printf("Word '%s' found in the grid.\n", word);
    } else {
        printf("Word '%s' not found in the grid.\n", word);
    }

    return 0;
}
