int largestInteger(int* nums, int numsSize, int k) {
    int hash[51];
    memset(hash, 0, sizeof(hash));
    int max = -1, max_dup = -1;
    for (int i=0; i<numsSize; i++) 
        hash[nums[i]] ++;
    for (int i=0; i<=50; i++) {
        if (hash[i] == 1 && i > max) 
            max = i; 
        if (hash[i] > 0 && i > max_dup)
            max_dup = i;
    }
    
    if (numsSize == k) return max_dup;
    if (k == 1) return max;
    if (hash[nums[0]] == 1 && hash[nums[numsSize - 1]] == 1) 
        return (nums[0] > nums[numsSize - 1]) ? nums[0] : nums[numsSize - 1];
    if (hash[nums[0]] == 1) return nums[0];
    if (hash[nums[numsSize - 1]] == 1) return nums[numsSize - 1];
    return -1;
}