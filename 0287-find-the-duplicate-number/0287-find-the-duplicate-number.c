int findDuplicate(int* nums, int numsSize) {
    int tmp[numsSize];
    memset(tmp, 0, sizeof(tmp));
    for (int i=0; i<numsSize; i++) {
        tmp[nums[i] - 1] ++;
        if (tmp[nums[i]-1] > 1) return nums[i];
    }
    return 0;
}