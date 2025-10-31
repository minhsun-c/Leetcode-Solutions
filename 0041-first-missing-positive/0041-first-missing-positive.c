int firstMissingPositive(int* nums, int numsSize) {
    int temp[numsSize+1];
    memset(temp, 0, sizeof(temp));
    for (int i=numsSize-1; i>=0; i--) {
        if (nums[i] > 0 && nums[i] <= numsSize) temp[nums[i]] = nums[i];
    }
    for (int i=1; i<=numsSize; i++) if (temp[i] != i) return i;
    return numsSize + 1;
}