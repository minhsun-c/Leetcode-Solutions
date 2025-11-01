int cmp(const void *a, const void *b) { 
    long long _a = *(int *) a;
    long long _b = *(int *) b;
    if (_b > _a) return 1;
    else return 0;
}
int thirdMax(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int cnt = 2;
    int prev = INT_MIN;
    for (int i=0; i<numsSize; i++) {
        if (cnt == 0) {
            if (prev != nums[i])
                return nums[i];
            else 
                continue;
        }
        if (prev != nums[i]) {
            cnt --;
            prev = nums[i];
        }
    }
    return nums[0];
}