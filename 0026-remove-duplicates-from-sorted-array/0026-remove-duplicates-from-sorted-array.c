int removeDuplicates(int* nums, int numsSize) {
    int idx = 0;
    int prev = INT_MIN;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] != prev) {
            nums[idx] = nums[i];
            idx ++;
            prev = nums[i];
        } 
    }
    return idx;
}