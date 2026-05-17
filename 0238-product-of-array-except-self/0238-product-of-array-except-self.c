/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getproduct(int *nums, int numsSize, int *zero) {
    int pd=1; 
    *zero = 0;
    for (int i=0; i<numsSize; i++) 
        if (nums[i]) pd *= nums[i];
        else *zero += 1;

    return pd;
}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *arr = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int iszero;
    int pd = getproduct(nums, numsSize, &iszero);
    for (int i=0; i<numsSize; i++) {
        if (nums[i]) arr[i] = (iszero) ? 0 : pd / nums[i];
        else if (iszero > 1) arr[i] = 0;
        else arr[i] = pd;
    }
    return arr;
}