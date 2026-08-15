int longestSubsequence(int* nums, int numsSize) {
    int xor = 0;
    int nonzero = 0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i]) nonzero = 1;
        xor ^= nums[i];
    }
    if (xor) return numsSize;
    if (nonzero) return numsSize - 1;
    return 0;
}