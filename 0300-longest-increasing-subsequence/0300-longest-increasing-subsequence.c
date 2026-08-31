int lengthOfLIS(int* nums, int numsSize) {
    int dp[numsSize + 1];
    dp[0] = 1;
    int all_max = 1;

    for (int i=1; i<numsSize; i++) {
        dp[i] = 1;
        for (int j=0; j<i; j++) {
            if (dp[j] + 1 > dp[i] && nums[j] < nums[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        all_max = all_max > dp[i] ? all_max : dp[i];
    }
    return all_max;
}