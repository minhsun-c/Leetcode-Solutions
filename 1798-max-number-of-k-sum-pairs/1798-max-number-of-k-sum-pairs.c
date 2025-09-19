int cmp(const void *a, const void *b) {
    int _a = *((int *)a);
    int _b = *((int *)b);
    return _a > _b;
}

int maxOperations(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);
    int cnt = 0;
    int l = 0, r = numsSize - 1;
    int sum;
    while (l < r) {
        sum = nums[l] + nums[r];
        if (sum == k) {
            cnt ++;
            l ++; r --;
        }
        else if (sum > k) {
            r --;
        }
        else {
            l ++;
        }
    }
    return cnt;
}