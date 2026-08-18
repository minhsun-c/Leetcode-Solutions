int cmp(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int dist = INT_MAX, closet;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i=0; i<numsSize-2; i++) {
        int head = i+1, tail = numsSize-1;
        while (head < tail) {
            int sum = nums[i] + nums[head] + nums[tail];
            if (sum > target) {
                tail --;
            } else if (sum < target) {
                head ++;
            } else {
                return sum;
            }
            int diff = abs(sum - target);
            if (diff < dist) {
                dist = diff;
                closet = sum;
            }
        }
    }
    return closet;
}