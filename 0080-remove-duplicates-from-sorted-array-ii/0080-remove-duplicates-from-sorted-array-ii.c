int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) return numsSize;

    int cnt = 2;

    for (int i=2; i<numsSize; i++) {
        if (nums[i] != nums[cnt-2]) {
            nums[cnt] = nums[i];
            cnt ++;
        }
    }
    return cnt;
}