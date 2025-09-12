/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *ret = (int *)malloc(sizeof(int) * (*returnSize));
    int left;
    for (int i=0; i<numsSize; i++) {
        left = target - nums[i];
        for (int j=i+1; j<numsSize; j++) {
            if (nums[j] == left) {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return NULL;
}