#include <stdio.h>

void minCoinsGreedy(int denominations[], int n, int amount) {
    int i, count = 0;
    printf("Coins used to make %d: ", amount);

    for (i = n - 1; i >= 0; i--) {  // Start with the largest denomination
        while (amount >= denominations[i]) {
            amount -= denominations[i];
            printf("%d ", denominations[i]);
            count++;
        }
    }

    if (amount != 0) {
        printf("\nThe greedy approach may not provide the optimal solution for this set of coins.");
    }

    printf("\nTotal coins used: %d\n", count);
}

int main() {
    int n, amount,i;

    // Get number of denominations
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int denominations[n];

    // Get the coin denominations
    printf("Enter the coin denominations: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &denominations[i]);
    }

    // Get the amount to make change for
    printf("Enter the amount: ");
    scanf("%d", &amount);

    // Call the function
    minCoinsGreedy(denominations, n, amount);

    return 0;
}
