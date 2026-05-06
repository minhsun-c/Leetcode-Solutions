static inline int min(int a, int b) {
    return a < b ? a : b;
}

int jump(int* nums, int numsSize) {
    int dp[numsSize];
    for (int i=0; i<numsSize; i++) 
        dp[i] = INT_MAX;
    dp[0] = 0;

    for (int i=1; i<numsSize; i++) {
        for (int j=0; j<i; j++) {
            if (nums[j] + j >= i && dp[j] < dp[i] - 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return dp[numsSize-1];
}