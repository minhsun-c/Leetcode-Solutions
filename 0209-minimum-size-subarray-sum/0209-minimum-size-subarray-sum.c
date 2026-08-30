int minSubArrayLen(int target, int* nums, int numsSize) {
    int min = INT_MAX;
    int cnt = 0;
    int sum = 0;
    int head = 0;
    for (int i=0; i<numsSize; i++) {
        sum += nums[i];
        cnt ++;
        while (sum >= target) {
            min = cnt < min ? cnt : min; 
            sum -= nums[head];
            head ++;
            cnt --;
        }
    }
    if (min == INT_MAX) 
        return 0;
    return min;
}