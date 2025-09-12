int pivotIndex(int* nums, int numsSize) {
    int left = 0;
    int right = 0;
    for (int i=1; i<numsSize; i++) right += nums[i];
    for (int i=0; i<numsSize; i++) {
        if (left == right) return i;
        
        if (i != numsSize - 1) {
            left += nums[i];
            right -= nums[i+1];
        } else {
            return -1;
        }
        
    }
    return -1;
}