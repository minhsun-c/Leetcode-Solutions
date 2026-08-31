int lengthOfLIS(int* nums, int numsSize) {
    int dp[numsSize + 1];
    dp[0] = 1;
    int all_max = 1;

    for (int i=1; i<numsSize; i++) {
        int max_v = INT_MIN;
        int max_i = -1;
        for (int j=0; j<i; j++) {
            if (dp[j] > max_v && nums[j] < nums[i]) {
                max_v = dp[j];
                max_i = j;
            }
        }
        if (max_i != -1) {
            dp[i] = max_v + 1;
            all_max = all_max > dp[i] ? all_max : dp[i];
        }
        else 
            dp[i] = 1;
    }
    return all_max;
}