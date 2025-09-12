#define MAX(a, b) ((a) > (b) ? (a) : (b))

int rec(int *nums, int left, int right) {
    if (left == right) return nums[left];
    if (left > right) return 0;
    int mid = (left + right) / 2;
    int l = rec(nums, left, mid);
    int r = rec(nums, mid + 1, right);

    int m = INT_MIN, temp = 0;
    for (int i=mid; i >= left; i--) {
        temp += nums[i];
        if (temp > m) m = temp;
    }
    temp = m;
    for (int i=mid+1; i <= right; i++) {
        temp += nums[i];
        if (temp > m) m = temp;
    }
    return MAX(MAX(l, r), m);
}

int maxSubArray(int* nums, int numsSize) {
    
    return rec(nums, 0, numsSize - 1);
}