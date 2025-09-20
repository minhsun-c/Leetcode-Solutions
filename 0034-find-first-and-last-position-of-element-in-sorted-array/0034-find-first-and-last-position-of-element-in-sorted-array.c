/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int bs(int *nums, int size, int target) {
    if (size == 0) return -1;
    int l = 0, r = size - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) l = mid + 1;
        else r = mid - 1; 
    }
    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *arr = (int *)malloc(sizeof(int) * 2);
    int find = bs(nums, numsSize, target);
    arr[0] = arr[1] = find;
    printf("%d\n", find);
    if (find == -1) return arr;
    
    for (; arr[0]>=0 && nums[arr[0]] == target; arr[0]--);
    for (; arr[1]<numsSize && nums[arr[1]] == target; arr[1]++);
    arr[0] ++;
    arr[1] --;
    return arr;
}