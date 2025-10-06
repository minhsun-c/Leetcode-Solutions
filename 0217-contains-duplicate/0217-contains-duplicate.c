int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int prev = nums[0];
    for (int i=1; i<numsSize; i++)
        if (prev == nums[i]) return true;
        else prev = nums[i];
    return  false;
}