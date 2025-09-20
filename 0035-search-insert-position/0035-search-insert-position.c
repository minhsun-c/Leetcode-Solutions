int searchInsert(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1, mid;
    while (l < r) {
        if (target <= nums[l]) return l;
        if (target > nums[r]) return r+1;
        mid = (l + r) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    if (nums[mid] < target) mid++;
    return mid;
}