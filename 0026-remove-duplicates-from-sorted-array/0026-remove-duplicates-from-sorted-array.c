int removeDuplicates(int* nums, int numsSize) {
    int prev = INT_MIN;
    int last = 0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] != prev) {
            nums[last++] = nums[i];
            prev = nums[i];
        } 
    }
    return last;
}