#define MAX(a, b) (a > b ? a : b)

int rob(int* nums, int numsSize) {
    int dp[105];
    dp[0] = 0; dp[1] = 0; dp[2] = nums[0];
    for (int i=1; i<numsSize; i++) {
        dp[i+2] = MAX(dp[i], dp[i-1]) + nums[i];
    }
    return MAX(dp[numsSize + 1], dp[numsSize]);
}