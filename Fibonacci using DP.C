#include <stdio.h>
#include <string.h>  // For memset()

int dp[100];  // DP Table

int fibonacci(int n) {
    if (n <= 1) return n;  // Base case
    if (dp[n] != -1) return dp[n]; // Check if already computed
    return dp[n] = fibonacci(n - 1) + fibonacci(n - 2); // Store result
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Initialize the dp array with -1 (indicating uncomputed values)
    memset(dp, -1, sizeof(dp));

    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    return 0;
}
