#include <stdio.h>
#include <string.h>

#define MAX 1000  // Maximum length of input string

// Function to find the longest palindromic subsequence
int longestPalindromicSubsequence(char *s) {
    int n = strlen(s);
    int dp[n][n];

    // Initialize all substrings of length 1 as palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Build the table for substrings of length 2 and more
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2) {
                    dp[i][j] = 2;
                } else {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            } else {
                dp[i][j] = (dp[i + 1][j] > dp[i][j - 1]) ? dp[i + 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[0][n - 1];  // Result in dp[0][n-1]
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);  // Read input string

    int length = longestPalindromicSubsequence(str);
    printf("Length of the longest palindromic subsequence: %d\n", length);

    return 0;
}
