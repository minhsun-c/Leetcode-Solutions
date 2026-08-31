#define MY_MAX (amount + 1)

int min(int a, int b) {
    return a < b ? a : b;
}

int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int i=1; i<=amount; i++) {
        dp[i] = MY_MAX;
        for (int j=0; j<coinsSize; j++) {
            int c = coins[j];
            if (i >= c && dp[i - c] + 1 < dp[i]) 
                dp[i] = dp[i - c] + 1;
        }
    }
    return dp[amount] == MY_MAX ? -1 : dp[amount];
}

/*
dp[i] = 
    dp[i - c] + 1   , if dp[i - c] + 1 < dp[i]
    -1
*/