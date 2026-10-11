int sumOfSquares(int* nums, int numsSize) {
    int ans = 0;
    for (int i=0; i<numsSize; i++) {
        if (numsSize % (i + 1) == 0) {
            ans += nums[i] * nums[i];
        }
    }
    return ans;
}