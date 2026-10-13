int abs(int a) {
    return a > 0 ? a : -a;
}

int cmp(const void *a, const void *b) {
    int _a = abs(*(int *)a);
    int _b = abs(*(int *)b);
    return _b - _a;
}

long long maxAlternatingSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    long long ans = 0;
    int half = (numsSize + 1) / 2;
    for (int i=0; i<half; i++) 
        ans += (long long) nums[i] * nums[i];
    for (int i= half; i<numsSize; i++)
        ans -= (long long) nums[i] * nums[i];
    return ans;
}