int majorityElement(int* nums, int numsSize) {
    int major = nums[0], count = 1;
    for (int i=1; i<numsSize; i++) {
        if (count == 0) {
            major = nums[i];
            count = 1;
        } 
        else if (major == nums[i]) count ++;
        else count --;
    }
    return major;
}