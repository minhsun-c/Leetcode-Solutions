#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestSubarray(int* nums, int numsSize) {
    int front = 0, end = 0, mid = -1;
    int max = 0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] == 0) {
            if (mid == -1) {
                mid = i;
            } else {
                max = MAX(max, end - front - 1);
                front = mid + 1;
                mid = i;
            }
        } 
        end ++;
    }
    max = MAX(max, end - front - 1);
    return max;
}