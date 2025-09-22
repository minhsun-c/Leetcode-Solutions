int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maxFrequencyElements(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int max_cnt = 0;
    int max_n = 0;
    int cur_cnt = 0;
    int prev = 0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] != prev) {
            prev = nums[i];
            cur_cnt = 1;
        } else {
            cur_cnt ++;
        }
        if (cur_cnt > max_cnt) {
            max_cnt = cur_cnt;
            max_n = 1;
        } else if (cur_cnt == max_cnt) {
            max_n ++;
        }
    }
    return max_cnt * max_n;
}