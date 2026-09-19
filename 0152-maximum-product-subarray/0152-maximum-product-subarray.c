int __max(int a, int b) { return a > b ? a : b; }
int max(int a, int b, int c) {
    return __max(__max(a, b), c);
}

int __min(int a, int b) { return a < b ? a : b; }
int min(int a, int b, int c) {
    return __min(__min(a, b), c);
}

int maxProduct(int* nums, int numsSize) {
    int max_dp[numsSize];
    int min_dp[numsSize];
    int max_ans = nums[0];

    max_dp[0] = min_dp[0] = nums[0];
    for (int i=1; i<numsSize; i++) {
        max_dp[i] = max(nums[i], max_dp[i-1] * nums[i], min_dp[i-1] * nums[i]);
        min_dp[i] = min(nums[i], max_dp[i-1] * nums[i], min_dp[i-1] * nums[i]);
        max_ans = max(max_ans, max_dp[i], INT_MIN);
    }
    return max_ans;
}