double findMaxAverage(int* nums, int numsSize, int k) {
    int start = 0;
    int max = 0;
    int sum = 0;
    for (int i=0; i<k; i++) { 
        max += nums[i]; 
        sum += nums[i]; 
    }
    for (int i=k; i<numsSize; i++) {
        sum -= nums[start++];
        sum += nums[i];
        if (sum > max) max = sum;
    }
    return (double) max / k;
}