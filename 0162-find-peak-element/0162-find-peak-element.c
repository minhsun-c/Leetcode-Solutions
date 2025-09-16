int findPeakElement(int* nums, int numsSize) {
    if (numsSize == 1) return 0;
    if (nums[0] > nums[1]) return 0;
    if (nums[numsSize - 2] < nums[numsSize - 1]) return numsSize - 1;
    int right = numsSize - 2;
    int left = 1;
    int mid;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;
        if (nums[mid] < nums[mid+1]) left = mid+1;
        else if (nums[mid-1] > nums[mid]) right = mid-1;
    }
    return 0;
}