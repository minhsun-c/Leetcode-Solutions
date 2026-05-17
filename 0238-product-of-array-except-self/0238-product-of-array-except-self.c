/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *arr = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    
    arr[0] = 1;
    for (int i=1; i<numsSize; i++)
        arr[i] = arr[i-1] * nums[i-1];

    int right = 1;
    for (int i=numsSize-1; i>=0; i--) {
        arr[i] *= right;
        right *= nums[i];
    }

    return arr;
}
