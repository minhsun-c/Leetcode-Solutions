int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) return numsSize;

    int pprev = nums[0], prev = nums[1];
    int cnt = 2;

    for (int i=2; i<numsSize; i++) {
        if (nums[i] != pprev || nums[i] != prev) {
            pprev = prev;
            prev = nums[i];
            nums[cnt] = nums[i];
            cnt ++;
        }
    }
    return cnt;
}