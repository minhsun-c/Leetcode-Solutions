

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int *arr = (int *)malloc(sizeof(int)*n*2);
    for (int i=0; i<n; i++) arr[2*i] = nums[i];
    for (int i=0; i<n; i++) arr[2*i+1] = nums[n+i];
    *returnSize = numsSize;
    return arr;
}