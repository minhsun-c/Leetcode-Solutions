int removeElement(int* nums, int numsSize, int val) {
    int last = 0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] != val) {
            nums[last++] = nums[i];
        } 
    }
    return last;
}