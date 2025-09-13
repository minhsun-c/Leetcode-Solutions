#define MIN(a, b) (a < b ? a : b)

int minCostClimbingStairs(int* cost, int costSize) {
    int dp[1005];
    dp[0] = 0; dp[1] = cost[0];
    for (int i=1; i<costSize; i++) {
        dp[i+1] = MIN(dp[i], dp[i-1]) + cost[i];
    }
    return MIN(dp[costSize], dp[costSize - 1]);
}