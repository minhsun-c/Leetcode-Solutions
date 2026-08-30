int __getmax(int a, int b) {
    return a > b ? a : b;
}

int __getmin(int a, int b) {
    return a < b ? a : b;
}

int minimumDeletions(int* nums, int numsSize) {
    int maxv = INT_MIN, maxi = -1;
    int minv = INT_MAX, mini = -1;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] >= maxv) {maxi = i; maxv = nums[i];}
        if (nums[i] <= minv) {mini = i; minv = nums[i];}
    }
    int maxleft = maxi + 1;
    int maxright = numsSize - maxi;
    int minleft = mini + 1;
    int minright = numsSize - mini;

    int ans = numsSize;
    if (maxv == minv) return __getmin(maxleft, maxright);
    if (__getmax(maxleft, minleft) < ans) ans = __getmax(maxleft, minleft);
    if (__getmax(maxright, minright) < ans) ans = __getmax(maxright, minright);
    if (maxleft + minright < ans) ans = maxleft + minright;
    if (maxright + minleft < ans) ans = minleft + maxright;
    return ans;
}