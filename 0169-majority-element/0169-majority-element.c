int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int half = (numsSize - 1) / 2;
    for (int i=0; i<=half; i++) {
        if (i + half >= numsSize) return -1;
        else if (nums[i] == nums[i+half]) return nums[i];
    }
    return -1;
}