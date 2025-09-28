/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for (int i=0, cnt=0; i<numsSize; i++) {
        cnt += nums[i];
        arr[i] = cnt;
    }
    return arr;
}