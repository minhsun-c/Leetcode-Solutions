/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int)*numsSize);
    int pd = 1;
    int zeros = 0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] == 0) zeros ++;
        else pd *= nums[i];
    }
    for (int i=0; i<numsSize; i++) {
        if (nums[i] == 0) {
            if (zeros > 1) arr[i] = 0;
            else arr[i] = pd;
        } else {
            if (zeros > 0) arr[i] = 0;
            else arr[i] = pd / nums[i];
        }
    }
    *returnSize = numsSize;
    return arr;
}