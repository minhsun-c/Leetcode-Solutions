#define MAX(a, b) (a > b ? a : b)

int rob(int* nums, int numsSize) {
    int dp[105];    // dp[i]: maximum profit of index 0 ~ n
                    // either the same as previous, or dp[i-2] + nums[i]
    dp[0] = nums[0]; 
    if (numsSize > 1) dp[1] = MAX(nums[0], nums[1]);
    for (int i=2; i<numsSize; i++) {
        dp[i] = MAX(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[numsSize-1];
}