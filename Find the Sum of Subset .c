#include <stdio.h>

// Function to check if subset with given sum exists
int subsetSum(int arr[], int n, int target) {
    int dp[n + 1][target + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            if (j == 0) {
                dp[i][j] = 1; // Sum 0 can always be achieved by taking no elements
            } else if (i == 0) {
                dp[i][j] = 0; // If no elements, no positive sum can be achieved
            } else if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][target]; // Result is stored in last cell
}

int main() {
    int n, target;

    // Take input from user
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    // Check if subset with given sum exists
    if (subsetSum(arr, n, target)) {
        printf("Subset with sum %d exists.\n", target);
    } else {
        printf("No subset with sum %d found.\n", target);
    }

    return 0;
}
